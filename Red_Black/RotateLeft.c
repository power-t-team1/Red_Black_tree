#include "common.h"

void RotateLeft(RB *pptr)
{
	RB *aptr;
	aptr = pptr->rchild;
	pptr->rchild = aptr->lchild;

	if (aptr->lchild != sentinel)
	{
		aptr->lchild->parent = pptr;
	}
	aptr->parent = pptr->parent;

	if (pptr->parent == sentinel)
	{
		root = aptr;
	}
	else if (pptr == pptr->parent->lchild)
	{
		pptr->parent->lchild = aptr;
	}
	else
	{
		pptr->parent->rchild = aptr;
	}
	aptr->lchild = pptr;
	pptr->parent = aptr;
}
