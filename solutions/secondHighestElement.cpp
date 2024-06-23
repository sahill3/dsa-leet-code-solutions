#include<iostream>
using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        int maxi = -1;
        int sMax = -1;
        for (int i = 0; i < s.length(); i++){
            char temp = s[i];
            if (isdigit(temp)) {
                int tmp = int(temp) - '0';
                if (tmp > maxi){
                    sMax = maxi;
                    maxi = tmp;
                }
                else if(tmp < maxi && tmp > sMax)
                    sMax = tmp;
            }   
        }

        return sMax;
    }
};

int main(){
    
    string s;
    cout << "Enter a string: ";
    cin >> s;
    
    Solution obj = Solution();
    cout << obj.secondHighest(s);

    return 0;
};