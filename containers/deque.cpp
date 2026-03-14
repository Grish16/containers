#include <iostream>

class Deque {
    int data[100];
    int head;
    int tail;
    int count;

public:
    Deque() {
        head = 50;
        tail = 50;
        count = 0;
    }

    void push_back(int val) {
        data[tail++] = val;
        count++;
    }

    void push_front(int val) {
        data[--head] = val;
        count++;
    }

    void pop_back() {
        if (count > 0) {
            tail--;
            count--;
        }
    }

    void pop_front() {
        if (count > 0) {
            head++;
            count--;
        }
    }

    void print() {
        for (int i = head; i < tail; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    int size() {
        return count;
    }
};

int main() {
    Deque dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.push_front(1);

    dq.print(); 

    dq.pop_front();
    dq.print(); 

    return 0;
}
