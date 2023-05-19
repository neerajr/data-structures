#include<stdio.h>
void msort(int a[], int low, int high)
{
	void merge(int a[], int, int, int);
	int mid;
	if(low < high){
		mid = (low + high)/2;
		msort(a, low, mid);
		msort(a, mid+1, high);
		merge(a,low,high,mid);
	}
}

void merge(int a[], int low, int high, int mid)
{
	int i,j,k, c[50];
	i = low;
	j = mid + 1;
	k = low;
	while((i <= mid) && (j <= high)){
		if(a[i] < a[j])
			c[k++] = a[i++];
		else 
			c[k++] = a[j++];
	}
	while(i <= mid)
		c[k++] = a[i++];
	while(j <= high)
		c[k++] = a[j++];
	for(i = low; i < k; i++)
		a[i] = c[i];
}

main()
{
	int v[100], left, right, i;
	printf("Enter the number of elements\n");
	scanf("%d", &right);
	printf("Enter the elements\n");
	for(i = 0; i < right; i++)
		scanf("%d", &v[i]);
	msort(v, 0, right-1);
	printf("Sorted array is\n");
	for(i =0; i< right; i++)
		printf("%d\t",v[i]);
}


