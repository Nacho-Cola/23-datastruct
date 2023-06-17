#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct Data_{
  int id;
  double score;
}Data;


typedef struct DataStack_{
  Data *stack;   // 문자 저장
  int sp;         //스텍포인터
}DataStack;

init(DataStack* stack, int size){
  stack -> sp = -1;
  stack -> stack = (Data*)malloc(sizeof(Data)*size);
}

int stack_push(DataStack* stack , Data data){
  if(stack->sp < SIZE - 1){
    stack->stack[++(stack->sp)] = data; //sp 값이 -1 이라서
    return 1;
  }
  return 0;
}

int stack_pop(DataStack* stack, Data* data){
  if(stack->sp > -1){
    *data = stack->stack[(stack->sp)--];
    return 1;
  }
  return 0;
}

int main(){
  DataStack st;
  Data test, ret;


  init(&st, SIZE);
  char ch;
  stack_push(&st, test);
  stack_push(&st, test);
  if(stack_pop(&st, &ret))
    printf("%d %f\n", ret.id, ret.score);
  if(stack_pop(&st,&ret))
    printf("%d %f\n", ret.id, ret.score);

  printf("stack point = %d \n",st.sp);
   if(stack_pop(&st,&ret))
    printf("%c\n", ch);
}