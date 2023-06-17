#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../linked_list_API/list.h"
#include "../linked_list_API/list.c"

typedef struct Stack_{
  int sp;
  char* str[100];
}Stack;

int init(Stack* stack){
  stack->sp = -1;
  return 0;
}

int push(Stack* stack, char *data){
  char* ch = (char*)malloc(1);
  ch = data;
  stack->str[++(stack->sp)] = ch;
  return 0;
}

int pop(Stack* stack, char** data){
  *data = stack->str[(stack->sp)--];
  return 0;
}

int bracket( char* str){
  Stack s;
  char *ch;
  init(&s);
  for(int i =0 ;str[i];i++){
    switch (str[i])
    {
    case '(' :case '{' :case '[' :
      push(&s,&str[i]); 
      break;
    case ')' :case '}' :case ']' :
      if(s.sp == -1){return 0;}
      else{
        pop(&s, &ch);
        printf("%s\n",ch);
        if((*ch != '(' && *str == ')') || (*ch != '{' && *str == '}') || (*ch != '[' && *str == ']')){
          return 0;
        }
        break;
      }
    }
  }
  if(s.sp != -1){return 0;}
  return 1;
}

int main(){
  FILE* fp;
  char str[100];
  fp = fopen("data.txt","r");
  while(!feof(fp)){
    fscanf(fp,"%s\n",str);
    if(bracket(str)){
      printf("괄호 정상\n");
    }
    else{
      printf("괄호 에러\n");
    }
  }
}

