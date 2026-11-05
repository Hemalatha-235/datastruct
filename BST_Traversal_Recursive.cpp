
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

/* Create a new node */
struct Node* createNode(int value) {
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/* Insert an element into BST */
struct Node* insert(struct Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

/* Inorder traversal: Left, Root, Right */
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Preorder traversal: Root, Left, Right */
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Postorder traversal: Left, Right, Root */
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/* Search an element in BST */
struct Node* search(struct Node *root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

/* Free allocated memory */
void freeTree(struct Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node *root = NULL;
    struct Node *result;
    int choice, key, i;

    int elements[] = {
        13, 3, 4, 12, 14, 10, 5, 1,
        8, 2, 7, 9, 11, 6, 18
    };

    int n = sizeof(elements) / sizeof(elements[0]);

    do {
        printf("\n\n----- BINARY SEARCH TREE -----\n");
        printf("1. Create BST\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1:
                freeTree(root);
                root = NULL;

                for (i = 0; i < n; i++)
                    root = insert(root, elements[i]);

                printf("BST created successfully.\n");
                break;

            case 2:
                if (root == NULL)
                    printf("Please create the BST first.\n");
                else {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 3:
                if (root == NULL)
                    printf("Please create the BST first.\n");
                else {
                    printf("Preorder Traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;

            case 4:
                if (root == NULL)
                    printf("Please create the BST first.\n");
                else {
                    printf("Postorder Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 5:
                if (root == NULL) {
                    printf("Please create the BST first.\n");
                } else {
                    printf("Enter the element to search: ");
                    if (scanf("%d", &key) != 1) {
                        freeTree(root);
                        return 1;
                    }

                    result = search(root, key);

                    if (result != NULL)
                        printf("KEY %d is found in the BST.\n", key);
                    else
                        printf("KEY %d is not found in the BST.\n", key);
                }
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 6);

    freeTree(root);
    return 0;
}
