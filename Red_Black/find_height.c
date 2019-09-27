#include "common.h"

int getTreeHeight(RB *root)
{
	int lHeight;
	int rHeight;

	//count nodes while Traversing
	if (root == sentinel)
	{
		return 0;
	}
	// compute the depth of each subtree
	
	lHeight = getTreeHeight(root->lchild);
	rHeight = getTreeHeight(root->rchild);
	
	// use the larger one
	if (lHeight > rHeight) return(lHeight+1);
	else return(rHeight+1);
	
}

