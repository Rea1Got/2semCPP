int* take_N_elements(int* ptr){
  delete[] ptr;
  ptr = nullptr;
  return ptr;
}
