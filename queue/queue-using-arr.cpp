#include<iostream>
using std::cout;
using std::endl;

class Queue{
    public:
        int *arr;
        int qfront;
        int qrear;
        int size;

    Queue(int size){
        this -> size = size;
        arr = new int[this -> size];
        qfront = 0;
        qrear = 0;
    }

    void enque(int data){
        if (qrear == size)
            cout << "Queue Full!" << endl;
        else {
            arr[qrear++] = data;
        }
    }

    int deque(){
        if (qfront == qrear){
            cout << "Queue empty" << endl;
            return -1;
        }
        else {
            int ele = arr[qfront];
            arr[qfront] = -1;
            qfront++;

            if(qfront == qrear){
                qfront = 0;
                qrear = 0;
            }
            return ele;
        }
    }

    bool isempty(){
        return (qrear == qfront);
    }

    int front(){
        if (isempty()){
            cout << "Queue empty" << endl;
            return -1;
        }
        
        return arr[qfront];
    }
};

int main(){

    Queue queue(3);

    queue.enque(10);
    queue.enque(20);
    queue.enque(30);
    queue.enque(40);

    cout << queue.front() << endl;

    queue.deque();
    queue.deque();

    cout << queue.front() << endl;
    
    queue.deque();

    cout << queue.front() << endl;

    return 0;
}