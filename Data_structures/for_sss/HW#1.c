#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../linked_list_API/list.h"
#include "../linked_list_API/list.c"

typedef struct Device_{
  char name[20];
  int id;
  char con[20];
}Device;

void display(List*list){
  ListElmt* p;
  for(p=list->head ; p!=NULL ; p=p->next){
    printf("%s %d %s \n",((Device*)p->data)->name,((Device*)p->data)->id,((Device*)p->data)->con);
  }
}

int list_sorted_insert(List* list, Device* data){
  ListElmt  *p;

  if(list_size(list) == 0){
    list_ins_next(list, NULL, (Device*)data);
    return 0;
  }

  if(list->size == 1){
    if(strcmp(((Device*)list->head->data)->name,data->name)<0){
      list_ins_next(list,list->tail,data);
      return 0;
    }
  }

  if(strcmp(((Device*)list->head->data)->name, data->name) > 0){
    list_ins_next(list, NULL, data);
    return 0;
  }

  for(p=list->head; p!=list->tail ; p=p->next){
    
    if(strcmp(((Device*)p->next->data)->name, data->name) > 0){
      list_ins_next(list,p,data);
      return 0;
    }
  }

  list_ins_next(list,list->tail,data);
  return 0;
}


int main(){
  FILE* fp;
  List ls;
  list_init(&ls,NULL);
  
  fp = fopen("devices.txt","r");
  while(1){
    Device* dic = (Device*)malloc(sizeof(Device));
    fscanf(fp,"%s %d %s", dic->name, &dic->id, dic->con); 
    if(!feof(fp)){
      list_sorted_insert(&ls, dic);
    }else{
      break;
    }
  }

  display(&ls);
  fclose(fp);
}