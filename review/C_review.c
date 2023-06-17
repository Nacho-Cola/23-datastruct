#include <stdio.h>
#include <stdlib.h>
#include "swap.c"
#include "find_min.c"
#include "calculate_length.c"
#include "string_compare.c"
#include "str_cat.c"
#include "header/defs.h"

#define NUM_BOOKS 1000



/*
book* add_book(){
  book* t = (book*)malloc(sizeof(book)); //동적할당
  printf("제목 입력: ");
  scanf("%s", (t)->title); //책제목
  printf("연도 입력: ");
  scanf("%d", &(t)->year);  //연도

  return t;
}

void display_book(book** p, int index){ //포인터 배열의 접근하는 함수의 인덱스는 이중 포인터
    
  int k;
  for(k=0; k < index ; k++){    //수업
    if(p[k] != NULL){
      printf("%s : %d \n", p[k]->title, p[k]->year );
    }
    printf("========출력완료======== \n");
  }
    
}

void delete_book(book** p, int index){
  free(p[index]);
  p[index] = NULL;
}

  int main(){
    book *shelf[NUM_BOOKS]; //포인터 배열은 동적 할당을 필요로 함
    int nbooks = 0;

    do{
      shelf[nbooks++] = add_book(); //동적할당 주소를 포인터 배열로 받는다.
      printf("마치려면'p'입력");
      getchar();
    }while(getchar() != 'q');

    display_book(shelf, nbooks);
    delete_book(shelf, 0);         //동적 할당은 삭제가 간편하다. 메모리 사용에 용이하다.
    display_book(shelf, nbooks);
    if(getchar() == 'w'){} // 파일 save load
  }
  //do while 문 사용해보기 
  //file 저장 및 입력받기
  */






/*
_______________________________________________
  void add_book(book* p, int num){
    printf("제목 입력: ");
    scanf("%s", (p+num)->title); //책제목
    printf("연도 입력: ");
    scanf("%d", &(p+num)->year);  //연도
  }

  void display_book(book* p, int index){
    
    for(;index>0;index--){  //내가 만든거
      printf("%d 번쨰 책\n",index);
      printf("%s\n",(p+(index-1))->title);
      printf("%d\n",(p+(index-1))->year);
    }
    
    
    int k;
    for(k=0; k < index ; k++){    //수업
      if((p+k)->year != -1){
        printf("%s : %d \n", (p+k)->title, (p+k)->year );
      }
    }
    
  }

  void delete_book(book* p, int index){
    strcpy((p+index)->title, "");
    (p+index)->year = -1;
  }

  int main(){
    book shelf[NUM_BOOKS];
    int nbooks = 0;

    do{
      add_book(shelf,nbooks++); // 책한권 정보을 입력받아 저장, 몇번째 정보인지 (첫번째)
      printf("마치려면'p'입력");
      getchar();
    }while(getchar() != 'q');

    display_book(shelf, nbooks);
    delete_book(shelf, 0);
    display_book(shelf, nbooks);

    if(getchar() == 'w'){} // 파일 save load
  }
  //do while 문 사용해보기 
  //file 저장 및 입력받기

*/






/*
___________________________________________

complex add(complex *p){
  complex c;
  c.real = p->real + (p+1)->real;
  c.imag = p->imag + (p+1)->imag;
  return c;
}

int main(){
  complex x[2]; //복소수 자료형 배열 (구조체 배열)
  complex z;
  x[0].real = 0; x[0].imag = -1;
  x[1].real = -1; x[1].imag = 9;
  z = add(x);
  printf("%.2f %.2f",z.real, z.imag);
 }
*/










/*

_____________________________________________________
complex add_complex(complex x, complex y) {
  complex z;
  z.real = x.real + y.real;
  z.imag = x.imag + y.imag;
  return z;
}

complex mul_complex(complex x, complex y) {
  complex z;
  z.real = x.real + y.real;
  z.imag = x.imag + y.imag;
  return z;
}

int main(){
  complex a, b, c;  // defs.h에 구조체 정의
  a.real = 1.0;a.imag = -0.56;
  b.real = -0.45;b.imag = 1.54;
  
  c = add_complex(a, b);
  printf("%.2f %.2f \n",c.real,c.imag);
  //mul_complex(a, b);

}
*/











/*
___________________________________________

int* my_func(){  //주소를 리턴 (포인트)

  int* p;                                // 지역변수가 아닌 윈도우에 요청해서 받아온 주소
  //p = malloc(10*sizeof(int));          //동적할당함수 malloc(필요한 크기를 인자로 넘겨준다) 시작 주소를 받아온다.
  p = (int *)malloc(10 * sizeof(int));

  for(int i = 0; i < 10; i++){
    p[i] = i ;
  }
  return p; //동적할당된 공간은 프로그램이 종료될 때까지 살아있다. 
}

int main()  // main 함수의 지역변수는 프로그램이 끝날 떄 삭제된다.
{
  int* data ; //받아오는 값: 주소 (포인터)
  data = my_func();

  for(int i=0; i < 10; i++){
    printf("%d",data[i]);
  }
*/









/*  
___________________________________________

함수에서 주소값 return, 지역변수 문제 
int* my_func(){  //주소를 리턴 (포인트)

  int data[10];  // 이런식으로 선언하면 안됨
  for(int i = 0; i < 10; i++){
    data[i] = i ;
  }
  return data;
}

int main()  // main 함수의 지역변수는 프로그램이 끝날 떄 삭제된다.
{
  int* data ; //받아오는 값: 주소 (포인터)
  data = my_func();

  for(int i=0; i < 10; i++){
    printf("%d",data[i]);
  }
*/



/*

___________________________________________

//기초 포인터 실습////////////////////
int my_func(int* x, int y){
  for(int i = 0; i < y; i++){
    x[i] = i ;
  };
}

int main()
{
  int data[10];

  my_func(data, 10);

  for(int i=0; i < 10; i++){
    printf("%d",data[i]);
  }
  */

  /*

  ___________________________________________

  //이중 포인터 : 포인터의 주소를 저장할 때 사용한다.
  //func포인터 : 함수의 주소를 pointing 하는 포인터.
  int (*f)(int);
  int **(*p[10])(int*,int);  //배열, 포인터, 인자를 두개 받는 함수, 배열 내용: 이중 포인터

  // char형 pointer 합치기
  int length;
  char *s1 = "data";
  char *s2 = "data2";
  printf("%s\n",str_cat(s1, s2));
  */


  /*

  ___________________________________________

  if(string_compare(s1, s2)){
    printf("different");
  } else {
    printf("same")
  }
  */


  /* 

  ___________________________________________

  //문자열 길이를 반환하는 함수
  int len, len_word;
  char *str = "data structure and algorithms";

  len = calculate_length(str);
  len_word = calculate_length("str");   // 문자열을 넘겨주는 것 = 문자열의 시작 주소를 넘기는 것과 같다. ( "" = cahr형 포인터)
  printf("length is %d %d\n",len,len_word);
 */ 

  /*

  __________________________________________

  //char str[] = {'d', 'a', 't', 'a' };
  char *str = "data structure and algorithms"; // (5byte) 마지막을 알리는 NULL 1byte가 추가된다.

  printf("%p\n", str); // %p pointer 주소 형태로 출력
  printf("%c\n", *str);

  for(int i = 0; i < 4; i++){
    printf("%c",*str++);    //str의 가리키는 주소를 변경
  }

  for(;*str++;){
    printf("%c",*str);
  }

  int data[10], min;
  min = find_min(data, sizeof(data));
  printf("\n %d",min);
  
}

*/

