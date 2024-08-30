#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(NULL) {}

    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertBegin(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void printList() const {
        Node* temp = head;
        while (temp != NULL) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    ~LinkedList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertBegin(5);

    std::cout << "List after insertions: ";
    list.printList();

    return 0;
}

