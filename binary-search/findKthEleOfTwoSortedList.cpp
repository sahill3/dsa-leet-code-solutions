// Kth Element of 2 sorted List

#include<iostream>
#include<vector>
using namespace std;

/*
=== Two Pointer ===
Time: O(k)
*/
int kthElement(vector<int> &a, vector<int> &b, int k) {
        int cnt = 0;
        int n1 = a.size(), n2 = b.size();
        int ptr1 = 0, ptr2 = 0;
        
        while(ptr1 < n1 && ptr2 < n2){
            if (a[ptr1] < b[ptr2]) {
                cnt++;
                if (cnt == k) return a[ptr1];
                ptr1++;
            }
            else {
                cnt++;
                if (cnt == k) return b[ptr2];
                ptr2++;
            }
        }
        
        while(ptr1 < n1){
            cnt++;
            if (cnt == k) return a[ptr1];
            ptr1++;
        }
        
        while(ptr2 < n2){
            cnt++;
            if (cnt == k) return b[ptr2];
            ptr2++;
        }
        return -1;
    }

/*
=== Binary Search ===
Time: O(log(min(n1, n2)))
*/

int kthElementBS(vector<int> &a, vector<int> &b, int k) {
    int n1 = a.size(), n2 = b.size();
    
    if (n1 > n2) return kthElementBS(b, a, k);
    int low = max(k - n2 , 0);
    int high = min(k, n1);
    
    while(low <= high){
        int mid1 = (low + high) >> 1;
        int mid2 = k - mid1;
        
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1) r1 = a[mid1];
        if (mid2 < n2) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];
        
        if (l1 <= r2 && l2 <= r1) return max(l1, l2);
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}


int main(){

    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;
    // cout << "Kth Element is: " << kthElement(a, b, k) << endl;
    cout << "Kth Element is: " << kthElementBS(a, b, k) << endl;
    return 0;
}