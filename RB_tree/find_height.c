/*#include "main.h"

int find_height(tree_t *root)
{
	int LC_height;
	int RC_height;

	//Base case and validation for one node with LC and RC NULL
	if (root == NULL)
	{
		return 0;
	}

	//Recursively traverse to the bottom of the tree
	LC_height = find_height(root->LC);
	RC_height = find_height(root->RC);

	//Assign the higher value to the variable
	if (LC_height > RC_height)
	{
		return LC_height + 1;
	}
	else
	{
		return RC_height + 1;
	}
}
*/