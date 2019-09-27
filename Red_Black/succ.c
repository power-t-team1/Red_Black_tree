#include "common.h"

RB *succ(RB *loc)
{
	RB *ptr = loc->rchild;
	while (ptr->lchild != sentinel)
	{
		ptr = ptr->lchild;
	}
	return ptr;
}
