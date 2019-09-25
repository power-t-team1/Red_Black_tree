#include "common.h"

void inorder(RB *ptr)
{
	if (ptr != sentinel)
	{
		inorder(ptr->lchild);
		printf("%d--> ",ptr->info);
		inorder(ptr->rchild);
	}
}
