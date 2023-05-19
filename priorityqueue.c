#include<stdio.h>
#define MAXSIZE 100

int parent(int i)
{
	return i/2;
}

int left(int i)
{
	return 2*i;
}

int right(i)
{
	return (2*i +1);
}

void heapify(int a[], int root, int bottom)
{
	int i = root;
	int l = left(i);
	int r = right(i);
	int maxchild, temp;

	if((l <= bottom) && (a[l] > a[i]))
		maxchild = l;
	else 
		maxchild = i;
	if((r <= bottom) && a[r] > a[maxchild])
		maxchild = r;
	if(maxchild != i) {
		temp = a[i];
		a[i] = a[maxchild];
		a[maxchild] = temp;
		heapify(a,maxchild,bottom);
	}
}

void buildheap(int a[], int n)
{
	int i;
	for(i = n/2; i>=1; i--)
		heapify(a,i,n);
}

void insert(int a[],int element, int rear)
{
	int temp;
	if(rear == MAXSIZE){
		printf("Queue FULL\n");
		return;
	}
	else {
		a[rear] = element;
		buildheap(a,rear);
	}
}
	
int deletemax(int a[], int rear)
{
	int temp;
	temp = a[1];
	a[1] = rear;
	rear = temp;
	buildheap(a,--rear);
	return temp;
}

/*void heapsort(int a[], int n)
{
	int i,j, temp;
	buildheap(a,n);
	for(i = n; i>1; i--) {
		temp = a[1];
		a[1] = a[i];
		a[i] = temp;;
		heapify(a,1,--n);
	}
}
*/
main()
{
	int rear = 0;
	int front = 0;
	int ch = 1;
	int v[MAXSIZE], i, element;
	while(1) {
		printf("1 : Insert\n2 : deletemax\n3 : emptyQ\n4 : display\n5 : exit\nEnter your choice\t");
		scanf("%d",&ch);
		switch(ch) {
			case 1: printf("Enter the element\n");
				scanf("%d", &element);
				rear++;
				if(rear == 1)
				front = 1;
				insert(v,element,rear);
				break;
			case 2: if(rear == 0){
					front == 0;
					printf("Queue emty\n");
					break;
				}
				printf("deleted element is : %d\n",deletemax(v,rear));
				rear--;
				break;
			case 3: front = rear = 0;
				break;
			case 4: printf("Priority queue is\n");
				for(i =1; i<= rear; i++)
					printf("%d\t",v[i]);
				printf("\n");
				break; 
			case 5: return 0;
			default: printf("Wrong choice\n");
				 break;
		}
	}
}
		



