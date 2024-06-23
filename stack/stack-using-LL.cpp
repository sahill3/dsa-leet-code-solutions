#include<iostream>
using std::cout;
using std::endl;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this -> data = data;
            this -> next = nullptr;
        }
};


class Stack : public Node{
    private:
    Node* topNode;
    
    public:
    Stack() : Node(0){
        topNode = nullptr;
    }

    ~Stack(){
        while(!isempty()){
            pop();
        }
    }

    void push(int data){
        Node* node = new Node(data);
        node -> next = topNode;
        topNode = node;
    }

    void pop(){
        if (isempty()){
            cout << "Stack underflow." << endl; 
            return;
        }
        
        Node* temp = topNode;
        topNode = topNode -> next;
        delete temp;
    }

    int top(){
        if (isempty()){
            cout << "Stack underflow." << endl; 
            return -1;
        }

        return topNode -> data;
    }

    bool isempty(){
        return topNode == nullptr;
    }
};

int main(){
    
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl;

    st.pop();

    cout << st.top() << endl;

    st.pop();

    cout << st.top() << endl;

    st.pop();

    st.pop();

    return 0;
}