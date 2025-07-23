#include<iostream>
using namespace std;

void printt(int ans[], int size){

    for (int i = 0; i < size; i++)
        cout << ans[i];
    cout << endl;
}

void rec(int index, int n, int arr[], int ans[], int size){
    if (index >= n) {
        printt(ans, size);
        return;
    }

    ans[size] = arr[index];
    rec(index+1, n, arr, ans, size+1);
    rec(index+1, n, arr, ans, size);
}

int main(){
    
    int arr[3] = {3, 2, 1};
    int ans[3];
    
    rec(0, 3, arr, ans, 0);

    return 0;
}

// Time complexity = O(2^n * n)
// Space = O(n)