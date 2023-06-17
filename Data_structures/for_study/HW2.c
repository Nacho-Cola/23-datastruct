#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../linked_list_API/dlist.h"
#include "../linked_list_API/dlist.c"

typedef struct device_
{
  char device_name[30];
  int id;
  char place[30];
} device;

void insert_device_file(DList *list, FILE *fp)
{

  for (int i = 0; i < 10; i++)
  {
    device *table = (device *)malloc(sizeof(device));
    if (fscanf(fp, "%s %d %s\n", table->device_name, &table->id, table->place) != EOF)
      {
        dlist_ins_next(list, dlist_tail(list), (device *)table);
      }
  }
}

void display_device(DList *list)
{
  DListElmt *p;
  for (p = list->head; p != NULL; p = p->next)
  {
    printf("%s %d %s \n", ((device*)p->data)->device_name, ((device*)p->data)->id,((device*)p->data)->place);
  }
}

void remove_duplicate_device(DList *list){
  DListElmt *p, *temp;
  device *d;
  for (p = list->head; p != NULL; p = p->next)
  {
    for(temp=p->next; temp!=NULL; temp = temp->next ){
      if(strcmp(((device*)p->data)->place, ((device*)temp->data)->place)==0){
        dlist_remove(list,temp,(device**)&d);
      }
    }
  }
}

int main(){
  DList resource;
  dlist_init(&resource, NULL);
  FILE *fp;
  if ((fp = fopen("devices.txt", "r")) == NULL)
  {
    printf("cannot open file\n");
    exit(0);
  }
  insert_device_file(&resource, fp);
  fclose(fp);
  display_device(&resource);
  remove_duplicate_device(&resource);
  printf("=========================\n");
  display_device(&resource);
}