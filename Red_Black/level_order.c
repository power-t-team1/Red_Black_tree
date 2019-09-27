#include "common.h"

void levelorder(RB *root)
{
    int h = getTreeHeight(root);
    int i;
    for(i = 1; i <= h; i++)
    {
        G_level_order(root, i);
        printf("\n");
    }
}

void G_level_order(RB *root, int level)
{
        if(root == sentinel)
        {
            return;
        }
        if(level == 1)
        {
            printf("%d ", root->info);
            if (root->color == red)
		    {
			    printf("(Red) ");
		    }
		    else
	    	{
		    	printf("(Black) ");
	    	}
        }
        else if(level > 1)
        {
            G_level_order(root->lchild, level-1);
            G_level_order(root->rchild, level-1);
        }   
}
