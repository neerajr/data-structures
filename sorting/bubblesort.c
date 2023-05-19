#include<stdio.h>
void bubsort(int v[], int n)
{
	int i,j,temp;
	for(i = n-2; i >= 0; i--)
		for(j = 0; j <= i; j++)
			if(v[j] > v[j+1]){
				temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
			}
}
main()
{
	int v[100], left, right, i;
	printf("Enter the number of elements\n");
	scanf("%d", &right);
	printf("Enter the elements\n");
	for(i = 0; i < right; i++)
		scanf("%d", &v[i]);
	bubsort(v,right);
	printf("Sorted array is\n");
	for(i =0; i< right; i++)
		printf("%d\t",v[i]);
}


