#include <iostream>

class MultiSet {
    int data[100];
    int sz;

public:
    MultiSet() : sz(0) {}

    void insert(int val) {
        int i = sz - 1;
        while (i >= 0 && data[i] > val) {
            data[i + 1] = data[i];
            i--;
        }
        data[i + 1] = val;
        sz++;
    }

    void remove(int val) {
        for (int i = 0; i < sz; i++) {
            if (data[i] == val) {
                for (int j = i; j < sz - 1; j++) {
                    data[j] = data[j + 1];
                }
                sz--;
                return;
            }
        }
    }

    int count(int val) {
        int c = 0;
        for (int i = 0; i < sz; i++) {
            if (data[i] == val) c++;
        }
        return c;
    }

    void print() {
        for (int i = 0; i < sz; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MultiSet ms;
    ms.insert(30);
    ms.insert(10);
    ms.insert(20);
    ms.insert(10);

    ms.print();
    std::cout << "10-երի քանակը: " << ms.count(10) << std::endl;

    ms.remove(10);
    ms.print();

    return 0;
}
