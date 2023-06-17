int calculate_length( char *str ){
  int len = 0;
  for(;*str++;){
    len++;
  }
  return len;
}