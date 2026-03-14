#include <iostream>
#include <string>
#include <vector>
#include <list>

struct Entry {
    std::string key;
    int value;
};

class UnorderedMultiMap {
    std::vector<std::list<Entry>> table;
    int capacity;

    int hashFunction(std::string key) {
        int hash = 0;
        for (char ch : key) hash += ch;
        return hash % capacity;
    }

public:
    UnorderedMultiMap(int cap = 10) : capacity(cap) {
        table.resize(capacity);
    }

    void insert(std::string k, int v) {
        int index = hashFunction(k);
        table[index].push_back({k, v});
    }

    void find(std::string k) {
        int index = hashFunction(k);
        bool found = false;
        for (auto& entry : table[index]) {
            if (entry.key == k) {
                std::cout << entry.key << " : " << entry.value << std::endl;
                found = true;
            }
        }
        if (!found) std::cout << "Բանալին չի գտնվել" << std::endl;
    }

    void remove(std::string k) {
        int index = hashFunction(k);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ) {
            if (it->key == k) {
                it = bucket.erase(it);
                return; 
            } else {
                ++it;
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
    UnorderedMultiMap umm;
    umm.insert("Apple", 100);
    umm.insert("Banana", 200);
    umm.insert("Apple", 150);
    umm.insert("Grapes", 300);

    umm.print();

    std::cout << "--- Գտնել Apple-ները ---" << std::endl;
    umm.find("Apple");

    umm.remove("Apple");
    std::cout << "--- Ջնջելուց հետո ---" << std::endl;
    umm.print();

    return 0;
}
