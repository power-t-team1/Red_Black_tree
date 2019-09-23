#include "common.h"

void insertNode(tree t, valueType v)
{
	int pl = 0;
	node ptr, btr = NULL, newNode;

	for (ptr = *t; ptr != NULL;
			btr = ptr, ptr = ((pl = (ptr->value > v)) ? ptr->left : ptr->right));

	newNode = initilize(btr, v);

	if (btr != NULL)
		(pl) ? (btr->left = newNode) : (btr->right = newNode);

	insertUtil(newNode);

	ptr = newNode;
	for (ptr = newNode; ptr != NULL; btr = ptr, ptr = ptr->parent);
	*t = btr;
}
void insertUtil(node n)
{
	node u = uncle(n), g = grandparent(n), p = n->parent;
	if (p == NULL)
		n->color = BLACK;
	else if (p->color == BLACK)
		return;
	else if (u != NULL && u->color == RED)
	{
		p->color = BLACK;
		u->color = BLACK;
		g->color = RED;

		insertUtil(g);
	}
	else
	{
		if (n == p->right && p == g->left)
		{
			rotateLeft(p);
			n = n->left;
		}
		else if (n == p->left && p == g->right)
		{
			rotateRight(p);
			n = n->right;
		}

		g = grandparent(n);
		p = n->parent;

		p->color = BLACK;
		g->color = RED;

		if (n == p->left)
			rotateRight(g);
		else
			rotateLeft(g);
	}
}

