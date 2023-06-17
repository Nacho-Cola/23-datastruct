#include <stdio.h>
#include <stdlib.h>
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


int main(){
  FILE* fp;
  List ls;
  list_init(&ls,NULL);
  
  fp = fopen("devices.txt","r");
  while(1){
    Device* dic = (Device*)malloc(sizeof(Device));
    fscanf(fp,"%s %d %s", dic->name, &dic->id, dic->con); 
    if(!feof(fp)){
      list_ins_next(&ls,ls.tail,dic);
    }else{
      break;
    }
  }

  display(&ls);
  fclose(fp);
}