#include "Massive.h"
#include "math.h"

int main() {

    Massive <int> arr = Massive<int>();

    for (int i = 0; i < 100; i++) {
        int p = rand() % 100;

        arr.append(pow(-1, rand() % 10) * p);
    }

    arr.append(0);

    arr.Print();

    std::cout << arr.find(0) << std::endl;

    return 0;
}