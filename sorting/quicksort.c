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

main()
{
	int v[100], left, right, i;
	printf("Enter the number of elements\n");
	scanf("%d", &right);
	printf("Enter the elements\n");
	for(i = 0; i < right; i++)
		scanf("%d", &v[i]);
	qsort(v, 0, right-1);
	printf("Sorted array is\n");
	for(i =0; i< right; i++)
		printf("%d\t",v[i]);
}


