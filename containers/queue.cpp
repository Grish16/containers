#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};


class Queue {
    Node* frontNode; 
    Node* rearNode;   

public:
    Queue() : frontNode(nullptr), rearNode(nullptr) {}

    
    bool empty() const {
        return frontNode == nullptr;
    }

    
    void push(int x) {
        Node* n = new Node(x);
        if (!rearNode) {
            frontNode = rearNode = n;
        } else {
            rearNode->next = n;
            rearNode = n;
        }
    }

   
    void pop() {
        if (empty()) return;
        Node* tmp = frontNode;
        frontNode = frontNode->next;
        if (!frontNode) rearNode = nullptr; 
        delete tmp;
    }


    int front() const {
        if (empty()) throw runtime_error("Queue is empty");
        return frontNode->data;
    }


    int back() const {
        if (empty()) throw runtime_error("Queue is empty");
        return rearNode->data;
    }


    ~Queue() {
        while (frontNode) {
            Node* tmp = frontNode;
            frontNode = frontNode->next;
            delete tmp;
        }
    }
};


int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl; 
    cout << "Back: " << q.back() << endl;   

    q.pop(); 
    cout << "Front after pop: " << q.front() << endl; 

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
