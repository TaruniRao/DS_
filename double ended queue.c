#include<stdio.h>
#include<stdlib.h>
int size = 5;
int arr[5];
int f = -1;
int r = -1;
void insert_front(int n)
{
	if(((f == 0)&&(r == size-1))||(f == r +1)){
		printf("Queue is full\n");
		return;
	}
	else if(f == -1 && r == -1)
	{
		f = r = 0;
		arr[f] = n;
		printf("%d is inserted \n",n,f);
	}
	else if(f == 0)
	{
		f = size-1;
		arr[f]=n;
		printf("%d is inserted \n",n,f);
	}
	else
	{
		f--;
		arr[f]=n;
		printf("%d is inserted \n",n,f);
	}
}

void insert_rear(int n)
{
	if(((f == 0)&&(r == size-1))||(f == r +1)){
		printf("Queue is full\n");
		return;
	}
	else if(f == r == -1)
	{
		f = 0;
		r = 0;
		arr[r] = n;
		printf("%d is inserted \n",n,r);
	}
	else if(r == size -1)
	{
		r = 0;
		arr[r] = n;
		printf("%d is inserted \n",n,r);
	}
	else
	{
		r++;
		arr[r] = n;
		printf("%d is inserted\n",n,r);
	}
}

void delete_front()
{
	if(f == -1&&r==-1)
	{
		printf("Queue is empty\n");
		return;
	}
	else if(f == size -1)
	{
		printf("%d is deleted\n",arr[f]);
		f = 0;
	}
	else if(f == r)
	{
		printf("%d is deleted\n",arr[f]);
		f=r=-1;
	}
	else
	{
		printf("%d is deleted \n",arr[f]);
		f++;
	}
}

void delete_rear()
{
	if(f == -1&&r==-1)
	{
		printf("Queue is empty\n");
		return;
	}
	else if(r == 0)
	{
		printf("%d is deleted\n",arr[r]);
		r = size -1;
	}
	else if(f == r)
	{
		printf("%d is deleted\n",arr[r]);
		f = r = -1;
	}
	else
	{
		printf("%d is deleted\n",arr[r]);
		r--;
	}
}

void display()
{
	if(f == -1&&r==-1)
	{
		printf("Queue is empty\n");
		return;
	}
	else
	{
		if(f > r)
		{
			int i,j;
			for(j = 0;j<=r;j++)
			{
				printf("%d ",arr[j]);
			}
			for(i = f;i<=size-1;i++)
			{
				printf("%d ",arr[i]);
			}
			
			printf("\n");
		}
		else
		{
			int i ;
			for(i = f;i<=r;i++)
			{
				printf("%d ",arr[i]);
			}
			printf("\n");
		}
	}
}

int main()
{
	int choice,n ;
	while(1){
		printf("1.insert-front\n2.insert-rear\n3.delete-front\n4.delete-rear\n5.display\n6.exit\n");
		printf("Enter the choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
				if(((f == 0)&&(r == size-1))||(f == r +1)){
					printf("Queue is full\n");
					return;
				}
				else{
					printf("Enter the element :");
					scanf("%d",&n);
					insert_front(n);
				}
				break;
			case 2 :
				if(((f == 0)&&(r == size-1))||(f == r +1)){
					printf("Queue is full\n");
					return;
				}
				else{
					printf("Enter the element : ");
					scanf("%d",&n);
					insert_rear(n);
				}
				break;
			case 3 :
				delete_front();
				break;
			case 4 :
				delete_rear();
				break;
			case 5 :
				display();
				break;
			case 6 :
				exit(0);
			default :
				printf("Enter the valid choice: ");
				break;
				
		}
	}	
}
