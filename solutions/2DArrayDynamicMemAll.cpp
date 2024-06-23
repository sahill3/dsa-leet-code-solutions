#include<iostream>
using namespace std;
int main(){
    
    int n, m;
    cout << "Enter the number of rows and columns for the arr: ";
    cin >> n >> m;; 

    int ** arr = new int*[n];

    for(int i = 0; i < n; i++){
        arr[i] = new int[m];
    } 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    } 

    cout << "Matrix: " << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //Releasing the memory
    for(int i = 0; i < n; i++){
        delete [] arr[i];
    }

    delete [] arr;

    return 0;
}