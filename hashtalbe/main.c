#include "hashtable/chtbl.h"
#include "hashtable/chtbl.c"
#include "hashtable/list.h"
#include "hashtable/list.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generate_rnd_string(char *p, int length){
  int t;
  for(t=0; t<length;t++){
    *p++ = 0x41+ (int)rand()%26;
  }
  *p = '\0';
}

int hash(const void *key){
  int sum = 0;
  char* ch = (char*)key;
  while(*ch){
    sum += *ch++;
  }
  return sum;
}

int match(const void* s,const void* t){
  return strcmp((char*)s,(char*)t);
}


int main(){
  CHTbl chtbl;
  int i;
  clock_t start;
  char* data, *tmp;

  chtbl_init(&chtbl, 10,hash,match,NULL);

  for(i=0; i<100000000; i++){
    data = (char*)malloc(sizeof(char)*20);
    generate_rnd_string(data, 10);

    chtbl_insert(&chtbl, data);

  }
  tmp = data;
  start = clock();
  if(!chtbl_lookup(&chtbl, (void**)&tmp)){
    printf("found\n");
  }
  printf("%f\n",(clock()-start)/CLOCKS_PER_SEC);
}