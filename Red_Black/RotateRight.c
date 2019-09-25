#include "common.h"

void RotateRight(RB *pptr)
{
	RB *aptr;
	aptr = pptr->lchild;
	pptr->lchild = aptr->rchild;

	if (aptr->rchild != sentinel)
	{
		aptr->rchild->parent = pptr;
	}
	aptr->parent = pptr->parent;

	if (pptr->parent == sentinel)
	{
		root = aptr;
	}
	else if (pptr == pptr->parent->rchild)
	{
		pptr->parent->rchild = aptr;
	}
	else
	{
		pptr->parent->lchild = aptr;
	}
	aptr->rchild = pptr;
	pptr->parent = aptr;
}
