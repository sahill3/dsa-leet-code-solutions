#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
        this -> prev = NULL;
    }

};

void print(Node* &head){
    Node* curr = head;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr -> next; 
    }
    cout << endl;
}

int getLenght(Node* &head){
    int cnt = 0;

    Node* temp = head;

    while(temp != NULL){
        cnt++;
        temp = temp -> next;
    }

    return cnt;
}

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    head -> prev = temp;
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    temp -> prev = tail;
    tail -> next = temp;
    tail = temp;
}

void insertByPosition(Node* &head, Node* &tail, int data, int pos){
    if(pos == 1){
        insertAtHead(head, data);
        return;
    }

    int len = getLenght(head);
    if(pos > len){
        insertAtTail(tail, data);
        return;
    }
    
    Node* curr = head;

    int cnt = 1;
    while(cnt < pos-1){
        curr = curr -> next;
        cnt++;
    }

    Node* temp = new Node(data);
    temp -> next = curr -> next;
    curr -> next -> prev = temp;
    temp -> prev = curr;
    curr -> next = temp;
}

int main(){
    
    Node* node1 = new Node(30);
    Node* head = node1;
    Node* tail = node1;
    
    print(head);

    insertAtHead(head, 20);
    print(head);

    insertAtHead(head, 10);
    print(head);

    insertAtTail(tail, 40);
    print(head);

    insertAtTail(tail, 50);
    print(head);

    insertByPosition(head, tail, 25, 3);
    print(head);

    cout << "Length: " << getLenght(head) << endl;

    return 0;
}