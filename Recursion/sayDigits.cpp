#include<iostream>
#include<map>
#include<string>

using namespace std;

void say(int n){
    int t = 0;
    map<int, string> m;

    m.insert({0, "zero"});
    m.insert({1, "one"});
    m.insert({2, "two"});
    m.insert({3, "three"});
    m.insert({4, "four"});
    m.insert({5, "five"});
    m.insert({6, "six"});
    m.insert({7, "seven"});
    m.insert({8, "eight"});
    m.insert({9, "nine"});

    if(n == 0)
        return;
    else{
        int t = n%10;
        say(n/10);
        cout << m[t] << " "; 
    }
}

int main(){

    int num;
    cout << "Enter a numeber: ";
    cin >> num;

    say(num);

    return 0;
}