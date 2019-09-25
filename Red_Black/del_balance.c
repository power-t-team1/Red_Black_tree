#include "common.h"

void del_balance(RB *nptr)
{
	RB *sib;
	while (nptr != root)
	{
		if (nptr == nptr->parent->lchild)
		{
			sib = nptr->parent->rchild;
			if (sib->color == red)
			{
				sib->color = black;
				nptr->parent->color = red;
				RotateLeft(nptr->parent);
				sib = nptr->parent->rchild;
			}
			if (sib->lchild->color == black && sib->rchild->color == black)
			{
				sib->color = red;
				if (nptr->parent->color == red)
				{
					nptr->parent->color = black;
					return;
				}
				else
				{
					nptr = nptr->parent;
				}
			}
			else
			{
				if (sib->rchild->color == black)
				{
					sib->lchild->color = black;
					sib->color = red;
					RotateRight(sib);
					sib = nptr->parent->rchild;
				}
				sib->color = nptr->parent->color;
				nptr->parent->color = black;
				sib->rchild->color = black;
				RotateLeft(nptr->parent);
				return;
			}

		}
		else
		{
			sib = nptr->parent->lchild;
			if (sib->color == red)
			{
				sib->color = black;
				nptr->parent->color = red;
				RotateRight(nptr->parent);
				sib = nptr->parent->lchild;
			}

			if (sib->rchild->color == black && sib->lchild->color == black)
			{
				sib->color = red;
				if (nptr->parent->color == red)
				{
					nptr->parent->color = black;
					return;
				}
				else
				{
					nptr = nptr->parent;
				}
			}
			else
			{
				if (sib->lchild->color == black)
				{
					sib->rchild->color = black;
					sib->color = red;
					RotateLeft(sib);
					display(root, 1);
					sib = nptr->parent->lchild;
				}
				sib->color = nptr->parent->color;
				nptr->parent->color = black;
				RotateRight(nptr->parent);
				return;
			}
		}
	}
}
