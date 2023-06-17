#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../linked_list_API/dlist.h"
#include "../linked_list_API/dlist.c"

typedef struct Device_{
  char name[20];
  int id;
  char con[20];
}Device;

void display(DList*list){
  DListElmt* p;
  for(p=list->head ; p!=NULL ; p=p->next){
    printf("%s %d %s \n",((Device*)p->data)->name,((Device*)p->data)->id,((Device*)p->data)->con);
  }
}

int dlist_sorted_insert(DList* list, Device* data){
  DListElmt* p;

  if(dlist_size(list) == 0){
    dlist_ins_next(list, NULL, (Device*)data);
    return 0;
  }

  if(strcmp(((Device*)list->head->data)->name, data->name) > 0){
    dlist_ins_prev(list,list->head, (Device*)data);
    return 0;
  }

  for(p= list->head; p!=list->tail ; p=p->next){
    if(strcmp(((Device*)p->next->data)->name, data->name) > 0){
      dlist_ins_next(list,p,(Device*)data);
      return 0;
    }
  }
  dlist_ins_next(list,list->tail,(Device*)data);
}

int main(){
  FILE* fp;
  DList ls;
  dlist_init(&ls,NULL);
  
  fp = fopen("devices.txt","r");
  while(1){
    Device* dic = (Device*)malloc(sizeof(Device));
    fscanf(fp,"%s %d %s", dic->name, &dic->id, dic->con); 
    if(!feof(fp)){
      dlist_sorted_insert(&ls, dic);
    }else{
      break;
    }
  }

  display(&ls);
  fclose(fp);
}