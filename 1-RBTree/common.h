#ifndef COMMON_H
#define COMMON_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32) && defined(_MSC_VER)
#pragma warning (disable : 4996)
#endif

enum { RED, BLACK };

typedef int COLOR;
typedef int valueType;
typedef struct Node {
	valueType value;
	COLOR color;
	struct Node *right, *left, *parent;
}*node;
typedef node* tree;

node initilize(node, valueType);
node grandparent(node);
node uncle(node);
node sibling(node);
int colorOf(node);
node findNode(tree, valueType);

void insertNode(tree, valueType);
void insertUtil(node);

void removeNode(tree, valueType);
void removeUtil(node);

void rotateRight(node);
void rotateLeft(node);

node findNode(tree, valueType);
void replaceNode(tree, node, node);

void printNode(node n);
void inorderIterator(node n, void(*func)(node));
void inorderPrint(tree t);

void destroy(node);
#endif
