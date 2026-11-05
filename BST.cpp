
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

/* Create a new node */
struct Node* createNode(int value) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = newNode->right = NULL;

    return newNode;
}

/* Insert an element into the BST */
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

/* Find the minimum-value node */
struct Node* findMin(struct Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

/* Delete an element from the BST */
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        /* Node has no left child */
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        /* Node has no right child */
        if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        /* Node has two children */
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

/* Search for a key */
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

/* Inorder traversal */
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Free all nodes */
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

/* Main function */
int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\n--- BST Operations Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display (Inorder)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                if (scanf("%d", &value) != 1)
                    goto cleanup;
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                if (scanf("%d", &value) != 1)
                    goto cleanup;
                root = deleteNode(root, value);
                break;

            case 3:
                printf("Enter value to search: ");
                if (scanf("%d", &value) != 1)
                    goto cleanup;

                if (search(root, value) != NULL)
                    printf("%d found in the BST.\n", value);
                else
                    printf("%d not found in the BST.\n", value);
                break;

            case 4:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);

cleanup:
    freeTree(root);
    return 0;
}
