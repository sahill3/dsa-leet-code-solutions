#include<iostream>
using namespace std;

//reference variable is a variable having 2 names, i.e. pointing at the same variable.
//here x and y point to the same value 44.

void update(int& num){
    num++;
}

int main()
{
    int x = 44;
    int & y = x;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "&x = " << &x << endl;
    cout << "&y = " << &y << endl;

    update(x);
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}
