#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node(){
        int val = this -> data;
        if(this->next != NULL)
            delete next;
            this->next = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void insertInMiddle(Node* &head, Node* &tail, int data, int pos){

    if(pos == 1){
        insertAtHead(head, data);
        return;
    }

    Node* temp = new Node(data);
    Node* curr = head;
    int i = 1;
    while(i < pos-1){
        curr = curr -> next;
        i++;
    }

    if(curr == tail)
        insertAtTail(tail, data);
    else{
        temp -> next = curr -> next;
        curr -> next = temp;
    }    
        
}

void printLinkedList(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void deleteByPos(Node* &head, Node* &tail, int pos){
    if(pos == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
        return;
    }

    Node* curr = head;
    int i = 1;
    while(i < pos-1){
        curr = curr -> next;
        i++;
    }

    if(curr -> next == tail){
        Node* temp = curr->next;
        curr -> next = NULL;
        tail = curr;
        delete temp;
    }
    else{
        Node* temp = curr->next;
        curr -> next = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
}

void deleteByValue(Node* &head, Node* &tail, int val){
    Node* curr = head;

    if(curr -> data == val && curr == head){
        head = head -> next;
        curr -> next = NULL;
        delete curr;
        return;
    }

    while(curr -> next != NULL){
        if(curr -> next -> data == val){
            if(curr -> next == tail){
                Node* temp = curr -> next;
                curr -> next = NULL;
                tail = curr;
                delete temp;
                return;
            }
            Node* temp = curr -> next;
            curr -> next = temp -> next;
            temp -> next = NULL;
            delete temp;
            return;
        }
        curr = curr -> next;
    }
}

int main(){

    Node* node1 = new Node(30); 
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 20);
    printLinkedList(head);

    insertAtHead(head, 10);
    printLinkedList(head);

    insertAtTail(tail, 40);
    printLinkedList(head);

    insertInMiddle(head, tail, 50, 5);
    printLinkedList(head);

    // cout << "head: " << head->data << endl;
    // cout << "tail: " << tail->data << endl;

    // deleteByPos(head, tail, 1);
    
    deleteByValue(head, tail, 20);
    printLinkedList(head);

    delete head;

    return 0;
}