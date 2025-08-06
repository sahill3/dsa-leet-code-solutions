#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int val){
        this->data = val;
        this->next = nullptr;
    }
};

Node* deleteNode(Node* start, int index){
    if (index == 0) return start->next;
    
    int i = 0;
    Node* temp = start;
    while(i < index-1) {
        start = start->next;
        i++;
    }

    start -> next = start -> next -> next;
    return temp;
}

void printList(Node* start){
    while(start != nullptr){ 
    cout << start->data << " ";
    start = start -> next;
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Node* head = new Node(-1);
    Node* temp = head;
    
    int n;
    cin >> n;
    
    for (int i=0; i < n; i++){
        int tmp;
        cin >> tmp;
        temp -> next = new Node(tmp);
        temp = temp -> next;
    }
    
    int posi;
    cin >> posi;
    
    head = deleteNode(head->next, posi);
    
    printList(head);
    return 0;
}
