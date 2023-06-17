#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#define MAXNUM 1000

//====================================================================

int str_count(char* str){
  int count = 0;
  for(;*str++;){
    count++;
  }
  return count;
}

int str_compare(char* str1, char* str2){
  for(;*str1++ && *str2++;){
    if(*str1 != *str2){
      return 0;
    }
  }
  if(*str1 && *str2){
    return 0;
  }
  return 1;
}

char* str_cat(char* str1, char* str2){
  char* memo = (char*)malloc(str_count(str1)+str_count(str2)+1);
  int i, j;
  for(i = 0; str1[i] ; i++){
    memo[i] = str1[i];
  }
  for (j = 0; str2[j] ; j++){
    memo[i+j] = str2[j];
  }
  return memo;
}

void append_ten(int* array){
  for(int i=0; i<10; i++){
    array[i] = i;
  }
}

int* make_ten(){
  int* array = (int*)malloc(10*sizeof(int));
  for(int i=0; 10>i ;i++){
    array[i] = i;
  }
  return array;
}

//====================================================================

complex add_complex(complex a, complex b){
  complex num;
  num.real = a.real + b.real;
  num.imag = a.imag + b.imag;
  return num;
}

complex mul_complex(complex a, complex b){
  complex num;
  num.real = a.real * b.real - a.imag * b.imag;
  num.imag = a.real * b.imag + a.imag * b.real;
  return num;
}

complex* add_complex_arr(complex* a){
  complex* z = (complex*)malloc(sizeof(complex));
  z->real = a->real + (a+1)->real;
  z->imag = a->imag + (a+1)->imag;
  return z;
}

complex* mul_complex_arr(complex* a){
  complex* z = (complex*)malloc(sizeof(complex));
  z->real = a->real * (a+1)->real - a->imag * (a+1)->imag;
  z->imag = a->imag * (a+1)->real + a->real * (a+1)->imag;
  return z;
}

//====================================================================

void add_book(books* book, int index){
  printf("입력");
  scanf("%s",(book+index)->title);
  scanf("%d",&(book+index)->year);
}

void display_book(books* book, int index){
  for(int i=0;i<index;i++){
    if((book+i)->year != -1){
      printf("%d번째 책", i+1);
      printf("%s : %d \n", (book+i)->title, (book+i)->year);
    }
  }
}

void del_book(books* book, int index){
  (book+index)->year = -1;
}

books* pnt_add_book(){
  books* p = (books*)malloc(sizeof(books));
  printf("입력");
  scanf("%s",p->title);
  scanf("%d",&p->year);
  return p;
}
void pnt_dispaly_book(books** book, int index){
  for(int i=0;i<index;i++){
    if(book[index] != NULL){
      printf("%d번째 책", i+1);
      printf("%s : %d",book[index]->title, book[index]->year);
    }
  }
}

void pnt_del_book(books** book, int index){
  free(book[index]);
  book[index] = NULL;
}

//====================================================================

int main(){
  char* str = "hello";
  int number[10];
  int* pnt_number;
  printf("%d \n",str_count(str));

  printf("%d\n",str_compare(str, "hello"));

  printf("%s\n",str_cat(str, "hello"));

  append_ten(number);
  for(int i=0; 10>i ; i++){
    printf("%d",number[i]);
  }

  pnt_number = make_ten();
  for(int i=0; 10>i ; i++){
    printf("%d",pnt_number[i]);
  }

  //====================================================================

  complex a, b;
  a.real = 0.7, a.imag = 1.5, b.real = 0.5, b.imag = 7.7;
  printf("\n%f %f\n",add_complex(a,b).real ,add_complex(a,b).imag); 

  printf("%f %f\n",mul_complex(a,b).real ,mul_complex(a,b).imag); 

  complex x[2];
  complex* p;
  x[0].real = 0.7, x[0].imag = 1.5, x[1].real = 0.5, x[1].imag = 7.7; 
  p=add_complex_arr(x);
  printf("%f %f\n",p->real, p->imag);
  p=mul_complex_arr(x);
  printf("%f %f\n",p->real, p->imag);

  //====================================================================

  books shelf[MAXNUM];
  int index = 0;
  add_book(shelf, index++);
  display_book(shelf, index);
  del_book(shelf, 0);

  books* p_shelf[MAXNUM];
  int p_index = 0;
  p_shelf[p_index++] = pnt_add_book();
  pnt_dispaly_book(p_shelf,p_index);
  pnt_del_book(p_shelf,0);
}