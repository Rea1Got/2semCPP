#include <iostream>
#include <fstream>  // запись в файл
#include <chrono>  // замер времени
#include <random>

#define MIN 100
#define MAX 50000
#define STEP 10
#define LOOP_TIMES 100
#define SEED 2
#define SEED_VARIATION 10 // при SEED < SEED_VARIATION генерируются разные уникальные массивы;

int findPairN2(int arr[MAX], int key, int limRight, int limLeft = 0) {
    auto begin = std::chrono::steady_clock::now();  // начало отсчета
    for (int i = limLeft; i < limRight; i++) {
        for (int j = i + 1; j < limRight; j++) {
            if (arr[i] + arr[j] == key) {
                auto end = std::chrono::steady_clock::now();
                auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
                // std::cout << "Found! ";
                return time_span.count();
            }
        }
    }
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // std::cout << "Failed! ";
    return time_span.count();
}

int findPairLinear(int arr[MAX], int key, int limRight, int limLeft = 0) {
    int left = limLeft;
    int right = limRight - 1;

    auto begin = std::chrono::steady_clock::now();  // начало отсчета
    while (left < right) {
        int currentSum = arr[left] + arr[right];
        if (currentSum == key) {
            auto end = std::chrono::steady_clock::now();
            auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            std::cout << "Found! ";
            return time_span.count();
        } else if (currentSum < key) {
            left++;
        } else {
            right--;
        }
    }
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // std::cout << "Found! ";
    return time_span.count();
}

int fillArrayAndKey(int (&array)[MAX], int seed, int limRight = MAX) {
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, limRight - 1);

    for (int i = 0; i < limRight; i++){
        array[i] = dstr(rng);
        // std::cout << array[i] << ' '; 
    }
    // std::cout << "Array is generated!\n";

    int key = dstr(rng);
    // printf("The key is: %d\n", key);
    return key;
}

int main() {
    unsigned int seed = SEED;
    int array[MAX] = {0};

    for (int i = 0; i < LOOP_TIMES; i++){  // количество повторений генерации массива 
        int key = fillArrayAndKey(array, seed);

        std::ofstream foutN2("outputN2.txt", std::ios::app);
        for (int j = MIN; j < MAX; j += STEP){    
            foutN2 << findPairN2(array, array[key], j) << ' ';
        }
        foutN2 << '\n';
        foutN2.close();

        std::ofstream foutLinear("outputLinear.txt", std::ios::app);
        for (int j = MIN; j < MAX; j += STEP){    
            foutLinear << findPairLinear(array, array[key], j) << ' ';
        }
        foutLinear << '\n';
        foutLinear.close();

        seed += SEED_VARIATION;
        std::cout << "Current progress: " << static_cast<float>(i)/LOOP_TIMES*100 << "%\n";
    }
    return 0;
}
