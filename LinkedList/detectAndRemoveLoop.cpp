#include<iostream>
using namespace std; 

class Node {
    public :

    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
        this -> next = nullptr;
    }

    ~Node(){
        Node* curr = this;
        Node* nextNode;

        while(curr != nullptr){
            nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
};

void append(Node* &head, int data){
    Node* node = new Node(data);
    Node* curr = head;

    if (head == nullptr){
        head = node;
        return;
    }

    while(curr->next != nullptr)
        curr = curr -> next;

    curr -> next = node;
}

void createLoop(Node* &head){
    Node* tail = head;
    int cnt = 0;
    while(tail -> next != nullptr){
        tail = tail -> next;
        cnt++;
    }

    int mid = cnt / 2;
    Node* temp = head;

    while(cnt > 0){
        temp = temp -> next;
        cnt--;
    }

    tail -> next = temp;
}

Node* floydDetection(Node* head){
    if (head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast -> next;

        if (fast != NULL)
            fast = fast -> next;

        slow = slow -> next;

        if (fast == slow)
            return slow;
    }
    cout << "Loop found." << endl;
    return fast;
}

Node *getStartingNode(Node* head){
    if (head == NULL)
        return NULL;

    Node* intersection = floydDetection(head);
    
    if (intersection == NULL)
        return NULL;

    Node* slow = head;

    while(slow != intersection){
        slow = slow -> next;
        intersection = intersection -> next;
    }
    return slow;
}

Node *removeLoop(Node *head)
{
    // Write your code here.
    Node* start = getStartingNode(head);

    if (start == NULL)
        return head;

    Node* temp = start;

    while(temp -> next != start)
        temp = temp->next;

    temp->next = NULL;

    return head;
}

void print(Node* &head){
    if (head == NULL)
        return;
    
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){

    Node* head = nullptr;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);
    print(head);

    createLoop(head);

    removeLoop(head);
    print(head);

    delete head;
    return 0;
}