#include "single_list.h"

node * head = NULL;

node * mk_node(int item)
{
	node *p = (node *)malloc(sizeof(node));
	p->item = item;

	return p;
}

void free_node(node *p)
{
	free(p);
}


void insert(node * p)
{
	p->next = head;
	head = p;
}


void insert_sort_l2b(node * p)
{
	if(head == NULL)
	{
		p->next = head;
		head = p;
		return ;
	}

	if(p->item < head->item)
	{
		p->next = head;
		head = p;
		return ;
	}

	node * pre = head;
	while(pre->next != NULL)
	{
		if((p->item > pre->item) && (p->item < pre->next->item))
		{
			p->next = pre->next;
			pre->next = p;

			return ;
		}
		pre = pre->next;
	}

	p->next = pre->next;
	pre->next = p;

	return;
}


void traverse()
{
	node *p = head;
	while(p != NULL)
	{
		printf("%d ", p->item);
		p = p->next;
	}
	printf("\n");
}



node * find(int item)
{
	node *p = head;
	while(p != NULL)
	{
		if(p->item == item)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}



int delete_node(node * p)
{
	if(head == p)
	{
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


void reverse()
{
	node *nhead = NULL;
	node *p;

	while(head != NULL)
	{
		p = head;
		head = head->next;

		p->next = nhead;
		nhead = p;
	}

	head = nhead;
}





int main()
{

	node *p = mk_node(1);
	insert_sort_l2b(p);
	traverse();

	p = mk_node(-1);
	insert_sort_l2b(p);
	traverse();

	p = mk_node(0);
	insert_sort_l2b(p);
	traverse();

	p = mk_node(-3);
	insert_sort_l2b(p);
	traverse();

	p = find(1);
	if(p != NULL)
	{
		delete_node(p);
		free_node(p);
	}
	traverse();

	printf("reverse...\n");
	reverse();
	traverse();

	return 0;
}
