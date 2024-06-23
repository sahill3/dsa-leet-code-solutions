#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if(x < 0){
        return false;
    }
    else{
    long int rev = 0;
    int unit = 0;
    int n = x;
    while(n){
        unit = n % 10;
        rev = (rev*10) + unit;
        n = n/10;
    }
        if(x == rev){
            return true;
        }
        else{
            return false;
        }
    }
}

int main() {
    isPalindrome(10);
    return 0;
}
