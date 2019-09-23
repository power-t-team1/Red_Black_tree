#include "common.h"
int main()
{
	node tree = NULL;
	int choice;
	int data;
	while(1)
	{
		printf("Select the option\n1.Insertion\n2.Deletion\n3.Print\n4.Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the data : ");
				scanf("%d", &data);
				insertNode(&tree, data);
				printf("Insertion success\n");
				break;
			case 2:
				printf("Enter the data : ");
				scanf("%d", &data);
				removeNode(&tree, data);
				printf("Deletion success\n");
				break;
			case 3:
				inorderPrint(&tree);
				break;
			case 4:
				return 0;
			default:
				printf("Invalid choice");

		}

	}

	return 0;
}

