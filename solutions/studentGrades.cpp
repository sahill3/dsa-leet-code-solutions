#include<iostream>
using namespace std;

// Example of a jagged array. This can have different number of columns in each row.

int main(){
    
    int n, m;
    cout << "Enter the number of students: ";
    cin >> n;
    
    int** studentGradesArr = new int*[n];
    
    for(int i = 0; i < n; i++){
        cout << "Enter the number of subjects for student " << i+1 << ": ";
        cin >> m;
        studentGradesArr[i] = new int[m];

        for(int j = 0; j < m; j++){
            cout << "Enter the grade for student " << i+1 << " for subject " << j+1 << ": ";
            cin >> studentGradesArr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        cout << "Student " << i+1 << " - ";
        for(int j = 0; j < m; j++){
            cout << studentGradesArr[i][j] << " ";
        }
        cout << endl;
    }

    //Release memory
    for(int i = 0; i < n; i++){
        delete[] studentGradesArr[i];
    }

    delete[] studentGradesArr;


    return 0;
}