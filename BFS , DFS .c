#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 5
void BFS(int adj[][MAX],int visited[],int start)
{
    int q[MAX],rear=-1,front=-1,i,k;
    for(k=0;k<MAX;k++)
    {
        visited[k]=0;
    }
    q[++rear]=start;
    ++front;
    visited[start]=1;
    while(rear>=front)     //until queue is empty
    {
        start=q[front++];
        printf("%c--",start+65);
        for(i=0;i<MAX;i++)     //add neighbours
        {
            if(adj[start][i] && visited[i]==0)
            {
                q[++rear]=i;
                visited[i]=1;
            }
        }
    }
}
void DFS(int adj[][MAX],int visited[],int start)
{
    int s[MAX];
    int top=-1,i,k;
    for(k=0;k<MAX;k++)
    {
        visited[k]=0;
    }
    s[++top]=start;
    visited[start]=1;
    while(top!=-1)     //until stack is empty
    {
        start=s[top--];
        printf("%c--",start+65);
        for(i=0;i<MAX;i++)     //add neighbours
        {
            if(adj[start][i] && visited[i]==0)
            {
                s[++top]=i;
                visited[i]=1;
            }
        }
    }
}
int main()
{
    int visited[MAX]={0};
    int adj[MAX][MAX],i,j;
    int ch,size;
    while(1)
    {
        printf("\nMAIN MENU\n");
        printf("\n1. enter the values in to adjancy matrix\n");
        printf("\n2. BFS Traversal\n");
        printf("\n3. DFS Traversal\n");
        printf("\n4. EXIT\n");
        printf("\n Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\n enter the values to adjacency matrix\n");
                    for(i=0;i<MAX;i++)
                    {
                        for(j=0;j<MAX;j++)
                        {
                            scanf("%d",&adj[i][j]);
                        }
                    }
                    break;
            case 2:printf("BFS Traversal is\n");
                    BFS(adj,visited,2);
                    break;
            case 3:printf("DFS Traversal is\n");
                    DFS(adj,visited,4);
                    break;
            case 4:exit(0);
            default:
            	printf("Enter the valid choice");
        }

    }
}
