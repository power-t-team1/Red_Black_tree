#include "common.h"

void insert_balance(RB *nptr)
{
	RB *uncle, *par, *grandpar;
	while (nptr->parent->color == red)
	{
		par = nptr->parent;
		grandpar = par->parent;
		if (par == grandpar->lchild)
		{
			uncle = grandpar->rchild;
			if (uncle->color == red)
			{
				par->color = black;
				uncle->color = black;
				grandpar->color = red;
				nptr = grandpar;
			}
			else
			{
				if (nptr == par->rchild)
				{
					RotateLeft(par);
					nptr = par;
					par = nptr->parent;
				}
				par->color = black;
				grandpar->color = red;
				RotateRight(grandpar);
			}
		}
		else
		{
			if (par == grandpar->rchild)
			{
				uncle = grandpar->lchild;
				if (uncle->color == red)
				{
					par->color = black;
					uncle->color = black;
					grandpar->color = red;
					nptr = grandpar;
				}
				else
				{
					if (nptr == par->lchild)
					{
						RotateRight(par);
						nptr = par;
						par = nptr->parent;
					}
					par->color = black;
					grandpar->color = red;
					RotateLeft(grandpar);
				}
			}

		}

	}
	root->color = black;
}
