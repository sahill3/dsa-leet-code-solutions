#include<bits/stdc++.h>
using namespace std;

/*
=== Two Pointer Approach ===
Only space optimized not time.
Time: O(n1 + n2)
*/

double SpaceOptimizedMedian(vector<int> arr1, vector<int> arr2){    

    int n1 = arr1.size();
    int n2 = arr2.size();
    int n = n1 + n2;

    int ind2 = n/2;
    int ind1 = ind2 - 1;

    int indEle1 = -1, indEle2 = -1;
    int i = 0, j = 0, cnt = 0;    

    while(i < n1 && j < n2){
        if (arr1[i] < arr2[j]){
            if (cnt == ind1) indEle1 = arr1[i];
            if (cnt == ind2) indEle2 = arr1[i];
            cnt++;
            i++;
        }
        else{
            if (cnt == ind1) indEle1 = arr2[j];
            if (cnt == ind2) indEle2 = arr2[j];
            cnt++;
            j++;
        }
    }

    while(i < n1){
         if (cnt == ind1) indEle1 = arr1[i];
        if (cnt == ind2) indEle2 = arr1[i];
        cnt++;
        i++;
    }

    while(j < n2){
        if (cnt == ind1) indEle1 = arr2[j];
        if (cnt == ind2) indEle2 = arr2[j];
        cnt++;
        j++;
    }

    if (n & 1) return indEle2;
    else return static_cast<double>(indEle1 + indEle2) / 2.0;
}

/*
=== Binary Search Approach ===

*/
double BinarySearchMedian(vector<int> arr1, vector<int> arr2){


    return 0;
}

int main(){

    vector<int> arr1 = {1,2};
    vector<int> arr2 = {3,4};

    cout << SpaceOptimizedMedian(arr1, arr2) << endl;

    return 0;
}