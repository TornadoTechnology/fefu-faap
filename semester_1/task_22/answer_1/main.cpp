#include <iostream>
#include <ctime>

void swap(int& a, int& b) noexcept {
    const int temp = a;
    a = b;
    b = temp;
}

void shakeSort(int* array, const int size, int& comparisons, int& moves) {
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

void bubbleSort(int* array, const int size, int& comparisons, int& moves) {
    comparisons = 0;
    moves = 0;

    bool swapped = true;
    for (int i = 0; i < size - 1 && swapped; i++) {
        swapped = false;

        for (int j = 0; j < size - 1 - i; j++) {
            comparisons++;

            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                moves++;

                swapped = true;
            }
        }
    }
}

void binInclusionSort(int* array, const int size, int& comparisons, int& moves) {
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


void directInclusionSort(int* array, const int size, int& comparisons, int& moves) {
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

void directChooseSort(int* array, const int size, int& comparisons, int& moves) {
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

void print(const int* array, const int size, const char* name, const int comparisons, const int moves) {
    std::cout << name << " (comparisons " << comparisons << "; moves " << moves << "):" << std::endl;
    visualize(array, size);
    std::cout << std::endl;
}

void fillRandom(int* array, const int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

void copy(const int* from, int* to, const int size) {
    for (int i = 0; i < size; i++) {
        to[i] = from[i];
    }
}

int main() {
    constexpr int SIZE = 40;

    srand(time(nullptr));

    int origin[SIZE] = {};
    int temp[SIZE] = {};

    fillRandom(origin, SIZE);

    std::cout << "Origin:" << std::endl;
    visualize(origin, SIZE);
    std::cout << std::endl;

    int comparisons, moves;

    // Direct sort
    copy(origin, temp, SIZE);
    directChooseSort(temp, SIZE, comparisons, moves);
    print(temp, SIZE, "Direct choose", comparisons, moves);

    // Direct inclusion
    copy(origin, temp, SIZE);
    directInclusionSort(temp, SIZE, comparisons, moves);
    print(temp, SIZE, "Direct inclusion", comparisons, moves);

    // Binary inclusion
    copy(origin, temp, SIZE);
    binInclusionSort(temp, SIZE, comparisons, moves);
    print(temp, SIZE, "Binary inclusion", comparisons, moves);

    // Bubble
    copy(origin, temp, SIZE);
    bubbleSort(temp, SIZE, comparisons, moves);
    print(temp, SIZE, "Bubble", comparisons, moves);

    // Shake
    copy(origin, temp, SIZE);
    shakeSort(temp, SIZE, comparisons, moves);
    print(temp, SIZE, "Shake", comparisons, moves);

    return 0;
}
