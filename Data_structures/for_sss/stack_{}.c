#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../linked_list_API/list.h"
#include "../linked_list_API/list.c"

typedef struct Stack_{
  int sp;
  char* data[100];
}Stack;

int init(Stack* s){
  s->sp = -1;
  return 1;
}

int push(Stack* s, char* ch){
  char* c = (char*)malloc(1);
  c = ch;
  s->data[++(s->sp)] = c;
  return 1;
}

int pop(Stack* s, char** ch){
  *ch = s->data[(s->sp)--];
  return 0;
}



int bracket(char* ch){
  Stack str;
  char* c;
  init(&str);
  for(int i=0; ch[i]; i++){
    switch (ch[i]){
      case '(':case '{': case '[':
        push(&str, &ch[i]);
        break;
      case ')': case'}': case ']':
        if(str.sp == -1){return 0;}
        pop(&str, &c);
        if((ch[i] == ')' && *c != '(')||(ch[i] == '}' && *c != '{'),(ch[i] == ']' && *c != '[')){return 0;}
        break;

    }
  }
  if(str.sp != -1){return 0;}
  return 1;
}


int main(){
  FILE* fp;
  char str[100];
  fp = fopen("data.txt","r");
  while(!feof(fp)){
    fscanf(fp,"%s",str);
    if(bracket(str)){
      printf("정상");
    }else{
      printf("error");
    }
  }

}