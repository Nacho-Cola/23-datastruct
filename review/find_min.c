int find_min (int *x, int size) {
  int temp = x[0];                   //p[0] == *(p + 0)
  for(int i = 1 ; size > i ; i++){
    if(temp > x[i]){
      temp = x[i];
    }
  }
  return temp;        //*p++ 공부 요망
}