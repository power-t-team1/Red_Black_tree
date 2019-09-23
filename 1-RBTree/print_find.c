#include "common.h"
node findNode(tree t, valueType v)
{
	node p;
	for (p = *t; p != NULL && p->value != v; p = (p->value > v ? p->left : p->right));
	return p;
}
void printNode(node n)
{
	printf("%d(%s) ", n->value, (n->color == BLACK ? "b" : "r"));
}
void inorderIterator(node n, void(*func)(node))
{
	if (n == NULL)
		return;
	inorderIterator(n->left, func);
	func(n);
	inorderIterator(n->right, func);
}
void inorderPrint(tree t)
{
	inorderIterator(*t, printNode);
	printf("\n");
}
void destroy(node tree)
{
	if (tree == NULL)
		return;
	destroy(tree->left);
	destroy(tree->right);
	free(tree);
}

