#include<iostream>
using namespace std;

int binarySearch(int *arr, int start, int end, int element){
    if(start > end)
        return -1;
    
    int mid = start + (end - start)/2;
    
    if(arr[mid] == element)
        return mid;
    else if(element < arr[mid])
        return binarySearch(arr, start, mid - 1, element);
    else
        return binarySearch(arr, mid + 1, end, element);
}

void search(int *arr, int element){

    int ans = binarySearch(arr, 0, 9, element);

    if(ans == -1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at "<< ans << endl;
}

int main(){
    
    int element;
    int *list = new int[10];

    list[0] = 93;
    list[1] = 199;
    list[2] = 286;
    list[3] = 302;
    list[4] = 406;
    list[5] = 500;
    list[6] = 612;
    list[7] = 702;
    list[8] = 876;
    list[9] = 920;

    cout << "Enter the element to search: ";
    cin >> element;

    search(list, element);

    for(int i = 0; i < 10; i++){
        cout << "For " << list[i] << " : ";
        search(list, list[i]);
    }    

    delete list;

    return 0;
}