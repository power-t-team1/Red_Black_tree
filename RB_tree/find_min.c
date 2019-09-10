#include "common.h"

struct Node* find_min(struct Node **root)
{
	//Check for tree empty
	if (*root == NULL)
	{
		
		return nullptr;
	}

	//Assigning the root value to a temp pointer
	struct Node *temp = *root;

	//Traverse to the leftmost element
	while (temp->left != NULL)
	{
		temp = temp->left;
	}
	
	//Assigning the value of minimum data to the variable
	
	return temp;
}
