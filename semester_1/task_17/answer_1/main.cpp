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

    for (int i = 0; i < size; i++)
    {
        int min = i;

        for (int j = i + 1; j < size; j++)
        {
            comparisons++;

            if (array[j] < array[min]) {
                min = j;
            }
        }

        swap(array[i], array[min]);
        moves += 3;
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

    std::cout << "Origin: ";
    visualize(array, SIZE);
    std::cout << std::endl;

    sort(array, SIZE);

    std::cout << "Sorted: ";
    visualize(array, SIZE);
    std::cout << std::endl;

    return 0;
}
