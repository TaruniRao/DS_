#include<stdio.h>
int x[10];

void quicksort(int x[10],int first,int last){
	int pivot,j,temp,i;
	if(first<last){
		pivot=first;
		i=first;
		j=last;
		while(i<j){
			while(x[i]<=x[pivot]&&i<last)
				i++;
			while(x[j]>x[pivot])
				j--;
			if(i<j){
				temp=x[i];
				x[i]=x[j];
				x[j]=temp;
			}
		}
		temp = x[pivot];
		x[pivot] = x[j];
		x[j] = temp;
		quicksort(x,first,j-1);
		quicksort(x,j+1,last);
	}
		
}

int main()
{
	int i = 0;
	printf("Enter the elements:\n");
	while(i<10){
		scanf("%d",&x[i]);
		i++;
	}
	quicksort(x,0,9);
	
	printf("the sorted list is :");
	int a;
	for(a = 0;a<10;a++)
	{
		printf("%d ",x[a]);
	}
	return 0;
	
}

