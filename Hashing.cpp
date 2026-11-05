
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int linearTable[TABLE_SIZE];
int quadraticTable[TABLE_SIZE];

struct Node {
    int key;
    struct Node *next;
};

struct Node *chainTable[TABLE_SIZE];

int hashFunction(int key) {
    return ((key % TABLE_SIZE) + TABLE_SIZE) % TABLE_SIZE;
}

/* Linear Probing */
void initLinear() {
    for (int i = 0; i < TABLE_SIZE; i++)
        linearTable[i] = -1;
}

void insertLinear(int key) {
    int index = hashFunction(key);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int probe = (index + i) % TABLE_SIZE;

        if (linearTable[probe] == -1) {
            linearTable[probe] = key;
            printf("Key %d inserted at index %d.\n",
                   key, probe);
            return;
        }
    }

    printf("Hash table is full!\n");
}

void displayLinear() {
    printf("\nLinear Probing Table:\n");
    printf("Index\tValue\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (linearTable[i] == -1)
            printf("%d\t-\n", i);
        else
            printf("%d\t%d\n", i, linearTable[i]);
    }
}

/* Quadratic Probing */
void initQuadratic() {
    for (int i = 0; i < TABLE_SIZE; i++)
        quadraticTable[i] = -1;
}

void insertQuadratic(int key) {
    int index = hashFunction(key);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int probe = (index + i * i) % TABLE_SIZE;

        if (quadraticTable[probe] == -1) {
            quadraticTable[probe] = key;
            printf("Key %d inserted at index %d.\n",
                   key, probe);
            return;
        }
    }

    printf("No free slot found for key %d.\n", key);
}

void displayQuadratic() {
    printf("\nQuadratic Probing Table:\n");
    printf("Index\tValue\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (quadraticTable[i] == -1)
            printf("%d\t-\n", i);
        else
            printf("%d\t%d\n", i, quadraticTable[i]);
    }
}

/* Separate Chaining */
void initChaining() {
    for (int i = 0; i < TABLE_SIZE; i++)
        chainTable[i] = NULL;
}

void insertChaining(int key) {
    int index = hashFunction(key);

    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->key = key;
    newNode->next = NULL;

    if (chainTable[index] == NULL) {
        chainTable[index] = newNode;
    } else {
        struct Node *temp = chainTable[index];

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Key %d inserted at index %d.\n", key, index);
}

void displayChaining() {
    printf("\nSeparate Chaining Table:\n");
    printf("Index\tChain\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node *temp = chainTable[i];

        printf("%d\t", i);

        if (temp == NULL) {
            printf("-\n");
            continue;
        }

        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

/* Main Function */
int main() {
    int choice, key;

    initLinear();
    initQuadratic();
    initChaining();

    while (1) {
        printf("\n--- HASHING TECHNIQUES ---\n");
        printf("1. Insert using Linear Probing\n");
        printf("2. Insert using Quadratic Probing\n");
        printf("3. Insert using Separate Chaining\n");
        printf("4. Display Linear Probing Table\n");
        printf("5. Display Quadratic Probing Table\n");
        printf("6. Display Separate Chaining Table\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1:
            case 2:
            case 3:
                printf("Enter key to insert: ");

                if (scanf("%d", &key) != 1)
                    return 1;

                if (choice == 1)
                    insertLinear(key);
                else if (choice == 2)
                    insertQuadratic(key);
                else
                    insertChaining(key);

                break;

            case 4:
                displayLinear();
                break;

            case 5:
                displayQuadratic();
                break;

            case 6:
                displayChaining();
                break;

            case 7:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
