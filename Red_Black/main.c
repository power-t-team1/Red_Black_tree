#include "common.h"

int main()
{
	int choice, num;
	sentinel = (RB *)malloc(sizeof(RB));
	sentinel->info = -1;
	sentinel->color = black;
	root = sentinel;

	while(1)
	{
		printf("\n");
		printf("Enter your choice\n1.Insert\n2.Delete\n3.Inorder Traversal\n4.Display\n5.Quit\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:		
					printf("Enter the number to be inserted: ");
					scanf("%d", &num);
					insert(num);
					break;

			case 2:
					printf("Enter the number to be deleted: ");
					scanf("%d", &num);
					del(num);
					break;

			case 3:	
					inorder(root);
					break;

			case 4:
					display(root, 1);
					break;

			case 5:
					exit(0);

			default:
					printf("Enter the correct choice\n");
		}
	}
}

