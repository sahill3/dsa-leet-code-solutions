#include<iostream>
using namespace std;
int main(){
    for(int i = 0; i < 10; i++){
        if(i==5){
            continue;
            //continue stops the current iteration and jump to the next iteration
        }

        if(i==7){
            break;
            //break stops the current iteration and exits from the loop, even the for loop in this case
        }
        cout<<i<<endl;
    }
    return 0;
}