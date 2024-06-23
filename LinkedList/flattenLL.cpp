#include <iostream>
using namespace std;

class Node {
  public:
		int data;
		Node *next;
 		Node *child;
		Node() : data(0), next(nullptr), child(nullptr){};
		Node(int x) : data(x), next(nullptr), child(nullptr) {}
		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

Node* merge2Sorted(Node* &head1, Node* &head2){
	Node* newHead = new Node(-1);
	Node* temp = newHead;

	while(head1 && head2){
		if (head1 -> data < head2 -> data){
			temp -> child = head1;
			head1 = head1 -> child;
		}
		else{
			temp -> child = head2;
			head2 = head2 -> child;
		}
		temp = temp -> child;
	}

	if(head1)
		temp -> child = head1;

	if(head2)
		temp -> child = head2;

	return newHead -> child;
}

Node* combine(Node* &curr){
	if (curr == nullptr)
		return nullptr;

	Node* nextt = combine(curr->next);

	curr -> next = nullptr;

	return merge2Sorted(curr, nextt);
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	Node* ans = combine(head);
	return ans;
}

void print(Node* head) {
    Node* temp = head;

    while (temp) {
        cout << temp->data << " ";
        temp = temp->child;
    }
    cout << endl;
}

// int main() {
//     // Create a test case
//     Node* node4 = new Node(29);
//     Node* node3 = new Node(18, nullptr, new Node(22));
//     Node* node2 = new Node(8, new Node(10, new Node(15), nullptr), nullptr);
//     Node* node1 = new Node(1, new Node(2, new Node(3, node2, nullptr), nullptr), nullptr);

//     Node* head = flattenLinkedList(node1);
//     print(head);

//     delete node4;
//     delete node3;
//     delete node2;
//     delete node1;

//     return 0;
// }

int main() {
    // Create a test case
  
    Node* node7 = new Node(29);
    Node* node6 = new Node(22);
    Node* node5 = new Node(18, node7, node6);
    Node* node4 = new Node(15);
    Node* node3 = new Node(10, nullptr, node4);
    Node* node2 = new Node(8, node5, node3);
    Node* node1 = new Node(3, nullptr, nullptr);
    Node* node0 = new Node(2, nullptr, node1);
    Node* head = new Node(1, node2, node0);


    Node* flattened = flattenLinkedList(head);
    print(flattened);

    // Free allocated memory
    delete node7;
    delete node6;
    delete node5;
    delete node4;
    delete node3;
    delete node2;
    delete node1;
    delete head;

    return 0;
}