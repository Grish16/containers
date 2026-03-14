#include <iostream>
#include <string>

struct Pair {
    std::string key;
    int value;
};

class MultiMap {
    Pair data[100];
    int count = 0;

public:
    void insert(std::string k, int v) {
        data[count].key = k;
        data[count].value = v;
        count++;
    }

    void find(std::string k) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (data[i].key == k) {
                std::cout << data[i].key << " : " << data[i].value << std::endl;
                found = true;
            }
        }
        if (!found) std::cout << "Բանալին չի գտնվել" << std::endl;
    }

    void print() {
        for (int i = 0; i < count; i++) {
            std::cout << data[i].key << " : " << data[i].value << std::endl;
        }
    }
};

int main() {
    MultiMap mm;
    mm.insert("Apple", 10);
    mm.insert("Banana", 20);
    mm.insert("Apple", 50);

    mm.print();

    std::cout << "--- Գտնել Apple-ները ---" << std::endl;
    mm.find("Apple");

    return 0;
}
