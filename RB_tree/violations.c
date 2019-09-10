#include "common.h"

void InsertCase1(struct Node* n)
 {
  if (GetParent(n) == nullptr) {
    n->color = BLACK;
  }
}

void InsertCase2(struct Node* n) 
{
  // Do nothing since tree is still valid.
  return;
}

void InsertCase3(struct Node* n) 
{
  GetParent(n)->color = BLACK;
  GetUncle(n)->color = BLACK;
  GetGrandParent(n)->color = RED;
  InsertRepairTree(GetGrandParent(n));
}

void InsertCase4(struct Node* n) 
{
  struct Node* p = GetParent(n);
  struct Node* g = GetGrandParent(n);

  if (n == p->right && p == g->left) {
    RotateLeft(p);
    n = n->left;
  } else if (n == p->left && p == g->right) {
    RotateRight(p);
    n = n->right;
  }

  InsertCase4Step2(n);
}

void InsertCase4Step2(struct Node* n) 
{
  struct Node* p = GetParent(n);
  struct Node* g = GetGrandParent(n);

  if (n == p->left) {
    RotateRight(g);
  } else {
    RotateLeft(g);
  }
  p->color = BLACK;
  g->color = RED;
}
