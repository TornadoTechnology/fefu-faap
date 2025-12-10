#include <iostream>
#include <ctime>

void sort(int* array, const int size, int& comparisons, int& moves) {
    comparisons = 0;
    moves = 0;

    for (int i = 1; i < size; i++)
    {
        const int temp = array[i];

        int j = i;
        while (j >= 1 && array[j - 1] > temp)
        {
            comparisons++;
            array[j] = array[j - 1];
            moves++;

            j--;
        }

        array[j] = temp;
        moves++;
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
