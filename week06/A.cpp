#include <string>
#include <iostream>

struct Student
{
  std::string name;
  int mark;
};

void writeStudent(Student*& student_array, int len_array){
  for(int i = 0; i < len_array; i++){
    std::cin >> student_array[i].name >> student_array[i].mark;
  }
}

// void printStudent(Student*& student_array, int len_array){
//   for(int i = 0; i < len_array; i++){
//     std::cout << student_array[i].name << " " << student_array[i].mark << std::endl;
//   }
// }

void sortByMark(Student*& student_array, int len_array){
  for(int i = 0; i < len_array - 1; i++){
    for (int j = i + 1; j < len_array; j++){
      if(student_array[i].mark > student_array[j].mark){
        std::swap(student_array[i], student_array[j]);
      }
    }
  }
}

void sortByName(Student*& student_array, int len_array){
  for(int i = 0; i < len_array - 1; i++){
    for (int j = i + 1; j < len_array; j++){
      if((student_array[i].mark == student_array[j].mark) and (student_array[i].name > student_array[j].name)){
        std::swap(student_array[i], student_array[j]);
      }
    }
  }

}

int main(){
  int n, m = 0;
  std::cin >> n >> m;
  Student* student_array = new Student[n];
  writeStudent(student_array, n);
  sortByMark(student_array, n);
  sortByName(student_array, n);
  for(int i = 0; i < n; i++){
    if (student_array[i].mark >= m){
      std::cout << student_array[i].name << " ";
    }
  }
  std::cout << std::endl;
  // printStudent(student_array, n);
  delete[] student_array;
  return 0;
}
