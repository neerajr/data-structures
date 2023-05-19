#include<stdio.h>
void selectsort(int v[], int n)
{
	int i, min, pos, temp;
	for(pos= 0; pos<n; pos++) {
		min = pos;
		for(i = pos+1; i<n; i++){
			if(v[i] < v[min])
				min = i;
		}
		if(min != pos){
			temp = v[min];
			v[min] = v[pos];
			v[pos] = temp;
		}
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
	selectsort(v,right);
	printf("Sorted array is\n");
	for(i =0; i< right; i++)
		printf("%d\t",v[i]);
}


