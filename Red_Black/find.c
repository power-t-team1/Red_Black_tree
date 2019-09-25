#include "common.h"

int find(int item, RB **loc)
{
	RB *ptr;
	if (root == sentinel)
	{
		*loc = sentinel;
		return 0;
	}
	
	if (item == root->info)
	{
		*loc = root;
		return 1;
	}

	if (item < root->info)
	{
		ptr = root->lchild;
	}
	else
	{
		ptr = root->rchild;
	}
	while (ptr != sentinel)
	{
		if (item == ptr->info)
		{
			*loc = ptr;
			return 1;
		}
		if (item < ptr->info)
		{
			ptr = ptr->lchild;
		}
		else
		{
			ptr = ptr->rchild;
		}
	}
	*loc = sentinel;
	return 0;
}
