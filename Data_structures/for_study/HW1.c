#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../linked_list_API/list.h"
#include "../linked_list_API/list.c"

typedef struct device_
{
  char device_name[30];
  int id;
  char place[30];
} device;

int list_sorted_insert(List *list, device *data){
  ListElmt* p ;

  if(list->head == NULL){
    list_ins_next(list,NULL,data);
    return 0;
  }
  if(list->size == 1){
    if(strcmp(((device*)list->head->data)->device_name,data->device_name)<0){
      list_ins_next(list,list->tail,data);
      return 0;
    }

  }
  if(strcmp(((device*)list->head->data)->device_name,data->device_name)>0){
      list_ins_next(list,NULL,data);
      return 0;
  }
  for(p = list->head; p!= list->tail ; p = p->next){
    if(strcmp(((device*)p->next->data)->device_name,data->device_name)>0){
      list_ins_next(list,p,data);
      return 0;
    }
  }
  list_ins_next(list,list->tail,data);
  return 0;
}

void insert_device_file(List *list, FILE *fp)
{

  for (int i = 0; i < 10; i++)
  {
    device *table = (device *)malloc(sizeof(device));
    if (fscanf(fp, "%s %d %s\n", table->device_name, &table->id, table->place) != EOF)
      {
        list_sorted_insert(list, (device *)table);
      }
  }
}

void display_device(List *list)
{
  ListElmt *p;
  for (p = list->head; p != NULL; p = p->next)
  {
    printf("%s %d %s \n", ((device*)p->data)->device_name, ((device*)p->data)->id,((device*)p->data)->place);
  }
}


int main(){
  List resource;
  list_init(&resource, NULL);
  FILE *fp;
  if ((fp = fopen("devices.txt", "r")) == NULL)
  {
    printf("cannot open file\n");
    exit(0);
  }
  insert_device_file(&resource, fp);
  fclose(fp);
  display_device(&resource);
}

