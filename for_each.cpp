#include <iostream>
using namespace std;

template <typename It, typename Func>
void my_for_each(It b, It e, Func f) {
    for (; b != e; ++b) {
        f(*b);
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5};

    my_for_each(a, a + 5, [](int x) {
        cout << x << " ";
    });

    return 0;
}
