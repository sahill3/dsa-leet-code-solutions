#include<iostream>
using std::cout;
using std::endl;

class Deque{
    public:
        int *arr;
        int front;
        int rear;
        int size;

    Deque(int s){
        this -> size = s;
        front = rear = -1;
        arr = new int[size];
    }

    void pushFront(int ele){
        if ((rear + 1) % size == front){
            cout << "Queue Full!" << endl;
            return;
        }
        else if (front == -1)
            front = rear = 0;
        
        else if (front == 0)
            front = size-1;
        
        else
            front--;

        arr[front] = ele;
    }

    void pushBack(int ele){
        if ((rear + 1) % size == front){
            cout << "Queue Full!" << endl;
            return;
        }
        else if(front == -1)
            front = rear = 0;
        
        else if (rear == size-1)
            rear = 0;
    
        else 
            rear++;

        arr[rear] = ele;
    }

    int popFront(){
        if (isEmpty()){
            cout << "Queue empty." << endl;
            return -1;
        }
        int ele = arr[front];
        arr[front] = -1;

        if (front == rear)
            front = rear = -1;
        
        else if (front == size-1)
            front = 0;

        else
            front++;

        return ele;

    }
    
    int popBack(){
        if (isEmpty()){
            cout << "Queue empty." << endl;
            return -1;
        }

        int ele = arr[rear];
        arr[rear] = -1;

        if (front == rear)
            front = rear = -1;

        else if (rear == 0)
            rear = size-1;

        else 
            rear--;

        return ele;
    }

    int getFront(){
        if (isEmpty()){
            cout << "Queue empty" << endl;
            return -1;
        }
        
        return arr[front];
    }

    int getRear(){
        if (isEmpty()){
            cout << "Queue empty" << endl;
            return -1;
        }
        
        return arr[rear];
    }

    bool isEmpty(){
        return front == -1 ? true : false;
    }

};

int main(){
    
    Deque q(4);
    
    q.pushFront(10);
    q.pushBack(20);
    
    q.pushFront(5);
    q.pushFront(1); 

    cout << q.getFront() << endl;
    cout << q.getRear() << endl;

    for(int i= 0; i < q.size; i++)
        cout << q.arr[i] << " ";

    delete[] q.arr;
    return 0;
}
