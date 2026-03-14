#include <iostream>
#include <vector>
#include <list>

class UnorderedSet {
    std::vector<std::list<int>> table;
    int capacity;

    int hashFunction(int key) {
        return key % capacity;
    }

public:
    UnorderedSet(int cap = 10) : capacity(cap) {
        table.resize(capacity);
    }

    void insert(int key) {
        int index = hashFunction(key);
        for (int x : table[index]) {
            if (x == key) return;
        }
        table[index].push_back(key);
    }

    bool find(int key) {
        int index = hashFunction(key);
        for (int x : table[index]) {
            if (x == key) return true;
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    void print() {
        for (int i = 0; i < capacity; i++) {
            std::cout << i << ": ";
            for (int x : table[i]) {
                std::cout << x << " -> ";
            }
            std::cout << "NULL" << std::endl;
        }
    }
};

int main() {
    UnorderedSet us;
    us.insert(10);
    us.insert(20);
    us.insert(15);
    us.insert(10); 

    us.print();

    if (us.find(15)) std::cout << "15-ը գտնվեց!" << std::endl;

    us.remove(15);
    us.print();

    return 0;
}
