#include "common.h"

void insert(int ikey)
{
	RB *tmp, *ptr, *par;
	par = sentinel;
	ptr = root;
	while (ptr != sentinel)
	{
		par = ptr;
		if (ikey < ptr->info)
		{
			ptr = ptr->lchild;
		}
		else if (ikey > ptr->info)
		{
			ptr = ptr->rchild;
		}
		else
		{
			printf("Duplicate\n");
			return;
		}
	}
	tmp = (RB *)malloc(sizeof(RB));
	tmp->info = ikey;
	tmp->lchild = sentinel;
	tmp->rchild = sentinel;
	tmp->color = red;
	tmp->parent = par;
	if (par == sentinel)
	{
		root = tmp;
	}
	else if (tmp->info < par->info)
	{
		par->lchild = tmp;
	}
	else
	{
		par->rchild = tmp;
	}
	insert_balance(tmp);
}
