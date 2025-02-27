void merge(int*& res, int*& ptr0, unsigned int N, int*& ptr1, unsigned int M){
  if (res == nullptr){
    res = new int[N + M];
  }
  
  for (int i = 0; i < N; i++){
    res[i] = ptr0[i];
  }
  for (int i = 0; i < M; i++){
    res[i + N] = ptr1[i];
  }
}
