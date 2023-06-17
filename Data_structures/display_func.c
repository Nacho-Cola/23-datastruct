#include <stdio.h>
#include <stdlib.h>
#include "linked_list_API/list.h"
#include "linked_list_API/list.c"

char* make_data(){
  char* data = (char*)malloc(100);
  scanf("%s",data);
  return data; 
}

void fill_list(List *list){
  int size;
  printf("list에 추가할 elements 갯수: ");
  scanf("%d", &size);
  for(int i=0; i<size; i++){
    printf("%5d 번쨰 elements 입력: ",i+1);
     list_ins_next(list,list->tail,make_data());
  }
}

void display_list(List *list){
  
  ListElmt* temp = list->head;
  printf("%5s  %20s\n","Index","Data");
  for(int i=0 ; i<list->size ; i++){
    printf("%5d %20s \n",i+1,(char*)list->head->data);
    list->head = list->head->next;
  }
  list->head = temp;
}

int main(){
  List new;
  list_init(&new,NULL);
  fill_list(&new);
  display_list(&new);

}
