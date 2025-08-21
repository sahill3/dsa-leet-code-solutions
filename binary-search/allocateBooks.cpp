#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;

class Solution {
  public:
    int allocate(vector<int> &arr, int a, int n){
        int students = 1, pages = 0;
        
        for(int i = 0; i < n; i++){
            if(pages + arr[i] > a) {
                students++;
                pages = arr[i];
            }
            else pages += arr[i];
        }
        return students;
    }
  
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1; 
        
        int l = *max_element(arr.begin(), arr.end());
        int r = accumulate(arr.begin(), arr.end(),0);
        
        while(l <= r){
            int mid = l + (r-l)/2;
            
            int a = allocate(arr, mid, n);
            
            if (a <= k) r = mid - 1;
            
            else l = mid + 1;
        
            // cout << l <<" "<< r << endl;
        }
        
        return l;
    }
};
    
int main(){
    Solution sol;
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    cout << sol.findPages(arr, k) << endl;
    return 0;
}