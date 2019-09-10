/*#include "main.h"

int find_max(tree_t **root, data_t *data)
{
	//Check for tree empty
	if (*root == NULL)
	{
		return FAILURE;
	}

	//Assigning the root value to a temp pointer
	tree_t *temp = *root;

	//Traverse to the rightmost element
	while (temp->RC != NULL)
	{
		temp = temp->RC;
	}
	
	//Assigning the value of maximum data to the variable
	*data = temp->data;
	return SUCCESS;
}
*/