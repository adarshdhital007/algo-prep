#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    void insertAtPosition(int value, int position) {
        if (position == 1) {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node;
        newNode->data = value;

        Node* current = head;
        for (int i = 1; i < position - 1 && current != NULL; i++) {
            current = current->next;
        }

        if (current == NULL) {
            cout << "Invalid Position" << endl;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "Linked list is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (head == NULL) {
            cout << "Linked List is empty" << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        delete current->next;
        current->next = NULL;
    }

    void display() {
        if (head == NULL) {
            cout << "Linked list is empty" << endl;
        }
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

void solve() {
    LinkedList list;

    cout << "Linked list before any operation: ";
    list.display();
    cout << endl;

    list.insertAtBeginning(8);
    list.insertAtBeginning(9);
    list.insertAtBeginning(10);
    cout << "Linked list after inserting 10 at the beginning: ";
    list.display();
    cout << endl;

    list.insertAtEnd(20);
    cout << "Linked list after inserting 20 at the end: ";
    list.display();
    cout << endl;

    list.insertAtPosition(30, 4);
    cout << "Linked list after inserting 30 at position 4: ";
    list.display();
    cout << endl;

    list.deleteAtBeginning();
    cout << "Linked list after deleting at the beginning: ";
    list.display();
    cout << endl;

    list.deleteAtEnd();
    cout << "Linked list after deleting at the end: ";
    list.display();
}

int main() {
    solve();
    return 0;
}
