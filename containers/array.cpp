#include <iostream>

class Array {
    int data[5]; 
    int sz = 5;

public:
    int& operator[](int index) {
        return data[index];
    }

    int size() {
        return sz;
    }

    void fill(int val) {
        for (int i = 0; i < sz; i++)
            data[i] = val;
    }

    void print() {
        for (int i = 0; i < sz; i++)
            std::cout << data[i] << " ";
        std::cout << std::endl;
    }
};

int main() {
    Array a;
    a.fill(7);
    a[0] = 10;
    a.print();
    return 0;
}
