#include <iostream>
#include <chrono>
#include <random>

#define START_SIZE 5
#define LOOP_TIMES 5
#define STEP 1

int count = 0;

int* copyArray(int data[], int size) {
    int* newArray = new int[size + STEP];
    for (int i = 0; i < size; i++) {
        newArray[i] = data[i];
    }
    return newArray;
}

auto timerStart() {
    return std::chrono::steady_clock::now();
}

int timerStop(auto begin) {
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    return static_cast<int>(time_span.count());
}

auto test1(int data[], int size, int newData) {
    auto ts = timerStart();
    int* newArray = copyArray(data, size);
    newArray[size] = newData;
    delete[] newArray; // Освобождаем память после использования
    return timerStop(ts);
}

int main() {
    for (int i = 0; i < LOOP_TIMES; i++) {
        int data[START_SIZE + STEP * count] = {0};
        int newData = i;
        std::cout << "Время копирования массива: " << test1(data, START_SIZE + STEP * count, newData) << " нс" << std::endl;
        count++;
    }
    return 0;
}
