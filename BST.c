#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int key;
    struct Node* left;
    struct Node* right;
};
struct Node* insert(struct Node* root, int key)
{
    if (root == NULL)
    {
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key);
    }
    return root;
}
struct Node* minValueNode(struct Node* node)
{
    struct Node* current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
return current;
}
struct Node* deleteNode(struct Node* root, int key)
{
    if(root == NULL)
    {
        return root;
    }
    if(key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if(root->left == NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
    struct Node* temp = minValueNode(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
struct Node* search(struct Node* root, int key)
{
    if (root == NULL || root->key == key)
    {
        return root;
    }
    if (key < root->key)
    {
        return search(root->left, key);
    }
    return search(root->right, key);
}
void inorderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}
void preorderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void postorderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}
int main()
{
    struct Node* root = NULL;
    int choice, key;
    while (1)
    {
        printf("MENU: 1. Insert 2. Delete 3. Search 4. Inorder Traversal 5. Preorder Traversal 6. Postorder Traversal 7. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root,key);
                printf("Key %d inserted successfully.\n", key);
                break;
        case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Key %d deleted successfully.\n", key);
                break;
        case 3:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                struct Node* searchResult = search(root, key);
                if (searchResult != NULL)
                {
                    printf("Key %d found in the BST.\n", key);
                }
                else
                {
                    printf("Key %d not found in the BST.\n", key);
                }
                break;
        case 4:
                printf("Inorder traversal of the BST: ");
                inorderTraversal(root);
                printf("\n");
                break;
        case 5:
                printf("Preorder traversal of the BST: ");
                preorderTraversal(root);
                printf("\n");
                break;
        case 6:
                printf("Postorder traversal of the BST: ");
                postorderTraversal(root);
                printf("\n");
                break;
        case 7:
                printf("Exiting the program.\n");
                exit(0);
        default:
                printf("Invalid choice. Please try again.\n");
    }
    }
return 0;
}
