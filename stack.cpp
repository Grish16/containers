#include <iostream>
#include <initializer_list>
using namespace std;


class V {
    int* data;
    size_t sz;
    size_t cap;

public:
    V() : data(nullptr), sz(0), cap(0) {}

    V(initializer_list<int> init) {
        sz = init.size();
        cap = sz;
        data = new int[cap];
        size_t i = 0;
        for (int x : init) data[i++] = x;
    }

    ~V() { delete[] data; }

    size_t size() const { return sz; }
    size_t capacity() const { return cap; }

    int& operator[](size_t index) { return data[index]; }
    const int& operator[](size_t index) const { return data[index]; }

    void reserve(size_t new_cap) {
        if (new_cap <= cap) return;
        int* new_data = new int[new_cap];
        for (size_t i = 0; i < sz; i++) new_data[i] = data[i];
        delete[] data;
        data = new_data;
        cap = new_cap;
    }

    void resize(size_t new_size, int val = 0) {
        if (new_size > cap) reserve(new_size);
        if (new_size > sz) {
            for (size_t i = sz; i < new_size; i++) data[i] = val;
        }
        sz = new_size;
    }

    void push_back(int x) {
        if (sz == cap) reserve(cap == 0 ? 1 : cap * 2);
        data[sz++] = x;
    }

    void print() const {
        for (size_t i = 0; i < sz; i++) cout << data[i] << " ";
        cout << endl;
    }
};


class Stack : private V {
public:
    Stack() : V() {}

    void push(int x) {
        push_back(x); 
    }

    void pop() {
        if (size() == 0) {
            cout << "Stack is empty!\n";
            return;
        }
        resize(size() - 1);
    }

    int top() const {
        if (size() == 0) throw runtime_error("Stack is empty");
        return (*this)[size() - 1];
    }

    bool empty() const {
        return size() == 0;
    }

    void print_stack() const {
        
        for (size_t i = 0; i < size(); i++)
            cout << (*this)[i] << " ";
        cout << endl;
    }
};


int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Stack: ";
    st.print_stack(); 

    cout << "Top: " << st.top() << endl; 

    st.pop();
    cout << "After pop, top: " << st.top() << endl;

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
