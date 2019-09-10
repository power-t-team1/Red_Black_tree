#include "common.h"

void inorder(struct Node *root)
{
	if (root)
	{
		inorder(root->left);
		printf("%d-->", root->key);
		if(root->color)
		{
			printf("Red....");
		}
		else
		{
			printf("black....");
		}
		
		inorder(root->right);
	}
}
