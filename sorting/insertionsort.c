#include<stdio.h>
void insertsort(int v[], int n)
{
	int i, j, key;

	for(i = 1; i < n-1; i++) {
		j = i;
		key = v[i];

		while(v[j-1] > key && j>0){
			v[j] = v[j-1];
			j = j-1;
		}
		v[j] = key;
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
	insertsort(v,right);
	printf("Sorted array is\n");
	for(i =0; i< right; i++)
		printf("%d\t",v[i]);
}


