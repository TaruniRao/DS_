#include<stdio.h>
#include<stdlib.h>
#define size 5
int front = -1;
int rear = -1;
int arr[size];
void insert_front();
void insert_rear();
void delete_front();
void delete_rear();
void display();
int main(){
	printf("***Menu**\n");
	printf("1.Insert from Front\n2.Insert from rear\n3.Delete from front\n4.Delete from rear\n5.Display\n6.Exit\n");
	int choice;
	while(1){
		printf("Enter choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1: insert_front();
					break;
			case 2: insert_rear();
					break;
			case 3: delete_front();
					break;
			case 4: delete_rear();
					break;
			case 5: display();
					break;
			case 6: exit(0);
			default: printf("Ente valid choice\n");
			
		}
	}
	return 0;
	
}
void insert_front(){
	int value;
	printf("Enter element:");
	scanf("%d",&value);
	
	if((front==0&&rear==size-1)||(front==rear+1)){
		printf("Queue is full\n");
	}
	else if(front==-1){
		front = rear=0;
		arr[front] = value;
		
	}
	else if(front==0){
		front = size -1;
		arr[front] = value;
		
	}
	else{	
		front--;
		arr[front] = value;
		
	}
}
void insert_rear(){
	int value;
	if((front==0&&rear==size-1)||(front==rear+1)){
		printf("Queue is full\n");
	}
	else{
		if(front==-1){
			front  = 0;
		}
		printf("Enter element:");
		scanf("%d",&value);
		
		rear = (rear+1)%size;
		arr[rear]=value;
	}
}
void delete_front(){
	if(front==-1){
		printf("Queue is empty\n");
	}
	else{
		if(front==rear){
			front=rear=-1;
		}
		else{
			front = (front+1)%size;
		}
	}
}
void delete_rear(){
	if(front==-1){
		printf("Queue is empty\n");
	}
	else if(rear==0){
		rear = size-1;
	}
	else if(front==rear){
		front=rear=-1;
	}
	else{
		rear--;
	}
	
}
void display(){
	if(front==-1){
		printf("Queue is empty\n");
	}
	else{
		int i;
		if(front<=rear){
			for(i = front; i<=rear;i++){
				printf("%d ",arr[i]);
			}
			printf("\n");
		}
		else{
			for(i=front;i<=size-1;i++){
				printf("%d ",arr[i]);
			}
			for(i=0;i<=rear;i++){
				printf("%d ",arr[i]);
			}
			printf("\n");
		}
	}
}
