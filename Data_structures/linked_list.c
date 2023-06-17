#include <stdio.h>
#include <stdlib.h>
#include "linked_list_API/list.h"
#include "linked_list_API/list.c"

void display_list(List* list){
  ListElmt* p;
  for( p = list->head ; p != NULL ; p = p->next ){
    printf("%s \n",(char*)p->data);
  }
}

int main(){
  List a;
  char* d[3]={"test", "exam", "student"};

  list_init(&a, NULL);
  list_ins_next(&a,a.tail,d[0]); //첫 tail의 값은 NULL
  list_ins_next(&a,a.tail,d[1]);
  list_ins_next(&a,a.tail,d[2]);

  display_list(&a);
}
