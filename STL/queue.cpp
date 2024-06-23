#include<iostream>
#include<queue>

using namespace std;
int main(){

    queue<string>  q;
    
    q.push("sam");
    q.push("Paulo");
    q.push("son");

    cout << "Size: " << q.size() << endl;

    cout << "First element: " << q.front() << endl;

    q.pop();

    cout << "First element: " << q.front() << endl;
    return 0;
}