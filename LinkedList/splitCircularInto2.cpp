#include<iostream>
#include<cmath>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }

    ~Node(){
        Node* curr = this;
        Node* nextNode;

        while(curr != nullptr){
            nextNode = curr -> next;
            delete curr;
            curr = next;
        }
    }
};

void insertNode(Node* &tail, int element, int d) {
    
    //empty list
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list

        Node* curr = tail;

        while(curr->data != element) {
            curr = curr -> next;
        }
        
        //element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}    

void appendNode(Node* &tail, int data){
    Node* temp = new Node(data);
    Node* curr = tail;
    if (tail == nullptr){
        tail = temp;
        tail -> next = tail;
        return;
    }
    else{
        while(curr -> next != tail)
            curr = curr -> next;   
    }
    
    temp -> next = curr -> next;
    curr -> next = temp;
}
  
void print(Node* tail) {

    Node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
}   

Node* splitInto2(Node* &tail){

    Node* slow = tail;
    Node* fast = tail;

    do{
        fast = fast -> next;
        
        if (fast -> next == tail)
            break;

        fast = fast -> next;  
        slow = slow -> next;

    }while(fast->next != tail); 

    Node* tail2 = slow -> next;
    slow -> next = tail;
    fast->next = tail2;

    return tail2;
}   

int main(){

    Node* tail = nullptr;

    appendNode(tail, 1);
    appendNode(tail, 2);
    appendNode(tail, 3);
    appendNode(tail, 4);
    appendNode(tail, 5);
    appendNode(tail, 6);

    print(tail);

    Node* tail2 = splitInto2(tail);

    cout << "List 1: ";
    print(tail);
    cout << "List 2: ";
    print(tail2);

    delete tail;
    delete tail2;
    return 0;
}