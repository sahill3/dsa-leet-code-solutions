#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums1 {4,5,6,0,0,0};
    vector<int> nums2 {1,2,3};
    vector<int>::iterator it1, it2;
    int n = nums2.size();

    it1 = nums1.end();
    it2 = nums1.end();
    int a, b;
    a = 0;
    b = 0;
    
    for(int i = 0; i < n; i++){
        it1--;
    }
    nums1.erase(it1, it2);
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());

    int cnt = nums1.size();

    for (int i = 0; i < cnt-1; i++){
        int minIndex = i;
        for (int j = i+1; j < cnt; j++){
            if(nums1[j] < nums1[minIndex]){
                minIndex = j;
            }
        } 
        int temp = nums1[i];
        nums1[i] = nums1[minIndex];
        nums1[minIndex] = temp; 
    }

    for(auto i: nums1){
        cout << i << " ";
    }    
    
    return 0;
}