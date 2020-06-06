#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   int key;

   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

bool isEmpty(){
   return head == NULL;
}

int length(){
   int length = 0;

   //neu danh sach la trong
   if(head == NULL){
      return 0;
   }

   current = head->next;

   while(current != head){
      length++;
      current = current->next;
   }

   return length;
}

//chen link tai vi tri dau tien
void insertFirst(int key, int data){

   //tao mot link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->key = key;
   link->data = data;

   if (isEmpty()) {
      head = link;
      head->next = head;
   }else {
      //tro no toi first node cu
      link->next = head;

      //tro first toi first node moi
      head = link;
   }

}

//xoa phan tu dau tien
struct node * deleteFirst(){

   //luu tham chieu toi first link
   struct node *tempLink = head;

   if(head->next == head){
      head = NULL;
      return tempLink;
   }

   //danh dau next toi first link la first
   head = head->next;

   //tra ve link da bi xoa
   return tempLink;
}

//hien thi danh sach
void printList(){

   struct node *ptr = head;
   printf("\n[ ");

   //bat dau tu phan dau cua danh sach
   if(head != NULL){

      while(ptr->next != ptr){
         printf("(%d,%d) ",ptr->key,ptr->data);
         ptr = ptr->next;
      }

   }

   printf(" ]");
}

main() {

   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56);

   printf("Danh sach ban dau: ");

   //In danh sach
   printList();

   while(!isEmpty()){
      struct node *temp = deleteFirst();
      printf("\nGia tri bi xoa:");
      printf("(%d,%d) ",temp->key,temp->data);
   }

   printf("\nDanh sach sau khi da xoa tat ca phan tu: ");
   printList();
}
