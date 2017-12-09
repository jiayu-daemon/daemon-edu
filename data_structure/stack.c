#include "stack.h"

node * head = NULL;

node * mk_node(int item)
{
	node *p = (node *) malloc(sizeof(node));
	p->item = item;

	return p;
}


void free_node(node * p)
{
	free(p);
}


void insert(node * p)
{
	p->next = head;
	head = p;
}


void traverse()
{
	node * p = head;
	while(p != NULL){
		printf("%d ",p->item);
		p = p->next;
	}
	printf("\n");
}


node * find(int item)
{

	node * p = head;
	while(p != NULL)
	{
		if(p->item == item){
			return p;
		}
		p = p->next;
	}
	return NULL;
}

int delete_node(node * p)
{
	if(head == p){
		head = head->next;
		return 1;
	}
	node * pre = head;
	while(pre->next != NULL)
	{
		if(pre->next == p)
		{
			pre->next = p->next;
			return 1;
		}
		pre = pre->next;
	}

	return 0;
}


void destroy()
{
	node *p;
	while(head != NULL)
	{
		p = head;
		head = head->next;
		free_node(p);
	}
}


void push(int i)
{
	node *p = mk_node(i);
	insert(p);
}

int pop()
{
	node *p = head;
	head = head->next;

	int item = p->item;
	free_node(p);

	return item;
}

int is_empty()
{
	if(head == NULL){
		return 1;
	}else{
		return 0;
	}
}


int main()
{
	push(1);
	push(2);
	push(3);

	while(!is_empty()){
		printf("%d\n",pop());
	}

	return 0;
}


