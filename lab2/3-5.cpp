#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include <string>

#define START_SIZE 10000
#define END_SIZE 1000000
#define STEP 10000
#define LOOP_TIMES 100
#define NEW_ELEMENT 1337
#define NUM_OF_NEW_ELEMENTS 100

int* copyArray(int data[], int sizeData, int result[]) {
    for (int i = 0; i < sizeData; i++) {
        result[i] = data[i];
    }
    return result;
}

int* biggerArray(int data[], int sizeData, int quantityOfNewElements){
    int *result = new int[sizeData + quantityOfNewElements];
    return copyArray(data, sizeData, result);
}

void fillNewElements(int result[], int sizeData, int quantityOfNewElements){
    for(int i = sizeData; i < sizeData + quantityOfNewElements; i++){
        result[i] = NEW_ELEMENT;
    }
}

auto timerStart() {
    return std::chrono::steady_clock::now();
}

int timerStop(auto begin) {
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    return static_cast<int>(time_span.count());
}

auto test1(int data[], int size, int quantityOfNewElements) {
    auto ts = timerStart();
    int* newArray = biggerArray(data, size, quantityOfNewElements);
    fillNewElements(newArray, size, quantityOfNewElements);
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
    std::string txtNames[] = { "3-5_firstTest.txt", "3-5_secondTest.txt", "3-5_thirdTest.txt" };

    for (int k = 0; k < 3; k++){
        for (int i = START_SIZE; i < END_SIZE; i += STEP){
            int *data = new int[i]();
            int timeResult[LOOP_TIMES] = {0};
            if (k % 3 == 0){
                for (int j = 0; j < LOOP_TIMES; j++){
                    timeResult[j] = test1(data, i, 1);
                }
            } else if (k % 3 == 1){
                for (int j = 0; j < LOOP_TIMES; j++){
                    timeResult[j] = test1(data, i, NUM_OF_NEW_ELEMENTS);
                }  
            } else {
                for (int j = 0; j < LOOP_TIMES; j++){
                    timeResult[j] = test1(data, i, i);
                }  
            }
            writeInFile(txtNames[k], timeResult, LOOP_TIMES);

            delete[] data;
        }
    }
    return 0;
}