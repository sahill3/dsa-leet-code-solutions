#include<iostream>
#include<queue>

//Priority queue is basically a sorted queue. We define if we want min or max heap
//that decides which way the elements are sorted.

using namespace std;
int main(){

    //max heap
    priority_queue<int> maxi;  //by default max heap

    //min heap
    priority_queue<int, vector<int>, greater<int> > mini;

    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);

    int n = maxi.size();

    for(int i = 0; i < n; i++){
        cout << "Front element: " << maxi.top() << endl;
        maxi.pop();
    }

    mini.push(1);
    mini.push(3);
    mini.push(2);
    mini.push(0);
    mini.push(3);

    for(int i = 0; i < n; i++){
        cout << "Front element: " << mini.top() << endl;
        mini.pop();
    }

    return 0;
}