int* give_N_elements(unsigned int N, int value){
  int* arr = new int[N];
  for (unsigned int i = 0; i < N; i++) {
     arr[i] = value;
  }
  return arr;
}
