#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define HASHSIZE 101

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

static struct nlist *hashtab[HASHSIZE];


unsigned hash(char *s)
{
	unsigned hashval;
	for(hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
       return hashval % HASHSIZE;
}


struct nlist *lookup(char *s)
{
	struct nlist *np;

	for(np =hashtab[hash(s)]; np !=NULL; np = np->next)
	       if(strcmp(s, np->name) == 0)
			return np;
	return NULL;
}


/*char *strdup(char *s)
{
	char *d = malloc(strlen(s) + 1);
	if(d != NULL)
		strcpy(d,s);
	return d;
}
*/

struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
       	unsigned hashval;

	if((np = lookup(name)) == NULL) {
		np = (struct nlist *) malloc (sizeof(*np));	       
		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else
		free((void *) np->defn);
	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}

main()
{
	struct nlist *p = NULL;
	int ch;
	char string[20], value[20];
	while(1){
	printf("Enter 1 to insert 0 to search\n");
	scanf("%d",&ch);
	if(ch == 1){
		printf("Enter the string to store\n");
		scanf("%s",string);
		printf("Enter the value\n");
		scanf("%s", value);
		p = install(string, value);
	}
	else if(ch == 0){
		printf("Enter the string to be searched\n");
		scanf("%s",string);
		if((p =lookup(string)))
			printf("Found %s",p->defn);
		else
			printf("Not found\n");
	}
	else 
		return 0;
	}
}

