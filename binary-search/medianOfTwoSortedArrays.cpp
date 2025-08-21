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
Time: O(min(log n1, log n2))
Space: O(1)
*/
double BinarySearchMedian(vector<int> nums1, vector<int> nums2){
    int n1 = nums1.size();
    int n2 = nums2.size();

    if (n1 > n2) return BinarySearchMedian(nums2, nums1);

    int n = n1 + n2;
    int l = 0, r = n1;

    int req = (n + 1)/2;

    while(l <= r){
        int mid1 = (l + r) >> 1;
        int mid2 = req - mid1;
        
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1) r1 = nums1[mid1];
        if (mid2 < n2) r2 = nums2[mid2];
        if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

        if (l1 <= r2 && l2 <= r1){
            if (n & 1) return max(l1, l2);
            else return (max(l1, l2) + min(r1, r2)) /  2.0;
        }
        else if (l1 > r2) 
            r = mid1 - 1;
        else 
            l = mid1 + 1;
    }        
    return 0;
}

int main(){

    vector<int> arr1 = {1,2};
    vector<int> arr2 = {3,4};

    cout << BinarySearchMedian(arr1, arr2) << endl;

    return 0;
}