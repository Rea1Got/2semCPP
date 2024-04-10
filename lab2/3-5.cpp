#include <iostream>
#include <chrono>
#include <fstream>
#include <istream>

#define END_SIZE 10000
#define LOOP_TIMES 4  
#define STEP 100
#define MULTIPLY 2

struct DynamicArray {
    int* data = nullptr;
    int sizeFilled = 0;
    int size = 0;
};

void clear(DynamicArray& array){
    delete[] array.data;
    array.size = 0;
    array.sizeFilled = 0;
    array.data = nullptr;
}

auto timerStart() {
    return std::chrono::steady_clock::now();
}

int timerStop(std::chrono::_V2::steady_clock::time_point  begin) {
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    return static_cast<int>(time_span.count());
}

void writeInFile(const std::string& filename, int* result, int size){
    std::ofstream fout(filename, std::ios::app);
    for (int i = 0; i < size; i++){
        fout << result[i] << ' ';
    }
    fout << '\n';
    fout.close();
}

DynamicArray pushRight(const DynamicArray& data, int newData) {
    DynamicArray result;
    result.size = data.size + 1;
    result.sizeFilled = data.sizeFilled + 1;
    result.data = new int[result.size];
    for (int i = 0; i < data.sizeFilled; i++) {
        result.data[i] = data.data[i];
    }
//    result.data[data.sizeFilled] = newData;
    return result;
}

DynamicArray pushRightStep(DynamicArray data, int step, int newData) {
    DynamicArray result;
    result.size = data.size + step;
    result.sizeFilled = data.sizeFilled;
    result.data = new int[result.size];
    for (int i = 0; i < result.sizeFilled; i++) {
        result.data[i] = data.data[i];
    }
    return result;
}

DynamicArray pushRightMultiply(const DynamicArray& data, int multiply, int newData) {
    DynamicArray result;
    result.size = data.size * multiply;
    result.sizeFilled = data.sizeFilled;
    result.data = new int[result.size];
    for (int i = 1; i < result.sizeFilled; i++) {
        result.data[i-1] = data.data[i-1];
    }
    return result;
}

int* test1(DynamicArray& array, int newData){
    int *result = new int[END_SIZE];
    for (int i = 0; i < END_SIZE; i++){
        auto ts = timerStart();
        if (array.size == array.sizeFilled){
            array = pushRight(array, newData);
        }
        array.data[i] = newData;
        result[i] = timerStop(ts);
    }
    return result;
}

int* test2(DynamicArray& array, int step, int newData){
    int *result = new int[END_SIZE];
    for (int i = 0; i < END_SIZE; i++){
        if (array.size == array.sizeFilled){
            auto ts = timerStart();
            array = pushRightStep(array, step, newData);
            result[i] = timerStop(ts);
        } else {
            auto ts = timerStart();
            array.data[i] = newData;
            result[i] = timerStop(ts);
        }
        array.sizeFilled++;
    }
    return result;
}

int* test3(DynamicArray& array, int step, int newData){
    int *result = new int[END_SIZE];
    array.size = 1;
    array.sizeFilled = 1;
    for (int i = 0; i < END_SIZE; i++){
        auto ts = timerStart();
        if (array.size == array.sizeFilled){
            array = pushRightMultiply(array, MULTIPLY, newData);
            array.data[i] = newData;
            // std::cout << array.size << ' ';
        } 
        array.data[i] = newData;
        array.sizeFilled++;
        result[i] = timerStop(ts);
    }
    return result;
}

// int readConfig(){
//     int config[4] = {0};
//     std::string _config[4];
//     std::ifstream MyReadFile("config.txt");
//     int i = 0;
//     while (std::getline(MyReadFile, _config[i])) {
//         config[i] = std::__cxx11::stoi(_config[i]);
//         i++;
//     }
//     MyReadFile.close();
//     return config;
// }

int main(){
    setlocale(LC_ALL, "Russian");
    std::string txtNames[] = { "3-5_firstTest.txt", "3-5_secondTest.txt", "3-5_thirdTest.txt" };

    int config[4] = {0};
    std::string _config[4];
    std::ifstream MyReadFile("config.txt");
    int i = 0;
    while (std::getline(MyReadFile, _config[i])) {
        config[i] = std::__cxx11::stoi(_config[i]);
        i++;
    }
    MyReadFile.close();

    DynamicArray array;
    array.size = 0;
    array.sizeFilled = 0;

    int newData = 1337;
    for (int i = 0; i < config[1]; i++){
        writeInFile(txtNames[0], test1(array, newData), config[0]);
        clear(array);

        writeInFile(txtNames[1], test2(array, config[2], newData), config[0]);
        clear(array);

        writeInFile(txtNames[2], test3(array, config[3], newData), config[0]);
        clear(array);
    }
    system("python graph3-5.py");
    return 0;
}
