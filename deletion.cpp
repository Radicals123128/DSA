#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
public:
    LinkedList() : head(NULL) {}

    void append(int value) {
        if (!head) {
            head = new Node(value);
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new Node(value);
    }

    void deleteValue(int value) {
        if (!head) return;

        if (head->data == value) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

private:
    Node* head;
};

int main() {
    LinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);

    std::cout << "Original List: ";
    list.printList();

    list.deleteValue(20);
    std::cout << "After deleting 20: ";
    list.printList();

    list.deleteValue(10);
    std::cout << "After deleting 10: ";
    list.printList();

    list.deleteValue(50);
    std::cout << "After attempting to delete 50: ";
    list.printList();

    return 0;
}

