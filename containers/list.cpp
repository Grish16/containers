#include <iostream>

struct Node {
    int data;
    Node* next;
};

class List {
    Node* head;

public:
    List() { head = nullptr; }

    void push_front(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

    void push_back(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main() {
    List l;
    l.push_back(10);
    l.push_back(20);
    l.push_front(5);
    l.print(); 
    return 0;
}
