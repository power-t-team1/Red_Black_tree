#include "common.h"
node initilize(node p, valueType v)
{
	node tree = (node)malloc(sizeof(struct Node));
	tree->left = tree->right = NULL;
	tree->parent = p;
	tree->value = v;
	tree->color = RED;
	return tree;
}
node grandparent(node n)
{
	if (n == NULL || n->parent == NULL)
		return NULL;
	return n->parent->parent;
}
node uncle(node n)
{
	node g = grandparent(n);
	if (n == NULL || g == NULL)
		return NULL;
	if (n->parent == g->left)
		return g->right;
	else
		return g->left;
}
node sibling(node n)
{
	if (n == n->parent->left)
		return n->parent->right;
	else
		return n->parent->left;
}
int colorOf(node n)
{
	return n == NULL ? BLACK : n->color;
}

