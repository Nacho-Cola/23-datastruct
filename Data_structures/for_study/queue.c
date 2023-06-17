#include <stdio.h>
#include <stdlib.h>
#include "../linked_list_API/list.h"
#include "../linked_list_API/list.c"

typedef struct Data_
{
  int id;
  char *name;
}Data;


typedef struct Queue_
{
  int head,tail,size;
  Data **Queue;
}Queue;

int init(Queue* queue, int size){
  queue->size = size + 1;
  queue->tail = queue->head = 0;
  queue->Queue = (Data**)malloc(sizeof(Data*) * queue->size);
  return 0;
}


int enQueue(Queue* que, Data* data){
  if((que->head)%que->size == (que->tail+1)%que->size ){
    return 0;
  }
  que->Queue[((que->tail)++)] = data ;
  que->tail %= que->size;
  return 1;
}

int deQueue(Queue* que,Data** data){
  if(que->head == que->tail ){
    return 0;
  }
  *data = que->Queue[(que->head)++] ;
  que->head %= que->size;
  return 1;
}

int main(){
  Queue Q;
  init(&Q, 4);
  Data* ret; 

  Data test;  test.id = 10; test.name = "4.5";
  Data test1; test1.id = 11;test1.name = "4";
  Data test2; test2.id = 12;test2.name = "3.5";
  Data test3; test3.id = 13;test3.name = "3";
  Data test4; test4.id = 14;test4.name = "2.5";

  enQueue(&Q, &test);
  enQueue(&Q, &test1);
  enQueue(&Q, &test2);
  enQueue(&Q, &test3);
  enQueue(&Q, &test4);


  if(deQueue(&Q, &ret))
    printf("%d %s\n", ret->id, ret->name);
  if(deQueue(&Q, &ret))
    printf("%d %s\n", ret->id, ret->name);
  if(deQueue(&Q, &ret))
    printf("%d %s\n", ret->id, ret->name);
  if(deQueue(&Q, &ret))
    printf("%d %s\n", ret->id, ret->name);
  if(deQueue(&Q, &ret))
    printf("%d %s\n", ret->id, ret->name);
  if(deQueue(&Q, &ret))
    printf("%d %s\n", ret->id, ret->name);

}