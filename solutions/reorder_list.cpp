#include<iostream>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;

    ListNode(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtTail(ListNode* &tail, int data){
    ListNode* node = new ListNode(data);
    tail -> next = node;
    tail = tail -> next;
}

void print(ListNode* &head){
    ListNode* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void reorderList(ListNode* &head){
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast != NULL && fast->next != NULL && fast -> next -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    ListNode* head2 = slow -> next;
    slow -> next = NULL;
    ListNode* prev = NULL;
    ListNode* nextt = NULL;

    while(head2){
        nextt = head2 -> next;
        head2 -> next = prev;
        prev = head2;
        head2 = nextt;
    }

    ListNode* head1 = head;
    head2 = prev;
    ListNode* temp = head;

    while(head1 != NULL){
        if(temp == head1){
            head1 = head1 -> next;
            temp -> next = head2;
            temp = temp -> next;
        }        
        else{
            head2 = head2 -> next; 
            temp -> next = head1;
            temp = temp -> next;
        }
    }
}

int main(){

    ListNode* node = new ListNode(1);
    ListNode* head = node;
    ListNode* tail = node;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    print(head);

    reorderList(head);

    print(head);

    return 0;
}