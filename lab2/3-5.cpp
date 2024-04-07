#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include <string>
#include <iterator>
#include <math.h>

#define START_SIZE 100
#define LOOP_TIMES 100
#define STEP 100
#define END_SIZE 100000

int* copyArray(int data[], int size, int step) {
    int* newArray = new int[size + step];
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
    int* newArray = copyArray(data, size, 1);
    newArray[size] = newData;
    int time = timerStop(ts);
    delete[] newArray; 
    return time;
}

auto test2(int data[], int size, int newData) {
    auto ts = timerStart();
    int* newArray = copyArray(data, size, STEP);
    newArray[size] = newData;
    int time = timerStop(ts);
    delete[] newArray; 
    return time;
}

auto test3(int data[], int size, int newData) {
    auto ts = timerStart();
    int* newArray = copyArray(data, size, size);
    newArray[size] = newData;
    int time = timerStop(ts);
    delete[] newArray; 
    return time;
}

void writeInFile(std::string filename, int *result, int size){
    std::ofstream fout(filename, std::ios::app);
    for (int i = 0; i < size; i++){
        fout << result[i] << ' ';
    }
    fout << '\n';
    fout.close();
}

int main(){
    int count = 1;
    int newData = 1337;
    std::string txtNames[] = { "3-5_firstTest.txt", "3-5_secondTest.txt", "3-5_thirdTest.txt" };

    // for (int i = 0; i < END_SIZE; i += STEP) {
    //     int data1[START_SIZE + count] = {0};   // + 1
    //     // int data2[START_SIZE + i] = {0};  // + STEP
    //     // int data3[START_SIZE*2] = {0};   // *2
    //     int result1[START_SIZE + count] = {0};
    //     // int result2[START_SIZE + count] = {0};
    //     // int result3[START_SIZE + count] = {0};

    //     for (int j = 0; j < LOOP_TIMES; j++) {
    //         result1[j] = test1(data1, START_SIZE + count, newData);
    //         // result2[j] = test2(data2, START_SIZE + i, newData);
    //         // result3[j] = test3(data3, START_SIZE*pow(2, i), newData);
    //     }
    //     writeInFile(txtNames[0], result1, LOOP_TIMES);
    //     // writeInFile(txtNames[1], result2, LOOP_TIMES);
    //     // writeInFile(txtNames[2], result3, LOOP_TIMES);
    //     count++;
    // }

    for (int i = START_SIZE; i < END_SIZE; i += STEP){
        int data[i] = {0};
        int timeResult[LOOP_TIMES] = {0};
        for (int j = 0; j < LOOP_TIMES; j++){
            timeResult[j] = test1(data, i, newData);
        }
        writeInFile(txtNames[0], timeResult, LOOP_TIMES);

        for (int j = 0; j < LOOP_TIMES; j++){
            timeResult[j] = test2(data, i, newData);
        }
        writeInFile(txtNames[1], timeResult, LOOP_TIMES);

        for (int j = 0; j < LOOP_TIMES; j++){
            timeResult[j] = test3(data, i, newData);
        }
        writeInFile(txtNames[2], timeResult, LOOP_TIMES);

    }
    return 0;
}

// struct dynamicArrayLinear()
// {   
//     int count = 0;
//     int *array = new int[START_SIZE + count*STEP + 1];
//         for (int i = 0; i < N; i+= STEP){
//             array[i] = data[i];
//         }
//         array[N] = newData;
//         return array;
//     }

// };

// int timer(int (&data)[START_SIZE + STEP*count], int numOfExperiment = 0){
//     int newdata = 1;
//     auto begin = std::chrono::steady_clock::now();  // начало отсчета
//     if (numOfExperiment == 0){
//         dynamicArrayLinear result = data;
//         result = pushRight(result, newdata);
//     }
//     auto end = std::chrono::steady_clock::now();
//     auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
//     return time_span.count();
// }
