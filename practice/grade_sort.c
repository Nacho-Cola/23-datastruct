#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 100

typedef struct stu_{
  char name[10];
  int id;
  int score[4];
  float avr;
}stu;

stu** load_data(){
  stu** students = (stu**)malloc(3*sizeof(stu));
  FILE* fp = fopen("grade.txt","r");
  for(int i=0; i<3;i++){
    stu* data = (stu*)malloc(sizeof(stu));
    fscanf(fp,"%s %d %d %d %d %d",data->name,&data->id,&data->score[0],&data->score[1],&data->score[2],&data->score[3]);
    data->avr = (data->score[0]+data->score[1]+data->score[2]+data->score[3])/4.;
    students[i] = data;
  }
  fclose(fp);
  return students;
}

void sort_data(stu** data){
  stu* temp;
  for(int i=0; i<3; i++){
    for(int j=i; j<3; j++){
      if(data[i]->avr < data[j]->avr){
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
      }
    }
  }
}

void dis_data(stu** data){
  printf("%10s%10s%10s%10s%10s%10s%10s\n","name","id","score1","score2","score3","score4","average");
  for(int i=0; i<3; i++){
    printf("%10s%10d%10d%10d%10d%10d%10f\n",data[i]->name,data[i]->id,data[i]->score[0],data[i]->score[1],data[i]->score[2],data[i]->score[3],data[i]->avr);
  }
}


int main(){
  stu** students = load_data();
  
  sort_data(students);
  dis_data(students);

	int* ptr;
  int array[10];

  ptr = array;  //배열의 이름은 배열의 첫 원소의 주소.
  ptr[0] = 100;
  printf("%d", array[0]);
}
