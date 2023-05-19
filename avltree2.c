#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct treenode {
	int element;
	struct treenode *left;
	struct treenode *right;
	int height;
};

int height(struct treenode *p)
{
	if(p == NULL)
		return -1;
	else
		return p->height;
}

/*Initialize the treenode*/
struct treenode *makenode(struct treenode *p, int data)
{
	p = (struct treenode *) malloc(sizeof (struct treenode));
	if(p == NULL)
		printf("Out of space\n");
	else {
		p -> element = data;
		p -> right = p -> left = NULL;
		p -> height = 0;
	}
	return p;
}

struct treenode *empty(struct treenode *p)
{
	if(p != NULL){
		p -> right = p -> left = NULL;
		free(p);
	}
	return NULL;
}


/*display in post order*/
void display(struct treenode *p)
{
	if(p -> left != NULL)
		display(p -> left);
	if(p -> right != NULL)
		display(p -> right);
	printf("%d\t", p -> element);
}
/*return greatest number*/
int max(int a,int b)						
{
	return a > b ? a : b;
}

/*right rotation */
struct treenode *single_rightrotation(struct treenode *p)	
{
	struct treenode *pivot;
	pivot = p -> left;
	p -> left = pivot -> right;
	pivot -> right = p;

	p -> height = max(height(p -> left), height(p -> right)) + 1;
	pivot -> height = max(height(pivot -> left), height(pivot -> right)) + 1;
	return pivot;						//This will become our new p
}

/*left rotation*/
struct treenode *single_leftrotation(struct treenode *p)
{
	struct treenode *pivot = p -> right;
	p -> right = pivot -> left;
	pivot -> left = p;

	p -> height = max(height(p -> left), height(p -> right)) + 1;
	pivot -> height = max(height(pivot -> left), height(pivot -> right)) + 1;
	return pivot;						//This will become our new p
}

/*left-right case
  **The first rotation is a left rotation with L as the root. The second is a right rotation with P as the root
 */
struct treenode *doublerotation_withleft(struct treenode *p)
{
	p -> left = single_leftrotation(p -> left);
	return single_rightrotation(p);
}

/* right-left case
   The first rotation is a right rotation with R as the root. The second is a left rotation with P as the root */
struct treenode *doublerotation_withright(struct treenode *p)
{
	p -> right = single_rightrotation(p -> right);
	return single_leftrotation(p);
}
struct treenode *second_check_if2(struct treenode *p)
{
	if((height(p -> left -> left) - height(p -> left ->right)) == 1)
		p = single_rightrotation(p);            //single right rotation with p as root is needed
	else
		p = doublerotation_withleft(p);         //left-right case
}

struct treenode *second_check_ifminus2(struct treenode *p)
{
	if((height(p -> right -> left) - height(p -> right ->right)) == -1)
		p = single_leftrotation(p);     //a single left rotation (with P as the root) is needed (Right-Right case).
	else
		p = doublerotation_withright(p);  
}


struct treenode *insert(struct treenode *p, int data)
{
	if(p == NULL)
		p = makenode(p,data);
	else if(data < p -> element) {
			p -> left = insert(p -> left, data);
			if((height(p -> left) - height(p -> right)) == 2)
				p=second_check_if2(p);
	}
	else if(data > p ->element){
		p -> right = insert(p -> right, data);
		if((height(p -> left) - height(p -> right)) == -2)
			p=second_check_ifminus2(p);
	}				
	p -> height = max(height(p ->right), height(p -> left)) + 1;
	return p;
}

struct treenode *lookup(struct treenode *p, int data)
{
	if(p == NULL)
		return NULL;
	if(data < p -> element)
		return lookup(p -> left,data);
	else if(data > p -> element)
		return lookup(p -> right,data);
	else if(data == p -> element){
		printf("Found!!\n");
		return p;
	}
	else {
	       printf("Not found!!\n");	
		return NULL;
	}
}

struct treenode *displaycall(struct treenode *p, int data)
{
	display(p);
}

struct treenode *stop(struct treenode *p, int data)
{
	exit(0);
}

int main()
{
	struct treenode *t;
	int element, choice;
	t = empty(NULL);
	typedef struct treenode *(*func)(struct treenode *, int);
	func fpointers[] = {insert,displaycall,stop};
	while(1){
		printf("\nEnter your choice\t1:insert\t2:display\t3:exit\t");
		scanf("%d",&choice);
		if(choice == 1){
			printf("Enter the element\n");
			scanf("%d",&element);
		}
		t = fpointers[choice-1](t,element);

	}
	return 0;
}
	/*	switch(choice){
			case 1: printf("Enter the element\n");
				scanf("%d",&element);
				t = insert(t, element);
				break;
			case 2: printf("Enter the element\n");
				scanf("%d",&element);
				if(lookup(t, element))
					printf("Found!!\n");
				else
					printf("Not found\n");
				break;
			case 3: printf("Printing in postorder\n");
				display(t);
				break;
			case 4 :exit(0);
			default: printf("Wrong choice\n");
		}
	}
	return 0;
}
*/
