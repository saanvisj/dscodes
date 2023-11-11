#include <stdio.h>
#include<stdlib.h>
#define CAPACITY 20
void insert();
void delete();
void display();
int queue_array[CAPACITY];
int rear = - 1;
int front = - 1;
void main()
{
 int choice;
 while (1)
 {
 printf("\n1.Enter 1 to insert element to queue \n");
 printf("2.Enter 2 to delete element from queue \n");
 printf("3.Enter 3 to display all elements of queue \n");
 printf("4.Enter 4 to quit \n");
 printf("Enter your choice : ");
 scanf("%d", &choice);
 switch (choice)
 {
 case 1: insert();
 break;
 case 2: delete();
 break;
 case 3: display();
 break;
 case 4: exit(0);
 default:printf("Wrong choice \n");
 } 
 } 
}