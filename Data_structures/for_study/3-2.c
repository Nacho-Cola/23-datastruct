#include <stdio.h>
#include <stdlib.h>
#include "../linked_list_API/list.h"
#include "../linked_list_API/list.c"

typedef struct device_
{
  char device_name[30];
  int id;
  char place[30];
} device;

void insert_device_file(List *list, FILE *fp)
{

  for (int i = 0; i < 10; i++)
  {
    device *table = (device *)malloc(sizeof(device));
    if (fscanf(fp, "%s %d %s\n", table->device_name, &table->id, table->place) != EOF)
      {
        list_ins_next(list, list_tail(list), (device *)table);
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

int main()
{
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