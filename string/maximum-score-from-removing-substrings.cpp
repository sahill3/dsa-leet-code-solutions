#include<iostream>
#include<vector>
using namespace std;

/*
You are given a string s and two integers x and y. 
You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.

Remove substring "ba" and gain y points.

Return the maximum points you can gain after applying the above operations on s.
*/

int maximumGain(string s, int x, int y){
    int ans = 0;

    int topScore, botScore;
    string top, bot;
    
    if (x > y){
        topScore = x;
        top = "ab";
        botScore = y;
        bot = "ba";
    }
    else{
        topScore = y;
        top = "ba";
        botScore = x;
        bot = "ab";
    }

    vector<char> stack1;
    //for higher value substring
    for (char ch: s){
        if ((ch == top[1] && !stack1.empty()) && stack1.back() == top[0]){
            ans += topScore;
            stack1.pop_back();
        }
        else    
            stack1.push_back(ch);
    }

    //for lower value substring
    vector<char> stack2;

    for (char ch: stack1){
        if ((ch == bot[1] && !stack2.empty()) && stack2.back() == bot[0]){
            ans += botScore;
            stack2.pop_back();
        }
        else    
            stack2.push_back(ch);
    }
    
    return ans;
}

int main(){
    
    string s = "aabbaaxybbaabb";
    int x = 5;
    int y = 4;

    int ans = maximumGain(s, x, y);

    cout << "Answer: " << ans;

    return 0;
}