#include <string.h>

char *str_cat (char*s, char*y) {
  //새로운 공간이 핑요함. 동적할당으로 main 함수에서도 사용할 수 있다.
  char* p = (char*)malloc(strlen(s) + strlen(y) + 1); // 동적할당
  int k;
  int m;
  for(k = 0; s[k] != '\0';k++){
    p[k] = s[k];
  }
  for(m = 0; y[m] != '\0';m++){
    p[k+m] = y[m];
  }
  p[k+m]='\0';

  return p;
}