#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#define nullptr NULL
enum color_t { BLACK, RED };

struct Node {
  struct Node* parent;
  struct Node* left;
  struct Node* right;
  enum color_t color;
  int key;
};
struct Node *bst_delete(struct Node *root, int data);
void inorder(struct Node *root);
struct Node *insert(struct Node *root, struct Node *n);
void InsertRecurse(struct Node* root, struct Node* n);
void InsertRepairTree(struct Node* n);
struct Node* GetParent(struct Node* n);
struct Node* GetGrandParent(struct Node* n);
struct Node* GetSibling(struct Node* n);
struct Node* GetUncle(struct Node* n);
void RotateLeft(struct Node* n);
void RotateRight(struct Node* n);

void InsertCase1(struct Node* n);
void InsertCase2(struct Node* n);
void InsertCase3(struct Node* n);
void InsertCase4(struct Node* n);
void InsertCase4Step2(struct Node* n);

struct Node* find_min(struct Node **root);

#endif