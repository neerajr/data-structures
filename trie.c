#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct trienode {
	int element;
	struct trienode *next[25];
};

int find_index(char *s)
{
	return *s - 'a';
}

struct trienode *makenode(struct trienode *p, int data, char *s)
{
	int i;
	p = (struct trienode *) malloc(sizeof (struct trienode));
	if (p == NULL)
		printf("Out of space\n");
	else {
		for(i = 0; i < 26; ++i)
			p -> next[i] == NULL;
		p -> element = 0;
	}
	return p;
}

struct trienode *search(struct trienode *p , char *s)
{
	if (p == NULL){
		printf("Not found\n");
		return NULL;
	}
	else{
		if (*s != '\0')
			p -> next[find_index(s)] = search(p ->next[find_index(s)], s+1);
		if (*s == '\0'){
			if(p -> element != 0)
				printf("Found!!value: %d\n",p -> element);
			else
				printf("Not found\n");
			return p;
		}
	}
	return p;
}

struct trienode *insert(struct trienode *p, int data, char *s)
{
	int i =0;
	if (p == NULL)
		p = makenode(p , 0, s);
	if (*s != '\0')
		p -> next[find_index(s)] = insert(p -> next[find_index(s)], data, s+1);
	if (*s == '\0'){
		p -> element = data;
		return p;
	}
	return p;
}
		
main()
{
	struct trienode *t;
	int value, choice;
	char key[100];
	t = 0;
	while(1){
		printf("\nEnter your choice\t1:insert\t2:search\t3:exit\t");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter the string\n");
				scanf("%s",key);
				printf("Enter value\n");
				scanf("%d",&value);
				t = insert(t,value,key);
				break;
			case 2: printf("Enter the string\n");
				scanf("%s",key);
				search(t,key);
				break;
			case 3: exit(0);
			default: printf("Wrong choice\n");
		}
	}
	return 0;
}

