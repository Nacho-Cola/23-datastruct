#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverse_string(char* str){
  int len = strlen(str);
  char* re_str = (char*)malloc(len+1);
  for(int i = 0; str[i]; i++){
    re_str[i] = str[len -1 - i];
  }
  re_str[len] = '\0';
  return re_str;
}

int main(){
  char str[10];
  printf("Enter a string: ");
  scanf("%[^\n]",str);
  printf("Reverse string: %s",reverse_string(str));
}