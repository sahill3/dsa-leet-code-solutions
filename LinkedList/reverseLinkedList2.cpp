#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left == right)
        return head;
    
    ListNode* start = new ListNode(-1);
    start -> next = head;

    for (int i = 1 ; i < left; i++)
        start = start -> next;

    ListNode* prev = nullptr;
    ListNode* curr = start -> next;
    ListNode* nextt = nullptr;
    
    for (int i = left; i <= right; i++){
        nextt = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nextt;
    }

    start -> next -> next = nextt;
    start -> next = prev;

    return left == 1 ? start -> next : head;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original list: ";
    printList(head);

    int left = 2, right = 4;
    head = reverseBetween(head, left, right);

    std::cout << "List after reversing between position " << left << " and " << right << ": ";
    printList(head);

    return 0;
}
