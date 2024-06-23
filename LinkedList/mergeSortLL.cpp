#include<iostream>
using namespace std;

class node{

public:
    int data;
    node* next;

    node(int data){
        this -> data = data;
        this -> next = nullptr;
    }
};

void insertAtTail(node* &head, int data){
    if (!head){
        head = new node(data);
        return;
    }

    node* temp = head;

    while(temp -> next)
        temp = temp -> next;

    temp -> next = new node(data);
}

void print(node* head){
    node* temp = head;

    while(temp){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

node* findMid(node* &head){
    node* slow = head;
    node* fast = head -> next;

    while(fast && fast->next){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}

node* merge(node* left, node* right){

    if (!left)
        return right;

    if (!right)
        return left;

    node* ans = new node(-1);
    node* curr = ans;

    while(left && right){
        if (left->data < right->data){
            curr -> next = left;
            left = left -> next;
        }
        else{
            curr -> next = right;
            right = right -> next;
        }
        curr = curr -> next;
    }

    if (left)   
        curr -> next = left;
    else
        curr -> next = right;

    return ans->next;
}

node* mergeSort(node* head){
    if (head == nullptr || head -> next == nullptr)
        return head;

    node* mid = findMid(head);

    node* left = head;
    node* right = mid -> next;
    mid -> next = nullptr;

    left = mergeSort(left);
    right = mergeSort(right);

    node* result = merge(left, right);
    return result;
}

int main(){
    
    node* head = nullptr;

    insertAtTail(head, 5);
    insertAtTail(head, 3);
    insertAtTail(head, 10);
    insertAtTail(head, 8);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 4);

    print(head);

    head = mergeSort(head);

    print(head);

    return 0;
}