#include<iostream>
using std::cout;
using std::cin;

int main(){
    

    int n;
    cout << "Enter a number: ";
    cin >> n;

    for (int i = 0; i < n; i++){

        for (int j = 1; j <= n; j++){
            if (j <= n - i)
                cout << j;
            else 
                cout << "*";
        }

        for (int k = n; k >=1; k--){
            if (k <= n - i)
                cout << k;
            else    
                cout << "*";
        }

        cout << "\n";
    }

    return 0;
}