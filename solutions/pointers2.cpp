#include<iostream>
using namespace std;
int main(){
    
    int arr[10] = {10, 20, 30};

    cout << "1. Address of the first memory block: " << arr << endl;
    cout << "2. " << &arr << endl;
    cout << "3. " << &arr[0] << endl;
    cout << endl;

    cout << "4. " << *arr;
    cout << "   5. " << *arr + 1;
    cout << "   6. " << (*arr) + 1;
    cout << "   7. " << (*arr + 1);
    cout << "   8. " << arr[2];
    cout << "   9. " << *(arr + 2) << endl;
    cout << endl;

    int i = 2;
    cout << "Value of i[arr]: " << i[arr] << endl;

    cout << "sizeof(arr): " << sizeof(arr) << endl;
    cout << "sizeof(*arr): " << sizeof(*arr) << endl;
    cout << "sizeof(*arr): " << sizeof(&arr) << endl;
    cout << endl;

    int *ptr = &arr[0];

    cout << "ptr:  " << ptr << endl;
    cout << "*ptr: " << *ptr << endl;
    cout << "&ptr: " << &ptr << endl;

    return 0;
}