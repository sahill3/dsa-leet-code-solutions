#include<iostream>
using namespace std;

int arrSum(int *arr, int n){
    if (n == 0)
        return 0;
    else{
        return arr[0] + arrSum(arr+1, n-1);
    }
}

int main(){
    
    int *arr = new int[5];
    int sum = 0;

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    sum = arrSum(arr, 5);

    cout << "The sum of the arr is " << sum;

    return 0;
} 