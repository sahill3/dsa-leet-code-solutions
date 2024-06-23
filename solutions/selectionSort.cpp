#include<iostream>
#include<vector>
using namespace std;

int main() {

    vector<int> nums {4,5,6,1,2,3};
    int n = nums.size();

    for (int i = 0; i < n-1; i++){
        int minIndex = i;
        for (int j = i+1; j < n; j++){
            if(nums[j] < nums[minIndex]){
                minIndex = j;
            }
        } 
        int temp = nums[i];
        nums[i] = nums[minIndex];
        nums[minIndex] = temp; 

        for(int k = 0; k < n; k++){
            cout << nums[k] << " ";
        }
        cout << endl;
    }
        
        return 0;
}

