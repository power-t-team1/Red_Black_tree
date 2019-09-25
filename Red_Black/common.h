#ifndef COMMON_H
#define COMMON_H

//Include header file
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	enum {black, red} color;
	int info;
	struct node *lchild;
	struct node *rchild;
	struct node *parent;
}RB;

int find(int item, RB **loc);
void insert(int);
void insert_balance(RB *nptr);
void del(int);
void del_balance(RB *ptr);
void RotateLeft(RB *ptr);
void RotateRight(RB *ptr);
RB *succ(RB *ptr);
void inorder(RB *ptr);
void display(RB *ptr, int level);
RB *root;
RB *sentinel;

#endif
