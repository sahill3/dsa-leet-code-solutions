#include<iostream>
using namespace std;

void solve(int arr[6], int i, int n){
    if(i >= n / 2) return;

    swap(arr[i], arr[n - i - 1]);

    solve(arr, i + 1, n);
}

int main(){
    
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Array before reversing: ";

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    solve(arr, 0, n);

    cout << "Array after reversing: ";

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}