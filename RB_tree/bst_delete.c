#include "common.h"


struct Node *bst_delete(struct Node *root, int key)
{
	//Creating a temp pointer
	struct Node *temp = NULL;

	//Check if tree empty
	if (root == NULL)
	{
		return root;
	}

	//If key is less than the root node, traverse the left half of the tree
	if (key < (root)->key)
	{
		root->left = bst_delete(root->left, key);
	}
	
	//If key is greater than the root node, traverse the right half of the tree
	else if (key > (root)->key)
	{
		root->right = bst_delete(root->right, key);
	}

	//If key is the same as the root node, the node is to be deleted
	else
	{
		//Check for leaf node
		if ((root)->left == NULL && (root)->right == NULL)
		{
			temp = NULL;
			free(root);
			return temp;
		}
		//Check for node with only one child
		if ((root)->left != NULL && (root)->right == NULL)
		{
			temp = (root)->left;
			free(root);
			return temp;
		}
		
		if ((root)->left == NULL && (root)->right != NULL)
		{
			temp = (root)->right;
			free(root);
			return temp;
		}
		//Node with two children
		else
		{
			temp = find_min(&((root)->right));
			(root)->key = temp->key;
			(root)->right = bst_delete((root)->right, temp->key);
		}

	}
	return root;
}
