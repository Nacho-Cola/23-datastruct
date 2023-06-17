#include <stdio.h>
#include<stdlib.h>
#include "defs.h"  //6

int str_length(char *str){
  int count = 0;
  for(;*str++;){
    count++;
  }
  return count;
}

int str_compare(char *str1, char* str2){
  for(;(*str1++)&&(str2++);){
    if (*str1 != *str2){
      return 0;
    }
  }
  if(*str1 && *str2){
    return 0;
  }
  return 1;
}

char* str_cat(char* str1, char* str2){
  char* cat = (char*)malloc(str_length(str1)+str_length(str2)+1);
  int i,k;
  for(i = 0;str1[i];i++){
    cat[i] = str1[i];
  }
  for(k = 0;str2[k];k++){
    cat[i+k] = str2[k];
  }
  cat[i+k] = '\0';
  return cat;
}

void get_10array(int* array, int size){
  for(int i=0; size>i; i++){
    array[i] = i;
  }
}

int* make_10array(){
  int* array = (int*)malloc(10*sizeof(int));
  for(int i = 0;10>i; i++){
    array[i] = i;
  }
  return array;
}

complex add_complex(complex x, complex y){
  complex result;
  result.real = x.real + y.real;
  result.imag = x.imag + y.imag;
  return result;
}

complex mul_complex(complex x, complex y){
  complex result;
  result.real = x.real*y.real - x.imag*y.imag;
  result.imag = x.real*y.imag +x.imag*y.real;
  return result;
}

complex add_array_complex(complex* x){
  complex result;
  result.real = x->real + (x+1)->real;
  result.imag = x->imag + (x+1)->imag;
  return result;
}

complex mul_array_complex(complex* x){
  complex result;
  result.real = x->real * (x+1)->real - x->imag * (x+1)->imag;
  result.imag = x->real * (x+1)->imag + (x+1)->real * x->imag;
  return result;
}


//================= main ==============


int main() {
  int length, compare; //1,2
  char *str = "hello";
  char *str2 = "wellcom"; 
  int array[10];
  int* result;


  length = str_length(str);
  compare = str_compare(str, str2);
  printf("%d, %d \n",length, compare);
  printf("%s \n",str_cat(str, str2));  //3

  get_10array(array, 10);      //4
  for(int i = 0 ; 10>i ; i++){
    printf("%d", array[i]);
  }printf("\n");

  result = make_10array();    //5
  for(int i = 0; 10>i ; i++){
    printf("%d",result[i]);
  }printf("\n");

  //======================= structure ============

  complex a, b, add_result, mul_result; // 7, 8
  a.imag = -7;b.imag = 0.5;
  a.real = 6.5;b.real = 4.8;

  add_result = add_complex(a, b);
  printf("%.2f %.2f\n",add_result.real, add_result.imag);

  mul_result = mul_complex(a,b);
  printf("%.2f %.2f\n",mul_result.real, mul_result.imag);

  complex coms[2], complex_add_result, complex_mul_result;    // 9, 10
  coms[0].real = 6.5;coms[0].imag = -7;
  coms[1].real = 4.8;coms[1].imag = 0.5;
  complex_add_result = add_array_complex(coms);
  printf("%.2f %.2f\n",complex_add_result.real, complex_add_result.imag);   
  complex_mul_result = mul_array_complex(coms);
  printf("%.2f %.2f\n",complex_mul_result.real, complex_mul_result.imag);   
  

}