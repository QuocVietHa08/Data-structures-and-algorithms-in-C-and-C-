#include <stdio.h>
#include <stdbool.h>
#define MAX 7

int intArray[MAX] = {4,6,3,2,1,9,7};

void printline(int count){
   int i;

   for(i = 0;i <count-1;i++){
      printf("=");
   }

   printf("=\n");
}

//ham hien thi cac phan tu
void display(){
   int i;
   printf("[");

   // duyet qua tat ca phan tu
   for(i = 0;i<MAX;i++){
      printf("%d ",intArray[i]);
   }

   printf("]\n");
}

//ham sap xep
void shellSort(){
   int inner, outer;
   int valueToInsert;
   int interval = 1;
   int elements = MAX;
   int i = 0;

   while(interval <= elements/3) {
      interval = interval*3 +1;
   }

   while(interval > 0) {
      printf("Vong lap thu %d#:",i);
      display();

      for(outer = interval; outer < elements; outer++) {
         valueToInsert = intArray[outer];
         inner = outer;

         while(inner > interval -1 && intArray[inner - interval]
            >= valueToInsert) {
            intArray[inner] = intArray[inner - interval];
            inner -=interval;
            printf(" Di chuyen phan tu :%d\n",intArray[inner]);
         }

         intArray[inner] = valueToInsert;
         printf(" Chen phan tu :%d, tai vi tri :%d\n",valueToInsert,inner);
      }

      interval = (interval -1) /3;
      i++;
   }
}

int main() {
   printf("Mang du lieu dau vao: ");
   display();
   printline(50);
   shellSort();
   printf("Mang ket qua: ");
   display();
   printline(50);
   return 1;
}
