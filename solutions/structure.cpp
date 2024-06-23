#include<iostream>
using namespace std;

typedef struct employee   //used to give pet name, so that we dont have to do "struct employee <name>"
{
    int id;   //4
    char fav;   //1
    float salary; //4
} ep;   //ep can be used instead of empolyee / pet name

union payment{
    int cash;   //4
    char upi; //1
    float netbanking; //4
};

int main(){
    struct employee zoro;
    zoro.id = 1;
    zoro.fav = 'c';
    zoro.salary = 1200000;

    ep russel;
    russel.id = 63;
    russel.fav = 's';
    russel.salary = 5000000; 

    struct employee giyu;
    giyu.id = 2;
    giyu.fav = 'e';
    giyu.salary = 100000;

    cout<<giyu.fav<<endl;
    cout<<zoro.id<<endl;
    cout<<russel.salary<<endl;

    union payment lol;
    lol.netbanking = 12.55;
    lol.cash = 5;

    cout<<lol.cash<<endl;
    //cout<<lol.netbanking<<endl;   gives garbage value
    //###################################
    //enum

    enum meal{breakfast, lunch, dinner}; //values have an index starting from 1
    cout<<breakfast<<endl;
    cout<<lunch<<endl;
    cout<<dinner<<endl;
    cout<<endl;
    meal M1 = lunch;
    cout<<M1;

    return 0;
}