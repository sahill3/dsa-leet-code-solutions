#include<iostream>
using namespace std;

bool isSorted(int *arr, int n){
    //base
    if(n == 0 || n == 1)
        return true;
    else if(arr[0] > arr[1])
        return false;
    else
        return isSorted(arr+1, n-1);
}

int main(){

    int *arr = new int[5];
    arr[0] = 11;
    arr[1] = 30;
    arr[2] = 10;
    arr[3] = 21;
    arr[4] = 8;

    int *arr2 = new int[5];
    arr2[0] = 8;
    arr2[1] = 10;
    arr2[2] = 11;
    arr2[3] = 21;
    arr2[4] = 30;
    
    cout << "Is arr sorted? " << (isSorted(arr, 5)?"Yes":"No") << endl;
    cout << "Is arr2 sorted? " << (isSorted(arr2, 5)?"Yes":"No") << endl;

    delete arr;
    delete arr2;

    return 0;
}