#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node* link;
};
struct node* top = NULL;

void push(int n)
{
struct node* newnode;
newnode = malloc(sizeof(newnode));
if(newnode == NULL){
printf("stack overflow\n");
return;
}
newnode->data = n;
newnode->link = NULL;
newnode->link = top;
top = newnode;
printf("%d is Inserted\n",n);
}

void pop()
{
struct node* temp = top;
if(top == NULL){
printf("Stack underflow\n");
return;
}
top = temp->link;
int value = temp->data;
temp->link = NULL;
free(temp);
printf("%d is deleted\n",value);
}

void display()
{
if(top == NULL)
{
printf("No elements in the stack");
return;
}
struct node* temp = top;
while(temp->link != NULL)
{
printf("%d->",temp->data);
temp = temp->link;
}
printf("%d\n",temp->data);
}

void peek()
{
if(top == NULL)
{
printf("no elements to print peek value\n");
return;
}
printf("peek : %d\n",top->data);
}

int main()
{
int choice,value;
while(1){
printf("menu\n");
printf("1.push\n2.pop\n3.display\n4.peek\n5.quit\n");
printf("enter the choice: ");
scanf("%d",&choice);
switch(choice){
case 1 :
printf("Enter the data : ");
scanf("%d",&value);
push(value);
break;
case 2 :
pop();
break;
case 3 :
display();
break;
case 4 :
peek();
break;
case 5 :
exit(0);
default:
printf("Enter the valid input");
break;
}
}
}

