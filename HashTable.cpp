#include <iostream>
using namespace std;

class Hash {
    int table[10];  
public:
    Hash() {
        for (int i = 0; i < 10; i++)
            table[i] = 0;
    }

    int hash(int key) {
        return key % 10;
    }

    void insert(int key) {
        int i = hash(key);
        table[i] = key;
    }

    void print() {
        for (int i = 0; i < 10; i++)
            cout << i << " : " << table[i] << endl;
    }
};

int main() {
    Hash h;
    h.insert(11);
    h.insert(25);
    h.insert(7);
    h.print();
}
