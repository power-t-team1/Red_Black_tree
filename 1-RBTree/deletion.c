#include "common.h"
void replaceNode(tree t, node o, node n)
{
	if (o->parent == NULL)
		*t = n;
	else
	{
		if (o == o->parent->left)
			o->parent->left = n;
		else
			o->parent->right = n;
	}

	if (n != NULL)
		n->parent = o->parent;
}
void removeNode(tree t, valueType v)
{
	node n = findNode(t, v), c;

	if (n == NULL)
		return;
	if (n->left != NULL && n->right != NULL)
	{
		node pred = n->left;
		while (pred->right != NULL)
			pred = pred->right;
		n->value = pred->value;
		n = pred;
	}

	c = n->right == NULL ? n->left : n->right;
	if (n->color == BLACK)
	{
		n->color = colorOf(c);
//		replaceNode(t, n, c);
		removeUtil(n);
	}

	replaceNode(t, n, c);
	free(n);
}
void removeUtil(node n)
{
	if (n->parent == NULL)
		return;

	node s = sibling(n);
	if (colorOf(s) == RED)
	{
		n->parent->color = RED;
		s->color = BLACK;
		if (n == n->parent->left)
			rotateLeft(n->parent);
		else
			rotateRight(n->parent);
	}

	s = sibling(n);
	if (colorOf(n->parent) == BLACK && colorOf(s) == BLACK &&
			colorOf(s->left) == BLACK && colorOf(s->right) == BLACK)
	{
		s->color = RED;
		removeUtil(n->parent);
	}
	else if (colorOf(n->parent) == RED && colorOf(s) == BLACK &&
			colorOf(s->left) == BLACK && colorOf(s->right) == BLACK)
	{
		s->color = RED;
		n->parent->color = BLACK;
	}
	else
	{
		if (n == n->parent->left && colorOf(s) == BLACK &&
				colorOf(s->left) == RED && colorOf(s->right) == BLACK)
		{
			s->color = RED;
			s->left->color = BLACK;
			rotateRight(s);
		}
		else if (n == n->parent->right && colorOf(s) == BLACK &&
				colorOf(s->right) == RED && colorOf(s->left) == BLACK)
		{
			s->color = RED;
			s->right->color = BLACK;
			rotateLeft(s);
		}

		s->color = colorOf(n->parent);
		n->parent->color = BLACK;
		if (n == n->parent->left)
		{
			s->right->color = BLACK;
			rotateLeft(n->parent);
		}
		else
		{
			s->left->color = BLACK;
			rotateRight(n->parent);
		}
	}
}

