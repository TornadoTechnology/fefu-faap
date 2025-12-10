#include <iostream>
#include <ctime>

void sort(int* array, const int size, int& comparisons, int& moves) {
    comparisons = 0;
    moves = 0;

    for (int i = 1; i < size; i++) {
        const int temp = array[i];
        int left = 0;
        int right = i - 1;

        while (left <= right) {
            const int mid = left + (right - left) / 2;
            comparisons++;

            if (array[mid] > temp) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        for (int j = i - 1; j >= left; j--) {
            array[j + 1] = array[j];
            moves++;
        }

        array[left] = temp;
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
