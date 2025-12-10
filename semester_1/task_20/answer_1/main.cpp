#include <iostream>
#include <ctime>

void swap(int& a, int& b) noexcept {
    const int temp = a;
    a = b;
    b = temp;
}

void visualize(const int* array, const int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
}

void sort(int* array, const int size, int& comparisons, int& moves) {
    comparisons = 0;
    moves = 0;

    bool swapped = true;
    for (int i = 0; i < size - 1 && swapped; i++) {
        // swapped = false;

        for (int j = 0; j < size - 1 - i; j++) {
            comparisons++;

            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                moves++;

                swapped = true;
            }
        }

        visualize(array, size);
        std::cout << std::endl;
    }
}

void fillRandom(int* array, const int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

int main() {
    constexpr int SIZE = 10;

    srand(time(nullptr));

    int array[SIZE] = {};
    fillRandom(array, SIZE);

    std::cout << "Origin:" << std::endl;
    visualize(array, SIZE);
    std::cout << std::endl;

    int comparisons, moves;
    sort(array, SIZE, comparisons, moves);

    std::cout << "Sorted (comparisons " << comparisons << "; moves " << moves << "):" << std::endl;
    visualize(array, SIZE);
    std::cout << std::endl;

    return 0;
}
