/*Program:  Write a C program to implement the linked list.*/ 
/*Author:Sushant Pokharel*/
/*Date:2016/07/31*/
/*Refrence:Data structure using C and C++,Chapter-4*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *next;
};
typedef struct node *nodeptr;

nodeptr getnode();
void freenode(nodeptr);
void insertatfirst(nodeptr *,int);
int deletefromfront(nodeptr *);
void displaylist(nodeptr);

int main()
{
	nodeptr p;
    p=NULL;
    insertatfirst(&p,5);
    insertatfirst(&p,6);  
    insertatfirst(&p,7); 
    displaylist(p);
	printf("deleted=%d\n",deletefromfront(&p));
	printf("deleted=%d\n",deletefromfront(&p));
	printf("deleted=%d\n",deletefromfront(&p));
	printf("deleted=%d\n",deletefromfront(&p));
		  
    displaylist(p); 
}

nodeptr getnode()
{
	return (nodeptr)malloc(sizeof(struct node));
}

void freenode(nodeptr p)
{
	free(p);
}

void insertatfirst(nodeptr*p,int x)
{
	nodeptr q;
	q=getnode();
	q->info=x;
	q->next=*p;
	*p=q;
}

void displaylist(nodeptr p)
{
	nodeptr ptr=p;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->info);
		ptr=ptr->next;
	}
	printf("\n");
}

int deletefromfront(nodeptr *p)
{    
	int x;
	if (*p==NULL)
	{
		printf("List underflow\n");
		exit(0);
	}else
	{
		nodeptr q;
	    q=*p;
	    *p=q->next;
	    x=q->info;
	    freenode(q);
		return x;    
	}	
}

