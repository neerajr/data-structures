#include<stdio.h>
struct heapstruct
{
	int capacity;
	int size;
	int *a;
};
typedef struct heapstruct *pq;
pq initialize(int maxa,int mindata)
{
	pq h;
	h=(struct heapstruct*)malloc(sizeof(struct heapstruct));
	if(h==NULL)
		printf(“\nOut of Space”);
	h->a=(int*)malloc((maxa+1)*sizeof(int));
	h->capacity=maxa;
	h->size=0;
	h->a[0]=mindata;
	return h;
}
void insert(int x,pq h)
{
	int i;
	if(h->size==h->capacity)
	{
		printf(“\nFull”);
	}
	else
	{
		for(i=++h->size;h->a[i/2]>x;i=i/2)
		{
			h->a[i]=h->a[i/2];
		}
		h->a[i]=x;
	}
}
int delmin(pq h)
{
	int i,mina,lasta,child;
	if(h->size==0)
	{
		return(h->a[0]);
	}
	else
	{
		mina=h->a[1];
		lasta=h->a[h->size--];
		for(i=1;i*2size;i=child)
		{
			child=i*2;
			if(child!=h->size && h->a[child+1]a[child])
				child++;
			if(lasta>h->a[child])
			{
				h->a[i]=h->a[child];
			}
			else
				break;
		}
		h->a[i]=lasta;
		return mina;
	}
}
void display(pq h)
{
	int i;
	for(i=1;isize;i++)
	{
		printf(“\nThe data is: %d”,h->a[i]);
	}
}
void main()
{
	pq h;int x,y,z,u,v;char ch;
	clrscr();
	printf(“\nEnter the maximum number of elements for the Priority Queue:”);
	scanf(“%d”,&x);
	printf(“\nEnter the minimum element :”);
	scanf(“%d”,&y);
	h=initialize(x,y);
menu:
	printf(“\nPriority Queue”);
	printf(“\n1.Insert\n2.Delete\n3.Display\n4.Exit”);
	scanf(“%d”,&u);
	switch(u)
	{
		case 1:printf(“Enter the Data:”);
		       scanf(“%d”,&z);
		       insert(z,h);
		       break;
		case 2:v=delmin(h);
		       printf(“\nThe deleted element is: %d”,v);
		       break;
		case 3:display(h);
		       break;
		case 4:exit(0);
	}
	goto menu;
}

