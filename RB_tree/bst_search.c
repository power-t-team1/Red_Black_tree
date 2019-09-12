#include "common.h"

//Function definition
int bst_search(struct Node *root, int data)
{
	//Declare variables here
	struct Node *temp = NULL;

	//Check whether list empty or not
	if (root == NULL)
	{
	//	return LIST_EMPTY;
		return 0;
	} 

	//Initialize temp
	temp = root;

	//Traversing tree
	while(temp != NULL)
	{

		if(temp -> key != data)
		{
			//If there is only root node
			if((temp -> left == NULL) && (temp -> right == NULL))
			{
			//	return NO_DATA_FOUND;
			return 0;
			}

			//If data less than temp data
			if(data < temp -> key)
			{
				//Update temp to left side
				temp = temp -> left;
			}

			//If data greater than temp data
			else
			{
				//Update temp to right child
				temp = temp -> right;
			}
		}

		//If data = temp data
		else 
		{
			return 1;
		}
	}

	//If data not found
	return 0;
}
