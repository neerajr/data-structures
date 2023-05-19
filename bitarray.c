#include<stdio.h>
#include <stdlib.h>

#define MAXSIZE 15

void insert (void);
void delete(void);
void ismember(void);

char bitarray[MAXSIZE];// = (char *) calloc(MAXSIZE, sizeof(char));

main ()
{	
	int ch, i;
	
	for (i = 0; i < MAXSIZE; i++)
		bitarray[i] = 0;
	typedef void (*func)(void);
	func fpointers[] = {insert, delete, ismember};

	do{
		printf ("\n1.insert\n2.delete\n3.ismember\npls enter the choice:" );
		scanf ("%d", &ch);
		(*fpointers[ch-1])();
	}while (ch > 0 && ch < 4);
	return 0;
}

void insert()
{
	
	int value;
	printf("Enter value to insert\t");
	scanf("%d", &value);
	if (value) 
		bitarray[value / 8] |= (1 << (7 - value % 8));
	
}

void delete()
{
	int value;
	printf("Enter the value to delete\t");
	scanf("%d", &value);

	bitarray[value / 8] &= ~(1 << (7 - value % 8));
}

void ismember()
{
	int value;
	printf("Enter the value to search\t");	
	scanf("%d", &value);

	if(bitarray[value / 8] & (1 << (7 - value % 8)))
		printf("%d is FOUND..\n", value);
	else
		printf("%d is NOT found..\n", value);
}

