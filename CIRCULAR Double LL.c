#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node* prev;
struct node* next;
};
struct node* head = NULL;

void insert_at_beg(int n)
{
struct node* newnode;
newnode = malloc(sizeof(newnode));
newnode->data = n;
if(head == NULL){
newnode->prev = newnode;
newnode->next = newnode;
head = newnode;
}
else{
struct node* temp = head;
while(temp->next!=head)
{
temp=temp->next;
}
temp->next = newnode;
newnode->next = head;
newnode->prev = temp;
head = newnode;
}
printf("%d is Inserted\n",n);
}

void insert_at_end(int n)
{
struct node* newnode;
newnode = malloc(sizeof(newnode));
newnode->data = n;
if(head == NULL)
{
newnode->prev = newnode;
newnode->next = newnode;
head = newnode;
}
else
{
struct node* temp = head;
newnode->next = head;
while(temp->next !=head){
temp = temp->next;
}
head->prev = newnode;
newnode->prev = temp;
temp->next = newnode;
}
printf("%d is Inserted\n",n);
}

void insert_at_pos(int n,int pos)
{
struct node* newnode;
newnode = malloc(sizeof(newnode));
newnode->data = n;
struct node* temp = head;
int i;
for(i = 0;i<pos-2;i++)
{
temp = temp->next;
}
newnode->next = temp->next;
newnode->prev = temp;
temp->next = newnode;
temp->next->prev = newnode;
printf("%d is Inserted\n",n);
}

void delete_at_beg()
{
struct node* temp1 = head;
if(head == NULL){
printf("no elements to delete\n");
return;
}
struct node* temp2 = head;
while(temp2 -> next != head)
{
temp2 = temp2->next;
}
head = temp1->next;
int value = temp1->data;
temp1->next = NULL;
temp2->next = head;
head->prev = temp2;
free(temp1);
printf("%d is deleted\n",value);
}

void delete_at_end()
{
struct node* temp = head;
struct node* prevnode;
if(head == NULL)
{
printf("no elements to delete\n");
return;
}
while(temp->next !=head){
prevnode = temp;
temp = temp->next;
}
int value = temp->data;
prevnode->next = head;
head->prev = prevnode;
temp->prev = NULL;
temp->next = NULL;
free(temp);
printf("%d is deleted\n",value);
}

void delete_at_pos(int n)
{
struct node* temp = head;
struct node* prevnode;
if(head == NULL){
printf("No elements to delete");
return;
}
while(temp->data != n)
{
if(temp->next != NULL){
prevnode = temp;
temp=temp->next;
}
else{
printf("no such element found\n");
return;
}
}
printf("%d is deleted\n",temp->data);
prevnode->next = temp->next;
temp->next = NULL;
temp->prev = NULL;
free(temp);
}


void display()
{
if(head == NULL)
{
printf("No elements in the list\n");
return;
}
struct node* temp = head;
while(temp->next != head)
{
printf("%d->",temp->data);
temp = temp->next;
}
printf("%d\n",temp->data);
}



void search(int n)
{
int count =1;
if(head == NULL)
{
printf("no elements to search\n");
return;
}
struct node* temp = head;
while(temp->next!= NULL)
{
if(temp->data==n)
{
printf("%d is at position %d\n",n,count);
return;
}
else{
temp = temp->next;
count++;
}
}
printf("No sech element found\n");
}

int main()
{
int choice,value,pos;
while(1){
printf("menu\n");
printf("1.insert at beggining\n2.insert at end\n3.insert at position\n4.delete at beggining\n5.delete at end\n6.delete at position\n7.display\n8.search\n9.quit\n");
printf("enter the choice: ");
scanf("%d",&choice);
switch(choice){
case 1 :
printf("Enter the data : ");
scanf("%d",&value);
insert_at_beg(value);
break;
case 2 :
printf("Enter the data : ");
scanf("%d",&value);
insert_at_end(value);
break;

case 3 :
printf("Enter the data : ");
scanf("%d",&value);
printf("Enter the position to be inserted: ");
scanf("%d",&pos);
insert_at_pos(value,pos);
break;
case 4 :
delete_at_beg();
break;
case 5 :
delete_at_end();
break;
case 6 :
printf("enter the element to be deleted: ");
scanf("%d",&value);
delete_at_pos(value);
break;
case 7 :
display();
break;
case 8 :
printf("enter the value to be searched: ");
scanf("%d",&value);
search(value);
break;
case 9 :
exit(0);
default:
printf("Enter the valid input");
break;
}
}
}
