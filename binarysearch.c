#include<stdio.h>
void qsort(int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j);
	if(left >= right)
		return;
	swap(v, left, (left+right)/2);
	last = left;
	for(i = left+1; i <= right; i++){
		if(v[i] < v[left])
			swap(v, ++last, i);
	}
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

void swap(int v[], int i, int j)
{
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int binsearch(int x, int v[], int n)
{
	int low, mid, high;
	low = 0;
	high = n-1;
	while(low <= high){
		mid = (low+high)/2;
		if(x < v[mid])
			high = mid - 1;
		else if(x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

main()
{
	int v[100], element, right, pos, i;
	printf("Enter the number of elements\n");
	scanf("%d", &right);
	printf("Enter the elements\n");
	for(i = 0; i < right; i++)
		scanf("%d", &v[i]);
	qsort(v, 0, right-1);
	printf("Sorted array is\n");
	for(i =0; i< right; i++)
		printf("%d\t",v[i]);
	printf("\nEnter the element to search\t");
	scanf("%d", &element);
	if(pos = binsearch(element,v,right))
		printf("Found at position %d\n",pos+1);
	else
		printf("Not found\n");
}


