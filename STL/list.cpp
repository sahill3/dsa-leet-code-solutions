#include<iostream>
#include<list>
using namespace std;

int main(){

    list<int> l;
    // list<int> n(l);
    list<int> n(5, 100);

    l.push_back(1);
    l.push_front(2);

    for(auto i:n){
        cout << i << " ";
    }    
    cout << endl;

    l.erase(l.begin());
    cout << l.size() << endl;
    return 0;
}