#include "common.h"

void del(int item)
{
	RB *child, *ptr, *successor;
	if (!find(item, &ptr))
	{
		printf("Item not present\n");
		return;
	}
	
	if (ptr->lchild != sentinel || ptr->rchild != sentinel)
	{
		successor = succ(ptr);
		ptr->info = successor->info;
		ptr = successor;
	}
	
	if (ptr->lchild != sentinel)
	{
		child = ptr->lchild;
	}
	else
	{
		child = ptr->rchild;
	}
	child->parent = ptr->parent;

	if (ptr->parent == sentinel)
	{
		root = child;
	}
	else if (ptr == ptr->parent->lchild)
	{
		ptr->parent->lchild = child;
	}
	else
	{
		ptr->parent->rchild = child;
	}

	if (child == root)
	{
		child->color = black;
	}
	else if (ptr->color == black)
	{
		if (child != sentinel)
		{
			child->color = black;
		}
		else
		{
			del_balance(child);
		}
	}
}


