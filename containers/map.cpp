#include <iostream>
#include <string>

struct Pair {
    std::string key;
    int value;
};

class Map {
    Pair data[100];
    int count = 0;

public:
    void insert(std::string k, int v) {
        for (int i = 0; i < count; i++) {
            if (data[i].key == k) {
                data[i].value = v;
                return;
            }
        }
        data[count].key = k;
        data[count].value = v;
        count++;
    }

    int get(std::string k) {
        for (int i = 0; i < count; i++) {
            if (data[i].key == k) return data[i].value;
        }
        return -1; 
    }

    void print() {
        for (int i = 0; i < count; i++) {
            std::cout << data[i].key << " : " << data[i].value << std::endl;
        }
    }
};

int main() {
    Map m;
    m.insert("Apple", 10);
    m.insert("Banana", 20);
    m.insert("Apple", 15); 

    m.print();
    std::cout << "Banana-ի արժեքը: " << m.get("Banana") << std::endl;

    return 0;
}
