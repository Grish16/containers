#include <iostream>
#include <vector>
#include <algorithm>

class PriorityQueue {
    std::vector<int> heap;

    void heapifyUp(int index) {
        if (index == 0) return;
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) {
            std::swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest]) largest = left;
        if (right < heap.size() && heap[right] > heap[largest]) largest = right;

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }
};

int main() {
    PriorityQueue pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    std::cout << "Ամենամեծ տարրը: " << pq.top() << std::endl; 

    pq.pop();
    std::cout << "Հաջորդ ամենամեծը: " << pq.top() << std::endl; 

    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << std::endl;

    return 0;
}
