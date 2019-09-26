#include "common.h"

int find_max(RB *ptr, int *data, int *colour)
{
	if(ptr == sentinel)
	{
		return 0;
	}

	RB *temp = ptr;
	while(temp->rchild != sentinel)
	{
		temp = temp->rchild;
	}

	*data = temp->info;
	*colour = temp->color;
	return 1;
}
