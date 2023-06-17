#include <stdlib.h>
#include <stdio.h>

typedef struct Data_{
  int id;
  double score;
}Data;


typedef struct Queue_{
  Data **queue;   
  int head,tail,Qsize;        
}Queue;

void init (Queue *q, int q_size){
  q->Qsize = q_size;
  q->head = q->tail = 0;
  q->queue = (Data**)malloc(sizeof(Data*)*q_size);
}

int enqueue_Queue(Queue *q, Data *data)
{
  if( q->head % (q->Qsize) == (q->tail+1) % (q->Qsize) ){
    return 0;
  }
  q->queue[(q->tail)++] = data; 
  q->tail %= q->Qsize;

  return 1;
}
int dequeue_Queue(Queue *q, Data **data) 
{
  if(q->head == q->tail){
    return 0;
  }
  *data = q->queue[(q->head)++];
  q->head %= q->Qsize;

  return 1;
}

int main(){
  Queue que;
  init(&que, 4);
  Data test; test.id = 10;test.score = 4.5;
  Data test1; test1.id = 11;test1.score = 4;
  Data test2; test2.id = 12;test2.score = 3.5;
  Data test3; test3.id = 13;test3.score = 3;
  Data test4; test4.id = 14;test4.score = 2.5;
  Data* ret;
  
  printf("%d\n",enqueue_Queue(&que, &test));
  printf("%d\n",enqueue_Queue(&que, &test1));
  printf("%d\n",enqueue_Queue(&que, &test2));
  printf("%d\n",enqueue_Queue(&que, &test3));
  printf("%d\n",enqueue_Queue(&que, &test4));
  
  if(dequeue_Queue(&que, &ret))
    printf("%d %f\n", ret->id, ret->score);
  if(dequeue_Queue(&que, &ret))
    printf("%d %f\n", ret->id, ret->score);
  if(dequeue_Queue(&que, &ret))
    printf("%d %f\n", ret->id, ret->score);
  if(dequeue_Queue(&que, &ret))
    printf("%d %f\n", ret->id, ret->score);
  if(dequeue_Queue(&que, &ret))
    printf("%d %f\n", ret->id, ret->score);
  if(dequeue_Queue(&que, &ret))
    printf("%d %f\n", ret->id, ret->score);
 
}