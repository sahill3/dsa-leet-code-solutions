#include<iostream>
using namespace std;

// void insertionSort(int *arr, int size){
//     int i = 0;
//     while(i < size){
//         int temp = arr[i];
//         int j = i - 1;
//         while(j >= 0){
//             if(arr[j] > temp){
//                 arr[j+1] = arr[j];
//                 j--;
//             }
//             else{
//                 break;
//             }
//         }
//         arr[j+1] = temp;
//         i++;
//     }
// }

void insertionSort(int *arr, int size, int i){
    if(i == size)
        return;

    int temp = arr[i];
    int j = i - 1;
    while(j >= 0){
        if(arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        else{
            break;
        }
    }
    arr[j+1] = temp;
    
    insertionSort(arr, size, i+1);

}

int main(){
    
    int arr[5] = {90, 40, 50, 20, 30};

    insertionSort(arr, 5, 0);

    for(int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    return 0;
}