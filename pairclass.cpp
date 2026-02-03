#include <iostream>
#include <string>
using namespace std;


class Pair {
public:
    int ar;
    string erk;


    Pair(int a, string b) {
        ar = a;
        erk = b;
    }


    void print() const {
        cout << ar << ": " << erk << endl;
    }
};

int main() {
    Pair p1(1, "Grish");
    p1.print();

    return 0;
}
