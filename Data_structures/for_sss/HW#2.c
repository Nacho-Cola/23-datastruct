#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../linked_list_API/dlist.h"
#include "../linked_list_API/dlist.c"

typedef struct Data_{
  char name[20];
  int id;
  char com[20];
}Data;

void display(DList* list){
  DListElmt *p;
  for(p=list->head; p!=NULL; p=p->next){
    printf("%s %d %s\n",((Data*)p->data)->name,((Data*)p->data)->id,((Data*)p->data)->com);
  }
}

remove_duplicate_device(DList* list){
  DListElmt *p,*temp;
  Data * b;
  for(p=list->head ; p!=NULL ; p=p->next){
    for(temp = p->next; temp != NULL ; temp = temp->next){
      if(((Data*)p->data)->com == ((Data*)temp->data)->com){
        dlist_remove(&list,temp,(Data**)&b);
      }
    }
  }
}

int main(){
  FILE* fp;
  DList ls;
  Data* data;
  dlist_init(&ls,NULL);
  fp = fopen("devices.txt","r");
  while(!feof(fp)){
    data = (Data*)malloc(sizeof(Data));
    fscanf(fp,"%s %d %s",data->name,&data->id,data->com);
    dlist_ins_next(&ls,ls.tail,data);
  }
  display(&ls);
  remove_duplicate_device(&ls);
  printf("+++++++++++++++");
  display(&ls);


}