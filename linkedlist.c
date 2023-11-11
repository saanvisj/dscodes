#include<stdio.h>
#include<stdlib.h>
int count;
struct node
{
float marks1,marks2,marks3;
char usn[15],name[20],dept[20],phno[15];
struct node *llink;
struct node *rlink;
};
typedef struct node *NODE;
NODE first=NULL;
NODE getnode()
{
NODE x; 
x = (NODE)malloc(sizeof(struct node));
return x;
}
NODE create_node()
{
NODE temp;
temp = getnode();
printf("Enter Students Details : \n");
printf("Enter usn : ");
scanf("%s", temp->usn);
printf("Enter Name : ");
scanf("%s", temp->name);
printf("Enter Dept : ");
scanf("%s", temp->dept);
printf("Enter marks1 : ");
scanf("%f", &(temp->marks1));
printf("Enter marks2 : ");
scanf("%f", &(temp->marks2));
printf("Enter marks3 : ");
scanf("%f", &(temp->marks3));
printf("Enter Phone No : ");
scanf("%s", temp->phno);
temp->llink = NULL;
temp->rlink = NULL;
count++;
return temp;
}
void disp_deleted(NODE temp)
{
printf("The following Student detail is deleted:\n");
printf("USN | Name | Dept | Marks1 | Marks2 | Marks3 | Ph. No \n");
printf("----------------------------------------------------------------------------------\n");
printf("%s | %s | %s | %.2f | %.2f | %.2f | %s \n",temp->usn,temp->name,temp->dept, 
temp->marks1,temp->marks2,temp->marks3,temp->phno);
count--;
}
void insert_front()
{
NODE temp;
temp = create_node();
if(first == NULL)
{
first = temp;
}
else
{
temp->rlink = first;
first->llink = temp;
first = temp;
}
}
void delete_front()
{
NODE temp;
if(first == NULL)
{
printf("List is Empty\n");
}
else if(first->rlink == NULL)
{
disp_deleted(first);
free(first);
first = NULL;
}
else
{
temp = first;
disp_deleted(temp);
first = first->rlink;
first->llink = NULL;
temp->rlink = NULL;
free(temp);
temp = NULL;
}
}
void insert_rear()
{
NODE temp,cur;
temp = create_node();
if(first == NULL)
{
first = temp;
}
else
{
cur = first;
while(cur->rlink !=NULL)
{
cur = cur->rlink;
}
cur->rlink = temp;
temp->llink = cur;
}
}
void delete_rear()
{
NODE cur;
if(first == NULL)
{
printf("List is empty\n");
}
else if(first->rlink == NULL)
{
disp_deleted(first);
free(first);
first = NULL;
}
else
{
cur = first;
while(cur->rlink != NULL)
{
cur = cur->rlink;
}
disp_deleted(cur);
cur->llink->rlink = NULL;
cur->llink = NULL;
free(cur);
cur = NULL;
}
}
void display()
{
NODE cur;
float total, average;
if(first == NULL)
{
printf("List is empty\n");
}
else
{
cur = first;
printf("The student details in doubly Linked list from beginning : \n");
printf("USN | Name | Dept | Marks1 |Marks2 | Marks3 | Total Marks | Average | Ph. No \n");
printf("----------------------------------------------------------------------------------\n");
while(cur != NULL)
{
total=cur->marks1 + cur->marks2 + cur->marks3;
average=total/3;
printf("%s | %s | %s | %.2f | %.2f | %.2f | %.2f | %.2f | %s \n",cur->usn,cur->name, cur->dept,cur->marks1,cur->marks2,cur->marks3,total, average, cur->phno);
cur = cur->rlink;
}
printf("----------------------------------------------------------------------------------\n");
printf("Number of Nodes = %d\n",count);
}
}
void main()
{
int choice,i,n;
while(1)
{
choice=0;
printf("------------------------------------------MENU----------------------------------------\n");
printf("1. Create a DLL of N student by using End Insertion\n");
printf("2. Display Status and Count of nodes\n");
printf("3. Insertion at rear\n");
printf("4. Deletion at rear\n");
printf("5. Insertion at front\n");
printf("6. Delete at front\n");
printf("7. Exit\n");
printf("----------------------------------------------------------------------------------\n");
printf("Enter choice : ");
scanf("%d", &choice);
switch (choice)
{
case 1: printf("Enter number of student:");
scanf("%d",&n);
for(i=0;i<n;i++)
insert_rear();
break;
case 2: display(); break;
case 3: insert_rear(); break;
case 4: delete_rear(); break;
case 5: insert_front(); break;
case 6: delete_front(); break;
case 7: return;
 default: printf("Invalid choice\n"); 
return;
}
}
}