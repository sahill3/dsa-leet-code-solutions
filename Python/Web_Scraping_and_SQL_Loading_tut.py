from bs4 import BeautifulSoup
import requests
import pandas as pd
import numpy as np
import sqlite3
from datetime import datetime 

def extract(url, table_attribs):
    ''' The purpose of this function is to extract the required
    information from the website and save it to a dataframe. The
    function returns the dataframe for further processing. '''

    page = requests.get(url).text
    data = BeautifulSoup(page,'html.parser')
    df = pd.DataFrame(columns=table_attribs)
    tables = data.find_all('tbody')
    rows = tables[2].find_all('tr')
    for row in rows:
        col = row.find_all('td')
        if len(col)!=0:
            if col[0].find('a') is not None and '—' not in col[2]:
                data_dict = {"Country": col[0].a.contents[0],
                             "GDP_USD_millions": col[2].contents[0]}
                df1 = pd.DataFrame(data_dict, index=[0])
                df = pd.concat([df,df1], ignore_index=True)
    return df

def transform(df):
    ''' This function converts the GDP information from Currency
    format to float value, transforms the information of GDP from
    USD (Millions) to USD (Billions) rounding to 2 decimal places.
    The function returns the transformed dataframe.'''

    GDP_list = df["GDP_USD_millions"].tolist()
    GDP_list = [float("".join(x.split(','))) for x in GDP_list]
    GDP_list = [np.round(x/1000,2) for x in GDP_list]
    df["GDP_USD_millions"] = GDP_list
    df=df.rename(columns = {"GDP_USD_millions":"GDP_USD_billions"})
    return df

def load_to_csv(df, csv_path):
    ''' This function saves the final dataframe as a `CSV` file 
    in the provided path. Function returns nothing.'''

    df.to_csv(csv_path)

def load_to_db(df, sql_connection, table_name):
    ''' This function saves the final dataframe to as a database table
    with the provided name. Function returns nothing.'''

    df.to_sql(table_name, sql_connection, if_exists='replace', index=False)

def run_query(query_statement, sql_connection):
    ''' This function runs the stated query on the database table and
    prints the output on the terminal. Function returns nothing. '''

    print(query_statement)
    query_output = pd.read_sql(query_statement, sql_connection)
    print(query_output)

def log_progress(message):
    ''' This function logs the mentioned message at a given stage of the 
    code execution to a log file. Function returns nothing.'''

    timestamp_format = '%Y-%h-%d-%H:%M:%S' # Year-Monthname-Day-Hour-Minute-Second 
    now = datetime.now() # get current timestamp 
    timestamp = now.strftime(timestamp_format) 
    with open("./etl_project_log.txt","a") as f: 
        f.write(f"{now.strftime(timestamp_format) } :  {message} \n")    

''' Here, you define the required entities and call the relevant 
functions in the correct order to complete the project. Note that this
portion is not inside any function.'''

url = 'https://web.archive.org/web/20230902185326/https://en.wikipedia.org/wiki/List_of_countries_by_GDP_%28nominal%29'
table_attribs = ["Country", "GDP_USD_millions"]
db_name = 'World_Economies.db'
table_name = 'Countries_by_GDP'
csv_path = './Countries_by_GDP.csv'

log_progress('Preliminaries complete. Initiating ETL process')
df = extract(url, table_attribs)

log_progress('Data extraction complete. Initiating Transformation process')

df = transform(df)

log_progress('Data transformation complete. Initiating loading process')

load_to_csv(df, csv_path)

log_progress('Data saved to CSV file')

sql_connection = sqlite3.connect('World_Economies.db')

log_progress('SQL Connection initiated.')

load_to_db(df, sql_connection, table_name)

log_progress('Data loaded to Database as table. Running the query')

query_statement = f"SELECT * from {table_name} WHERE GDP_USD_billions >= 100"
run_query(query_statement, sql_connection)

log_progress('Process Complete.')

sql_connection.close()

"""
import sqlite3
import pandas as pd 
import numpy as np 
import requests
from bs4 import BeautifulSoup
from datetime import datetime


def log_progress(message):
    timestamp_format = '%Y-%h-%d-%H:%M:%S'
    now = datetime.now()
    timestamp = now.strftime(timestamp_format)
    with open("./code_log.txt","a") as f: 
        f.write(timestamp + ' : ' + message + '\n') 


def extract(url):
    cols = ["Rank", "Name", "Cap"]
    df = pd.DataFrame(columns = cols)

    data = requests.get(url).text
    soup = BeautifulSoup(data, 'html.parser')

    table = soup.find_all('tbody')[0].find_all('tr')

    for row in table:
        col = row.find_all('td')
        if col:
            rank = col[0].get_text(strip=True)
            name = col[1].find_all('a')[-1].get('title')
            cap = float(col[2].get_text(strip=True))
            
            df1 = pd.DataFrame({'Rank': rank, 'Name': name, 'Cap': cap}, index = [0])
            df = pd.concat([df, df1], ignore_index=True)

    return df

def transform(df):
    cap = pd.read_csv('exchange_rate.csv')
    
    eur = cap.loc[cap['Currency'] == 'EUR', 'Rate'].values[0]
    gbp = cap.loc[cap['Currency'] == 'GBP', 'Rate'].values[0]
    inr = cap.loc[cap['Currency'] == 'INR', 'Rate'].values[0]
    
    df['EUR'] = (df['Cap'] * eur).round(2)
    df['GBP'] = (df['Cap'] * gbp).round(2)
    df['INR'] = (df['Cap'] * inr).round(2)

    return df

def load_to_csv(df, csv_path):
    df.to_csv(csv_path)


def load_to_db(df, sql_connection, table_name):

    df.to_sql(table_name, sql_connection, 
              if_exists='replace', index=False)



url = "https://web.archive.org/web/20230908091635 /https://en.wikipedia.org/wiki/List_of_largest_banks"
log_progress('Preliminaries Complete, Starting Extraction')
df = extract(url)

log_progress('Extraction Complete, Starting transformation')
transform(df)

log_progress('transformation Complete, Starting to load CSV')
path = "./Largest_banks_data.csv"
load_to_csv(df, path)

log_progress('Loading to CSV Complete, Starting to load Database')
table_name = "Largest_banks"
sql_connection = sqlite3.connect('Banks.db')
load_to_db(df, sql_connection, table_name)
log_progress('Loading to Database Complete')

log_progress('Process Complete.')

sql_connection.close()
"""

