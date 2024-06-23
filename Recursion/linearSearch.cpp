#include<iostream>
using namespace std;

bool search(int *arr, int size, int element){
    if(size == 0)
        return false;
    else if(arr[0] == element)
        return true;
    else
        return search(arr+1, size-1, element);
    
}

int main(){

    int element;
    int *arr = new int[10];

    arr[0] = 793;
    arr[1] = 199;
    arr[2] = 986;
    arr[3] = 302;
    arr[4] = 66;
    arr[5] = 100;
    arr[6] = 912;
    arr[7] = 402;
    arr[8] = 176;
    arr[9] = 920;

    cout << "Enter the element to search: ";
    cin >> element;

    if(search(arr, 10, element))
        cout << "Element found" << endl;
    else
        cout << "Element not found "<< endl;

    delete arr;

    return 0;
}