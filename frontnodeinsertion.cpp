#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int new_data) : data(new_data), next(NULL) {}
};

Node* insertAtFront(Node* head, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = head;
    return new_node;
}

Node* insertAtPosition(Node* head, int position, int data) {
    Node* newNode = new Node(data);

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node* curr = head;
    for (int i = 1; curr != NULL && i < position - 1; ++i) {
        curr = curr->next;
    }

    if (curr == NULL) {
        delete newNode; // Clean up if position is out of bounds
        return head;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

Node* insertAfter(Node* head, int key, int new_data) {
    Node* curr = head;
    while (curr != NULL && curr->data != key) {
        curr = curr->next;
    }
    if (curr != NULL) {
        Node* new_node = new Node(new_data);
        new_node->next = curr->next;
        curr->next = new_node;
    }
    return head;
}

Node* insertAtEnd(Node* head, int new_data) {
    Node* new_node = new Node(new_data);
    if (head == NULL) {
        return new_node;
    }

    Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    return head;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << " " << curr->data;
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);

    cout << "Original Linked List:";
    printList(head);

    int data = 0;
    head = insertAtFront(head, data);

    cout << "After inserting Nodes at the front:";
    printList(head);

    int key = 3, newData = 6;
    head = insertAfter(head, key, newData);

    cout << "Linked List after insertion: ";
    printList(head);

    int newDataAtPos = 12, pos = 3;
    head = insertAtPosition(head, pos, newDataAtPos);
    cout << "Linked list after insertion of 12 at position 3:";
    printList(head);

    cout << "Created Linked list is: ";
    printList(head);

    head = insertAtEnd(head, 1);

    cout << "\nAfter inserting 1 at the end: ";
    printList(head);

    return 0;
}

