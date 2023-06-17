#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct Data_{
  int id;
  double score;
}Data;


typedef struct DataStack_{
  Data *stack[SIZE];   // 문자 저장
  int sp;         //스텍포인터
}DataStack;

init(DataStack* stack, int size){  //malloc 필요 없다.
  stack -> sp = -1; 
}

int stack_push(DataStack* stack , Data *data){
  if(stack->sp < SIZE - 1){
    stack->stack[++(stack->sp)] = data; //sp 값이 -1 이라서
    return 1;
  }
  return 0;
}

int stack_pop(DataStack* stack, Data** data){
  if(stack->sp > -1){
    *data = stack->stack[(stack->sp)--];
    return 1;
  }
  return 0;
}

int main(){
  DataStack st;
  Data test; test.id = 10;test.score = 4.5;
  Data* ret;

  // main 문이 아닌 함수의 지역변수에서 선언된 정적 할당은 stact에 저장되었다고 하여도 주소값 접근이 유효하지 않음.
  // 동적할당으로 해결, 동적할당은 free 하기전까지 주소가 유효하다.
 
  init(&st, SIZE);
  char ch;
  stack_push(&st, &test);
  stack_push(&st, &test);
  if(stack_pop(&st, &ret))
    printf("%d %f\n", ret->id, ret->score);
  if(stack_pop(&st,&ret))
    printf("%d %f\n", ret->id, ret->score);

  printf("stack point = %d \n",st.sp);
   if(stack_pop(&st,&ret))
    printf("%c\n", ch);
}