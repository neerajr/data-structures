#include<stdio.h>
#define MAX 20

int false = 0;
int true = 1;
int adj[MAX][MAX];
int visited[MAX];
int n;	/*number of nodes */

main()
{
	int i,v,ch;

	creategraph();
	while(1)
	{
		printf("\n 1 : Adjacency matrix\n2 : BFS\n3 : DFS\n");
		printf("4 : Adjacent vertices\n5 : exit\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Adjacency matrix\n");
				display();
				break;
			case 2: printf("Enter the start node\n");
				scanf("%d",&v);
				for(i=1; i<=n; i++)
					visited[i] = false;
				bfs(v);
				break;
			case 3: printf("enter starting node\n");
				scanf("%d",&v);
				for(i=1; i<=n; i++)
					visited[i] = false;
				dfs(v);
				break;
			case 4: printf("Enter node to find adjacent vertices\n");
				scanf("%d",&v);
				printf("Adjacent vertices are : ");
				adjnodes(v);
				break;
			case 5: return 0;
			default: printf("Wrong choice\n");
				 break;
		}
	}
}

creategraph()
{
	int i, maxedges, origin, destin;

	printf("Enter the number of nodes\t");
	scanf("%d",&n);
	maxedges = n*(n-1);
	for(i=1;i<=maxedges;i++)
	{
		printf("Enter edge %d( 0 0 to quit ) : ",i);
		scanf("%d %d",&origin,&destin);

		if((origin==0) && (destin==0))
			break;

		if( origin > n || destin > n || origin<=0 || destin<=0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin]=1;
		}
	}
}

display()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%4d",adj[i][j]);
		printf("\n");
	}
}

bfs(int v)
{
	int i,front,rear;
	int que[20];
	front=rear= -1;

	printf("%d ",v);
	visited[v]=true;
	rear++;
	front++;
	que[rear]=v;

	while(front<=rear)
	{
		v=que[front];
		front++;
		for(i=1;i<=n;i++)
		{
			if( adj[v][i]==1 && visited[i]==false)
			{
				printf("%d ",i);
				visited[i]=true;
				rear++;
				que[rear]=i;
			}
		}
	}
}

dfs(int v)
{
	int i,stack[MAX],top=-1,pop_v,j,t;
	int ch;

	top++;
	stack[top]=v;
	while (top>=0)
	{
		pop_v=stack[top];
		top--; /*pop from stack*/
		if( visited[pop_v]==false)
		{
			printf("%d ",pop_v);
			visited[pop_v]=true;
		}
		else
			continue;

		for(i=n;i>=1;i--)
		{
			if( adj[pop_v][i]==1 && visited[i]==false)
			{
				top++; 
				stack[top]=i;
			}
		}
	}
}

adjnodes(int v)
{
	int i;
	for(i=1;i<=n;i++)
		if(adj[v][i]==1)
			printf("%d ",i);
	printf("\n");
}

