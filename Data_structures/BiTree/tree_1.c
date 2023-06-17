#include "../binary_tree/bitree_rev.h"
#include "../binary_tree/bitree_rev.c"
#include "../binary_tree/list.c"
#include "../binary_tree/list.h"
#include "../binary_tree/traverse.h"
#include "../binary_tree/traverse.c"

#include <stdio.h>



//랜덤 문자열 생성, 100만개 tree에 추가, index look_up, 시간 측정.
//동일한 상황에서 linked_list 시간 측정 후 비교.

int cmp(void*s, void*t){
  return *(char*)s - *(char*)t;
}

int main(){
  BiTree tree;
  char *p;
  List list;
  ListElmt *x;

  bitree_init(&tree,NULL,cmp);

  for(int i =0; i<5; i++){
    p = (char*)malloc(1); *p = 0x41 + rand()%20;
    bitree_insert(&tree, p);
    printf("%c",*p);
  }

  printf("\n");
  list_init(&list,NULL);

  preorder(tree.root, &list);
  for(x=list.head;x!=NULL;x=x->next){
    printf("%c",*((char*)x->data));
  }

  printf("\n");
  list_destroy(&list);  
  inorder(tree.root, &list);
  for(x=list.head;x!=NULL;x=x->next){
    printf("%c",*((char*)x->data));
  }


  //pre_order //root 먼저
  //in_order //left 먼저
  //post_order //root 마지낙
}