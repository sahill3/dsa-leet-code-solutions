#include<iostream>
using namespace std;
int main(){
    
    //CHARACTER ARRAYS
    int arr[5] = {1, 2, 3, 4, 5};
    char ch[6] = "abcde";

    cout << arr << endl;
    cout << ch << endl; //Prints the entire content...

    char *c = &ch[0];

    cout << c << endl;

    return 0;
}