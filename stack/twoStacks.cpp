#include<iostream>
using namespace std;

class TwoStack{
    int *arr;
    int top1;
    int top2;
    int size;

public:

    TwoStack(int s){
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    void push1(int num){
        if (top2 - top1 <= 1) {cout << "Stack full" << endl; return;}

        arr[++top1] = num;
    }

    void push2(int num){
        if (top2 - top1 <= 1) { cout << "Stack full" << endl; return; }

        arr[--top2] = num;
    }

    int pop1(){
        if (top1 >= 0){
            int ele = arr[top1];
            top1--;
            return ele;
        }
        else{
            cout << "Stack empty" << endl;
            return -1;
        }
    }

    int pop2(){
        if (top2 > size){
            int ele = arr[top2];
            top2++;
            return ele;
        }
        else
            return -1;
    }

    void printStack(){
        for (int i = 0; i <= top1; i++)
            cout << arr[i] << " ";

        cout << endl;

        for (int i = size-1; i >= top2; i--)
            cout << arr[i] << " ";

        cout << endl;
    }

};

int main(){
    
    TwoStack stacks = TwoStack(8);
    stacks.push1(1);
    stacks.push1(2);
    stacks.push1(3);
    stacks.push1(4);
    stacks.push2(5);
    stacks.push2(6);
    stacks.push2(7);
    stacks.push2(8);

    stacks.push1(9);

    stacks.printStack();

    stacks.push2(10);

    stacks.pop1();
    stacks.pop1();
    stacks.pop1();
    stacks.pop1();
    stacks.pop1();

    stacks.printStack();

    return 0;
}
