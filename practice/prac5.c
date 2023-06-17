#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct books_{
  char title[20];
  int year;
}books;


/*
void add_book(books* shelf, int index){
  printf("%d 번째 책 입력\n",index+1);
  printf("제목 입력: ");
  scanf("%s",(shelf+index)->title);
  printf("연도 입력: ");
  scanf("%d",&(shelf+index)->year);
}

void dis_books(books* shelf, int index){
  printf("%10s %10s\n", "제목","연도");
  for(int i=0;i<index;i++){
    if(shelf[i].year != -1){
      printf("%10s %10d\n", shelf[i].title, shelf[i].year);
    }
  }
}

void del_book(books* shelf , int index){
  shelf[index].year = -1;
}
*/

books* add_book(){
  books* book = (books*)malloc(sizeof(books));
  printf("======책 입력 시작======\n");
  printf("제목: \n");
  scanf("%s",book->title);
  printf("연도: \n");
  scanf("%d",&book->year);
  return book;
}

void dis_books(books** book, int index){
  printf("%5s %5s\n","제목","연도");
  for(int i=0; i<index; i++){
    if(book[i] != NULL){
      printf("%5s %5d\n",book[i]->title, book[i]->year);
    }
  }
}

void del_book(books** book, int index){
  free(book[index]);
  book[index] = NULL;
}

int main(){
  books *shelf[MAX];
  int nbooks = 0;
  do{
    shelf[nbooks++] = add_book();
    printf("press 'q' to exit.\n");
    getchar();
  }while(getchar() != 'q');

  dis_books(shelf, nbooks);
  del_book(shelf, 0);
  dis_books(shelf, nbooks);



  /*
  books shelf[MAX];
  int index = 0;
  do{
    add_book(shelf, index++);
    printf("press 'q' to exit.\n");
    getchar();
  }while(getchar() != 'q');

  dis_books(shelf, index);
  del_book(shelf, 0);
  dis_books(shelf, index);
  */

}