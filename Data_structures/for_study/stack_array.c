#include <stdio.h>
#include <stdlib.h>
#include "../linked_list_API/list.h"
#include "../linked_list_API/list.c"

#define SIZE 100

typedef struct data_{
  int id;
  char *name;
}data;

typedef struct Stack_{
  data* data[SIZE];
  int sp;
}Stack;

int init(Stack* stack){
  stack->sp = -1;
  return 0;
}
int push(Stack* stack, data* data){
  if(stack->sp < SIZE-1){
    stack->data[++(stack->sp)] = data;
  }
  return 0;
}

int pop(Stack* stack, data** data){
  if(stack->sp != -1){
    *data = stack->data[(stack->sp)--];
  }
  return 0;
}

int main(){
  Stack stack;
  data p; 
  p.id = 1; 
  p.name = "nay";
  data* ret;
  init(&stack);
  push(&stack, &p);
  pop(&stack, &ret);

  printf("%d %s",ret->id, ret->name);

}
