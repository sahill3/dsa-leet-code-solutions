#include<iostream>
using namespace std;

class kQueue{
    public:
        int n;
        int k;
        int* front;
        int* rear;
        int* next;
        int freeSpot;
        int*arr;

    kQueue(int n, int k){
        this -> n = n;
        this -> k = k;
        front = new int[k];
        rear = new int[k];
        next = new int[n];
        arr = new int[n];
        freeSpot = 0;

        for (int i = 0; i < k; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        for (int i = 0; i < n; i++)
            next[i] = i+1;

        next[n-1] = -1;
    }

    void enqueue(int data, int qn){
        if (freeSpot == -1){
            cout << "Queue Full!" << endl;
            return;
        }

        int index = freeSpot;
        freeSpot = next[index];

        if (front[qn-1] == -1)
            front[qn-1] = rear[qn-1] = index;
        
        else
            next[rear[qn-1]] = index;
        
        next[index] = -1;

        rear[qn-1] = index;

        arr[index] = data;
    }

    int dequeue(int qn){
        if (front[qn-1] == -1)
            return -1;

        int index = front[qn-1];

        front[qn-1] = next[index];

        next[index] = freeSpot;

        freeSpot = index;

        int temp = arr[index];
        arr[index] = -1;

        return temp;
    }
};

int main(){

    kQueue q(10, 3);

    q.enqueue(15, 3);
    q.enqueue(45, 3);

    q.enqueue(17, 2);
    q.enqueue(49, 2);
    q.enqueue(39, 2);
    
    q.enqueue(11, 1);
    q.enqueue(9, 1);
    q.enqueue(7, 1);

    cout << q.dequeue(3) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    
    cout << q.dequeue(3) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;

    return 0;
}