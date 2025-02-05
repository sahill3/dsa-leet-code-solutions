import requests
from bs4 import BeautifulSoup
import sqlite3
import numpy as np 
import pandas as pd
from datetime import datetime


def extract(url, table_attribs):
    ''' This function extracts the required
    information from the website and saves it to a dataframe. The
    function returns the dataframe for further processing. '''
    data = requests.get(url).text
    soup = BeautifulSoup(data, 'html.parser')
    df = pd.DataFrame(columns = table_attribs)
    table_body = soup.find_all('tbody')
    rows = table_body[2].find_all('tr')

    for row in rows:
        col = row.find_all('td')
        if len(col) != 0:
            if col[0].find('a') is not None and '-' not in col[2]:
                data_dict = {'Country': col[0].a.contents[0],
                             'GDP_USD_millions': col[2].contents[0]}
                df2 = pd.DataFrame(data_dict, index=[0])
                df = pd.concat([df, df2], ignore_index = True)
    return df

def transform(df):
    ''' This function converts the GDP information from Currency
    format to float value, transforms the information of GDP from
    USD (Millions) to USD (Billions) rounding to 2 decimal places.
    The function returns the transformed dataframe.'''
    temp = df['GDP_USD_millions'].to_list()
    temp = [float("".join(x.split(','))) for x in temp]
    temp = [np.round(x/1000, 2) for x in temp]
    df['GDP_USD_millions'] = temp

    df = df.rename(columns = {"GDP_USD_millions":"GDP_USD_billions"})
    return df

def load_to_csv(df, csv_path):
    ''' This function saves the final dataframe as a `CSV` file 
    in the provided path. Function returns nothing.'''
    df.to_csv(csv_path)

def load_to_db(df, sql_connection, table_name):
    ''' This function saves the final dataframe as a database table
    with the provided name. Function returns nothing.'''
    df.to_sql(table_name, sql_connection, if_exists='replace', index=False)

def run_query(query_statement, sql_connection):
    ''' This function runs the stated query on the database table and
    prints the output on the terminal. Function returns nothing. '''
    print(query_statement)
    query_output = pd.read_sql(query_statement, sql_connection)
    print(query_output)

def log_progress(message):
    ''' This function logs the mentioned message at a given stage of the code execution to a log file. Function returns nothing'''
    timestamp_format = '%Y-%h-%d-%H:%M:%S'
    now = datetime.now()
    timestamp = now.strftime(timestamp_format)
    with open("./etl_project_log.txt","a") as f: 
        f.write(timestamp + ' : ' + message + '\n')


table_attribs = ["Country", "GDP_USD_millions"]
db_name = "World_Economics.db"
table_name = "Countries_by_GDP"
csv_path = "Countries_by_GDP.csv"
url = 'https://web.archive.org/web/20230902185326/https://en.wikipedia.org/wiki/List_of_countries_by_GDP_%28nominal%29'
conn = sqlite3.connect(db_name)

log_progress("Extraction Started")
df = extract(url, table_attribs)
log_progress("Extraction Ended")

log_progress("Transformation Started")
df = transform(df)
log_progress("Transformation Ended")

log_progress("Loading to CSV Started")
load_to_csv(df, csv_path)
log_progress("Loading to CSV Ended")

log_progress("Loading to DB Started")
load_to_db(df, conn, table_name)
log_progress("Loading to DB Ended")

log_progress("Quering Started")
query_statement = f"SELECT * from {table_name}"
run_query(query_statement, conn)
log_progress("Quering Ended")

conn.close()
