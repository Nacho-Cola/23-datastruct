#include <stdio.h>
#include <stdlib.h>

typedef struct em_{
  char name[50];
  char id[50];
  int money;
}em;

em* new_emp(){
  em* person = (em*)malloc(sizeof(em));
  printf("name: \n");
  scanf("%s",person->name);
  printf("id: \n");
  scanf("%s",person->id);
  printf("money: \n");
  scanf("%d",&person->money);
  return person;
}

void sort_data(em** data){
  em* temp;
  for(int i=0; i<3 ; i++){
    for(int j=i; j<3 ; j++){
      if(data[i]->money < data[j]->money){
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
      }
    } 
  }
}

void dis_data(em** data){
  printf("%10s %10s %10s\n","name","id","money");
  for(int i=0;i<3;i++){
    printf("%10s %10s %10d\n",data[i]->name,data[i]->id,data[i]->money);
  }
}

void save_data(em** data){
  FILE* fp = fopen("test.txt","w");
  for(int i=0; i<3; i++){
    fprintf(fp,"%s %s %d\n",data[i]->name,data[i]->id,data[i]->money);
  }
  fclose(fp);
}

void load_data(em** data){
  FILE* fp = fopen("test.txt","r");
  for(int i=0; i<3; i++){
    fscanf(fp,"%s %s %d\n",data[i]->name,data[i]->id,&data[i]->money);
  }
  fclose(fp);
}

int main(){
  em* list[3];
  printf("put in 3 employee info.");
  for(int i=0;i<3;i++){
    list[i] = new_emp();
  }
  sort_data(list);
  dis_data(list);
  save_data(list);

  list[0]->money = NULL;list[1]->money =NULL;list[2]->money=0; // 정보 변경
  dis_data(list);

  load_data(list); //저장된 정보 load
  dis_data(list);
}