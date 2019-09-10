#include "common.h"

int main()
{
    //Declare variables here
    int choice, data;
    struct Node *root = NULL, *n = NULL, *minmax = NULL, *temp_parent = NULL;

    //Allocate memory for n
  //  n = malloc(sizeof(struct Node));

    //Select choice
    while(1)
    {
        //Select choice
        printf("Enter the choice : \n");
        printf("1.Insertion\n2.Deletion\n3.Find max\n4.Find min\n5.print\n6.Delete min\n7.Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the data : ");
                scanf("%d", &data);
                  n = malloc(sizeof(struct Node));
                n->key = data;
               /* n->color = RED;
                n->key = data;
                n->left = NULL;
                n->parent = NULL;
                n->right = NULL;*/
                printf("Calling insert\n");
                //Calling the insert function
                root = insert(root, n);
                printf("Insertion success\n");
                break;
            case 2:
            break;
            case 3:
            break;
            case 4:
                minmax = find_min(&root);
                if(minmax)
                {
                    printf("%d-->", minmax->key);
                    if(minmax->color)
                    {
                        printf("red...\n");
                    }
                    else
                    {
                        printf("Black...\n");
                    }
                    
                }
                else
                {
                    printf("Tree empty\n");   /* code */
                }
                
            break;
            case 5:
            inorder(root);
            break;
            case 6:
            minmax = find_min(&root);
            temp_parent = minmax->parent;
            root = bst_delete(root, minmax->key);
            if(temp_parent->right)
            {
                InsertRepairTree(temp_parent->right);
            }
            else
            {
                InsertRepairTree(temp_parent);
            }
            
            
            //InsertRepairTree(root);

            break;
            case 7:
            return 0;
            
            default:
            printf("Invalid option\n");
            
        }

    }
}