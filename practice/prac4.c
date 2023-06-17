#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100

char* del_mo(char* str){
  char* result = (char*)malloc(sizeof(str));
  int a = 0;
  for(int i=0;str[i];i++){
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
      a++;
    }else{
      result[i-a] = str[i];
    }
  }
  return result;
}


typedef struct books_{
  int year;
  char title[10];
}books;

books* add_book(){
  books* book = (books*)malloc(sizeof(books));
  printf("책 정보 입력\n");
  printf("책 이름: \n");
  scanf("%s",book->title);
  printf("년도: \n");
  scanf("%d",&book->year);
  return book;
}

void display_books(books** book, int index){
  for(int i=0;i<index;i++){
    if(book[i]!= NULL){
      printf("%s : %d\n",book[i]->title, book[i]->year);
    }
  }
}

void del_book(books** book,int index){
  free(book[index]);
  book[index] = NULL;
}

int sum(int x, int y){
  return x+y;
}
int sub(int x, int y){
  return x+y;
}
int mul(int x,int y){
  return x+y;
}
int div(int x, int y){
  return x/y;
}


int main(){
  char* z = "hello" , result;
  int x = 2, y = 3;

  int (*cal[4])(int, int)={sum,sub,mul,div};

  //int** array = make_malloc();
  printf("%s\n\n", del_mo(z));
  
  books* shelf[MAXNUM];
  int nbooks=0;
  do{
    shelf[nbooks++] = add_book();
    printf("종료 == 'q'");
    getchar();
  }while(getchar() != 'q');
  display_books(shelf,nbooks);

  del_book(shelf, 0);

  
}