#include "sort/sort.h"
#include <stdio.h>
#define NUM_DATA 500

typedef struct data_
{
  int id;
  char name[10];
  double score;
}data;

int op;

void gen_rand_str(char* p, int len){
  int i;
  for(i=0;i<len;i++){
    *p++= 0x41 +rand() %26;
  }
  *p = '\0';
}

compare(const void* key1, const void* key2){
  int val;
  data *a, *b;
  a=(char* )key1;
  b = (char*)key2;

  swich(op){
    case 0 : val = a->id - b->id;break;
    case 1 : val = a->id - b->id;break;
    case 2 : val = a->score - b->score;break;
    return val
  }
}

int main(){
  // data v[NUM_DATA];  //stack overflow 해결법 -> 동적할당
  data *v;
  v = (data*)malloc(sizeof(data)*NUM_DATA);
  int i;
  for(i=0; i<NUM_DATA ; i++){
    (v+i)->id = rand();
    gen_rand_str((v+i)->name, 7);  
    (v+i)->score = (double)rand();
  }

  op = 0;

  issort(v, NUM_DATA, sizeof(data), compare);

  qksort(v, NUM_DATA, sizeof(data), 0, NUM_DATA-1,compare);

  for(i=0;i<NUM_DATA;i++){
    print("%d %s\n",(v+i)->id, (v+i)->name);
  }
}



//구조체 포인터 배열 정렬 -> 구조체를 복사할 필요럾이 주소만 복사하여 정렬가능