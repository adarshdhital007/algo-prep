#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int data;
    ListNode* next;
    ListNode(int value) : data(value), next(nullptr) {}
};

ListNode* reverseLinkedList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void print(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

ListNode* createLinkedList() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for(int i=1;i<10;i++) {
        ListNode* newNode = new ListNode(i);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void solve() {
    ListNode* head = createLinkedList();

    cout << "Original Linked List : ";
    print(head);

    head = reverseLinkedList(head);

    cout << "Reversed linked list is : ";
    print(head);
}

int main() {
    solve();
    return 0;
}
