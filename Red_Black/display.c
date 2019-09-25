#include "common.h"

void display(RB *ptr, int level)
{
	int i;
	
	if(ptr != sentinel)
	{
		display(ptr->lchild, level+1);
	/*	for (i = 0; i < level; i++)
		{
			printf("  ");
		}
	*/	printf(" %d", ptr->info);
		if (ptr->color == red)
		{
			printf("(Red)-->");
		}
		else
		{
			printf("(Black)-->");
		}
		display(ptr->rchild, level+1);
	}
}
