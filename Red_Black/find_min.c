#include "common.h"

int find_min(RB *ptr, int *data, int *colour)
{
	if(ptr == sentinel)
	{
		return 0;
	}

	RB *temp = ptr;
	while(temp->lchild != sentinel)
	{
		temp = temp->lchild;
	}

	*data = temp->info;
	*colour = temp->color;
	return 1;
}
