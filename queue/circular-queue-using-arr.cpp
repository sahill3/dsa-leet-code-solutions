#include<iostream>
using std::cout;
using std::endl;

class CirclarQueue{
    public:
    int size;
    int front;
    int rear;
    int *arr;

    CirclarQueue(int s){
        this -> size = s;
        this -> arr = new int[size];
        this -> front = -1;
        this -> rear = -1;
    }

    void enqueu(int data){
        if ((rear + 1) % size == front){
            cout << "Queue Full!" << endl;
            return;
        }
        else if (front == -1){
            front = rear = 0;
        }
        else if (rear == size-1 && front != 0){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = data;
    }

    int dequeu(){
        if (front == -1){
            cout << "Queue empty " << endl;
            return -1;
        }
        
        int ele = arr[front];
        arr[front] = -1;

        if (front == rear){
            front = rear = -1;
        }
        else if (front == size - 1){
            front = 0;
        }
        else{
            front++;
        }

        return ele;
    }

    void print(){
        cout << "Front : " << arr[front] << endl;
    }
};


int main(){
    
    CirclarQueue queue(2);

    queue.enqueu(10);
    queue.enqueu(20);

    queue.print();

    queue.dequeu();

    queue.enqueu(30);
    queue.print();

    queue.dequeu();

    queue.print();

    return 0;
}