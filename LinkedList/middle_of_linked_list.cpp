#include<iostream>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode* next;

        ListNode(int d) : data(d), next(nullptr) {};
};

void addNode(ListNode* &tail, ListNode* &head, int data){
    
    ListNode* node = new ListNode(data);
    
    if (!head){
        head = node;
        tail = node;
    }

    else{
        tail -> next = node;
        tail = tail -> next;
    }
}

ListNode* findMiddle(ListNode* head){

    if (!head || !head -> next) return head;

    ListNode* slow = head;
    ListNode* fast = head -> next;

    while(fast){
        fast = fast -> next;

        if (fast)
            fast = fast -> next;

        slow = slow -> next;
    }
    return slow;
}

int main(){

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    addNode(tail, head, 1);
    addNode(tail, head, 2);
    addNode(tail, head, 3);
    addNode(tail, head, 4);
    addNode(tail, head, 5);

    ListNode* middle = findMiddle(head);

    if (middle) cout << "Middle: " << middle -> data;
    
    return 0;
}