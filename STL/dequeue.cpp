#include<iostream>
#include<deque>

using namespace std;
int main(){

    deque<int> a;

    a.push_back(1);
    a.push_front(0);

    for(auto i:a){
        cout << i << " ";
    }

    cout << endl;

    deque<int> b(a);

    cout << "Print: " << a.front() << endl;
    cout << "Print: " << a.back() << endl;
    cout << "Print: " << a.empty() << endl;


    b.pop_back();
    a.pop_front();

    for(auto i:a){
        cout << i << " ";
    }

    cout << endl;

    for(auto i:b){
        cout << i << " ";
    }

    cout << "\nElement at 1st position: " << a.at(0);

    a.erase(a.begin(), a.end());
    cout << a.size() << endl;

    return 0;
}