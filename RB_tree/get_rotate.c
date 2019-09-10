#include "common.h"

// Helper functions:

struct Node* GetParent(struct Node* n) 
{
  // Note that parent is set to null for the root node.
  return n->parent;
}

struct Node* GetGrandParent(struct Node* n) 
{
  struct Node* p = GetParent(n);

  // No parent means no grandparent.
  if (p == nullptr) {
    return nullptr;
  }

  // Note: Will be nullptr if parent is root.
  return GetParent(p);
}

struct Node* GetSibling(struct Node* n) 
{
  struct Node* p = GetParent(n);

  // No parent means no sibling.
  if (p == nullptr) {
    return nullptr;
  }

  if (n == p->left) {
    return p->right;
  } else {
    return p->left;
  }
}

struct Node* GetUncle(struct Node* n) 
{
  struct Node* p = GetParent(n);
  struct Node* g = GetGrandParent(n);

  // No grandparent means no uncle
  if (g == nullptr) {
    return nullptr;
  }

  return GetSibling(p);
}

void RotateLeft(struct Node* n) 
{
  struct Node* nnew = n->right;
  struct Node* p = GetParent(n);
 // assert(nnew != nullptr);  // Since the leaves of a red-black tree are empty,
                            // they cannot become internal nodes.
  n->right = nnew->left;
  nnew->left = n;
  n->parent = nnew;
  // Handle other child/parent pointers.
  if (n->right != nullptr) {
    n->right->parent = n;
  }

  // Initially n could be the root.
  if (p != nullptr) {
    if (n == p->left) {
      p->left = nnew;
    } else if (n == p->right) {
      p->right = nnew;
    }
  }
  nnew->parent = p;
}

void RotateRight(struct Node* n) 
{
  struct Node* nnew = n->left;
  struct Node* p = GetParent(n);
  //assert(nnew != nullptr);  // Since the leaves of a red-black tree are empty,
                            // they cannot become internal nodes.

  n->left = nnew->right;
  nnew->right = n;
  n->parent = nnew;

  // Handle other child/parent pointers.
  if (n->left != nullptr) {
    n->left->parent = n;
  }

  // Initially n could be the root.
  if (p != nullptr) {
    if (n == p->left) {
      p->left = nnew;
    } else if (n == p->right) {
      p->right = nnew;
    }
  }
  nnew->parent = p;
}