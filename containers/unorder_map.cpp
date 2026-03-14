#include <iostream>
#include <string>
#include <vector>
#include <list>

struct Entry {
    std::string key;
    int value;
};

class UnorderedMap {
    std::vector<std::list<Entry>> table;
    int capacity;

    int hashFunction(std::string key) {
        int hash = 0;
        for (char ch : key) hash += ch;
        return hash % capacity;
    }

public:
    UnorderedMap(int cap = 10) : capacity(cap) {
        table.resize(capacity);
    }

    void insert(std::string k, int v) {
        int index = hashFunction(k);
        for (auto& entry : table[index]) {
            if (entry.key == k) {
                entry.value = v;
                return;
            }
        }
        table[index].push_back({k, v});
    }

    int get(std::string k) {
        int index = hashFunction(k);
        for (auto& entry : table[index]) {
            if (entry.key == k) return entry.value;
        }
        return -1;
    }

    void remove(std::string k) {
        int index = hashFunction(k);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == k) {
                bucket.erase(it);
                return;
            }
        }
    }

    void print() {
        for (int i = 0; i < capacity; i++) {
            std::cout << i << ": ";
            for (auto& entry : table[i]) {
                std::cout << "[" << entry.key << ":" << entry.value << "] -> ";
            }
            std::cout << "NULL" << std::endl;
        }
    }
};

int main() {
    UnorderedMap um;
    um.insert("Apple", 100);
    um.insert("Banana", 200);
    um.insert("Grapes", 300);
    um.insert("Apple", 150);

    um.print();

    std::cout << "Banana: " << um.get("Banana") << std::endl;
    
    um.remove("Banana");
    um.print();

    return 0;
}
