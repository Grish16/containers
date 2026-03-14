#include <iostream>
#include <vector>
#include <list>

class UnorderedMultiSet {
    std::vector<std::list<int>> table;
    int capacity;

    int hashFunction(int key) {
        return (key < 0 ? -key : key) % capacity;
    }

public:
    UnorderedMultiSet(int cap = 10) : capacity(cap) {
        table.resize(capacity);
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    int count(int key) {
        int index = hashFunction(key);
        int c = 0;
        for (int x : table[index]) {
            if (x == key) c++;
        }
        return c;
    }

    void remove(int key) {
        int index = hashFunction(key);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == key) {
                bucket.erase(it);
                return;
            }
        }
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
    UnorderedMultiSet ums;
    ums.insert(10);
    ums.insert(20);
    ums.insert(10);
    ums.insert(15);

    ums.print();

    std::cout << "10-երի քանակը: " << ums.count(10) << std::endl;

    ums.remove(10);
    ums.print();

    return 0;
}
