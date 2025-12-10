#include <iostream>
#include <ctime>

void swap(int& a, int& b) noexcept {
    const int temp = a;
    a = b;
    b = temp;
}

void sort(int* array, const int size, int& comparisons, int& moves) {
    comparisons = 0;
    moves = 0;

    int left = 0;
    int right = size - 1;

    while (left < right) {
        for (int i = left; i < right; i++) {
            comparisons++;
            if (array[i] > array[i + 1]) {
                std::swap(array[i], array[i + 1]);
                moves += 2;
            }
        }

        right--;

        for (int i = right; i > left; i--) {
            comparisons++;
            if (array[i - 1] > array[i]) {
                std::swap(array[i - 1], array[i]);
                moves += 2;
            }
        }

        left++;
    }
}

void visualize(const int* array, const int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
}

void fillRandom(int* array, const int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

int main() {
    constexpr int SIZE = 40;

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
