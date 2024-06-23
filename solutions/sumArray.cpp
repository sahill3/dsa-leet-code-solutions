#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    
    vector<int> num1 {2, 3, 9};
    vector<int> num2 {1, 5};
    vector<int> ans;

    int n3, n1 = 0, n2 = 0;

    for(int i : num1){
        n1 = (n1*10) + i;
    }

    for(int i : num2){
        n2 = (n2*10) + i;
    }

    cout << "Number 1: " << n1 << endl;
    cout << "Number 2: " << n2 << endl;
    cout << endl;

    n3 = n1 + n2;

    while(n3){
        int temp = n3 % 10;
        ans.push_back(temp);
        n3 = n3 / 10;
    }

    reverse(ans.begin(), ans.end());

    for (int i : ans){
        cout << i << " ";
    }

    return 0;
}