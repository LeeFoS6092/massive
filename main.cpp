#include "Massive.h"

int main() {

    Massive <int> arr = Massive<int>();

    for (int i = 0; i < 15; i++) {
        int p = rand() % 100;

        arr.append(p);
    }

    std::cout << arr.max() << std::endl;

    arr.Print();

    return 0;
}