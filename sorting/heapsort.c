#include<stdio.h>

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

void heapsort(int a[], int n)
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

main()
{
	int v[100], n, i;
	printf("Enter the number of elements\n");
	scanf("%d", &n);
	printf("Enter the elements\n");
	for(i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	heapsort(v,n);
	printf("Sorted array is\n");
	for(i =1; i<= n; i++)
		printf("%d\t",v[i]);
}
		



