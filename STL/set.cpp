//stores only unique elements
#include<iostream>
#include<set>

/*
Implemented using BST behind the scenes
Cannot be modified, delete or add operations only  
insert, find, erase, count operations complexity is O(log n) 
size, begin, end, empty complexity = O(1)
*/

using namespace std;
int main(){
    
    set<int> s;

    s.insert(5);
    s.insert(6);
    s.insert(1);
    s.insert(0);
    s.insert(5);
    s.insert(5);

    for(int i: s)
        cout << i << " ";

    cout << endl; 

    set<int>::iterator it = s.begin();
    it++;

    s.erase(it);

    for(int i: s)
        cout << i << " ";

    cout << endl;

    set<int>::iterator itr = s.find(5);

    cout << "Iterator: " << * itr << endl;

    cout << s.size() << endl;
    
    
    return 0;
}