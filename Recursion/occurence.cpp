#include<iostream>
using namespace std;
int firstOccurence(int *arr, int s, int e, int element, int ans){
    int a = ans;
    
    if(s > e)
        return a;

    int mid = s + (e -s)/2;

    if(element == arr[mid])
        return firstOccurence(arr, s, mid - 1, element, mid);
    else if(element  < arr[mid])
        return firstOccurence(arr, s, mid - 1, element, a);
    else
        return firstOccurence(arr, mid + 1, e, element, a);
}

int lastOccurence(int *arr, int s, int e, int element, int ans){
    int a = ans;
    
    if(s > e)
        return a;

    int mid = s + (e -s)/2;

    if(element == arr[mid])
        return lastOccurence(arr, mid + 1, e, element, mid);
    else if(element  < arr[mid])
        return lastOccurence(arr, s, mid - 1, element, a);
    else
        return lastOccurence(arr, mid + 1, e, element, a);
}

int main(){

    int num;
    int *list = new int[10];

    list[0] = 9;
    list[1] = 19;
    list[2] = 26;
    list[3] = 32;
    list[4] = 32;
    list[5] = 32;
    list[6] = 32;
    list[7] = 72;
    list[8] = 87;
    list[9] = 92;

    cout << "Enter the number to be searched: ";
    cin >> num;

    int ans1 = firstOccurence(list, 0, 9, num, -1);
    int ans2 = lastOccurence(list, 0, 9, num, -1);

    cout << "The First occurence of " << num << " is at: " << ans1 << endl; 
    cout << "The Last occurence of " << num << " is at: " << ans2 << endl; 
    
    delete list;

    return 0;
}