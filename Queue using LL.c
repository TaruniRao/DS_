#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node* link;
};
struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int n)
{
struct node* newnode;
newnode = malloc(sizeof(newnode));
newnode->data = n;
newnode->link = NULL;
if(rear == NULL){
front= rear  = newnode;
newnode->link = NULL;
}
else{
rear->link = newnode;
newnode->link = NULL;
rear = newnode;
}
printf("%d is inserted\n",n);
}

void dequeue()
{
if(front == NULL){
printf("Queue underflow\n");
return;
}
struct node* temp = front;
front = front->link;
temp->link = NULL;
printf("%d is deleted\n",temp->data);
free(temp);
if(front == rear){
front = rear = NULL;
}
}

void display()
{
struct node* temp = front;
if(front == NULL){
printf("no elements in the queue\n");
return;
}
while(temp != NULL)
{
printf("%d ",temp->data);
temp = temp->link;
}
printf("\n");
}

int main()
{
int choice,value;
while(1)
{
printf("1.enqueue\n2.dequeue\n3.display\n4.quit\n");
printf("Enter the choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1 :
printf("Enter the element to be inserted :");
scanf("%d",&value);
enqueue(value);
break;
case 2 :
dequeue();
break;
case 3 :
display();
break;
case 4 :
exit(0);
break;
default :
printf("enter the valid choice");
break;
}
}
}
