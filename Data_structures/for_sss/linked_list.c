#include <stdio.h>
#include <stdlib.h>
#include "../linked_list_API/list.h"
#include "../linked_list_API/list.c"


void display_list(List* list){
  ListElmt *p;
  for(p = list->head; p!=NULL ; p=p->next){
    printf("%s \n",((char*)p->data));
  }
}

int main(){

  List ls;
  list_init(&ls,NULL);
  char* str[10] = {"hello","Bye","what","Mmm?"};
  list_ins_next(&ls,ls.tail,str[0]);
  list_ins_next(&ls,ls.tail,str[1]);
  list_ins_next(&ls,ls.tail,str[2]);
  list_ins_next(&ls,ls.tail,str[3]);

  display_list(&ls);

}
