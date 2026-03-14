#include <iostream>

struct Node {
    int data;
    Node* next;
};

class ForwardList {
    Node* head;

public:
    ForwardList() : head(nullptr) {}

    void push_front(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

    void pop_front() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int front() {
        if (head != nullptr) return head->data;
        return -1;
    }

    bool empty() {
        return head == nullptr;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    ~ForwardList() {
        while (head != nullptr) {
            pop_front();
        }
    }
};

int main() {
    ForwardList fl;
    fl.push_front(30);
    fl.push_front(20);
    fl.push_front(10);

    fl.print(); 

    fl.pop_front();
    fl.print(); 
    return 0;
}
