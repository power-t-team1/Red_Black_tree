#include "common.h"

struct Node *insert(struct Node *root, struct Node *n)
{
    // Insert new Node into the current tree.
    InsertRecurse(root, n);

    // Repair the tree in case any of the red-black properties have been violated.
    InsertRepairTree(n);

    // Find the new root to return.
    root = n;
    while (GetParent(root) != nullptr) 
    {
        root = GetParent(root);
    }
    return root;   
}


void InsertRecurse(struct Node* root, struct Node* n)
{
  // Recursively descend the tree until a leaf is found.
  if (root != nullptr && n->key < root->key)
   {
    if (root->left != nullptr)
     {
      InsertRecurse(root->left, n);
      return;
    }
     else 
     {
      root->left = n;
    }
  } 
  else if (root != nullptr) 
  {
    if (root->right != nullptr) 
    {
      InsertRecurse(root->right, n);
      return;
    }
     else
     {
      root->right = n;
    }
  }

  // Insert new Node n.
  n->parent = root;
  n->left = nullptr;
  n->right = nullptr;
  n->color = RED;
}


void InsertRepairTree(struct Node* n) 
{
  if (GetParent(n) == nullptr) 
  {
    InsertCase1(n);
  }
   else if (GetParent(n)->color == BLACK) 
  {
    InsertCase2(n);
  }
   else if (GetUncle(n) != nullptr && GetUncle(n)->color == RED) 
   {
    InsertCase3(n);
  }
   else
    {
    InsertCase4(n);
  }
}