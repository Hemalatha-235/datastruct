
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Structure of a BST node */
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

/* Stack */
struct Node *stack[MAX];
int top = -1;

/* Push a node */
void push(struct Node *node) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = node;
}

/* Pop a node */
struct Node* pop() {
    if (top == -1)
        return NULL;

    return stack[top--];
}

/* Check whether stack is empty */
int isEmpty() {
    return top == -1;
}

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

/* Insert into BST */
struct Node* insert(struct Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

/* Non-recursive Inorder: Left, Root, Right */
void inorder(struct Node *root) {
    struct Node *current = root;

    while (current != NULL || !isEmpty()) {
        while (current != NULL) {
            push(current);
            current = current->left;
        }

        current = pop();
        printf("%d ", current->data);
        current = current->right;
    }
}

/* Non-recursive Preorder: Root, Left, Right */
void preorder(struct Node *root) {
    struct Node *current;

    if (root == NULL)
        return;

    push(root);

    while (!isEmpty()) {
        current = pop();
        printf("%d ", current->data);

        if (current->right != NULL)
            push(current->right);

        if (current->left != NULL)
            push(current->left);
    }
}

/* Non-recursive Postorder: Left, Right, Root */
void postorder(struct Node *root) {
    struct Node *current = root;
    struct Node *lastVisited = NULL;

    while (current != NULL || !isEmpty()) {
        if (current != NULL) {
            push(current);
            current = current->left;
        } else {
            current = stack[top];

            if (current->right != NULL &&
                lastVisited != current->right) {
                current = current->right;
            } else {
                printf("%d ", current->data);
                lastVisited = current;
                pop();
                current = NULL;
            }
        }
    }
}

/* Free the BST */
void freeTree(struct Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node *root = NULL;

    int elements[] = {
        6, 9, 5, 2, 8, 15,
        24, 14, 7, 8, 5, 2
    };

    int n = sizeof(elements) / sizeof(elements[0]);
    int choice, i;

    do {
        printf("\n\n----- BINARY SEARCH TREE -----\n");
        printf("1. Create BST\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
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
                if (root == NULL) {
                    printf("Please create the BST first.\n");
                } else {
                    top = -1;
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 3:
                if (root == NULL) {
                    printf("Please create the BST first.\n");
                } else {
                    top = -1;
                    printf("Preorder Traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;

            case 4:
                if (root == NULL) {
                    printf("Please create the BST first.\n");
                } else {
                    top = -1;
                    printf("Postorder Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 5);

    freeTree(root);
    return 0;
}
