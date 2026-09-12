#include <stdio.h>
#include <stdlib.h>

/* Linked list node */
struct Node {
    int data;
    struct Node *next;
};

int main() {

    printf("===== DYNAMIC MEMORY AND LINKED LIST DEMO =====\n");

    /* Dynamic array */
    int capacity = 3;
    int size = 0;

    int *buffer = malloc(capacity * sizeof(int));

    if (buffer == NULL) {
        printf("Initial memory allocation failed\n");
        return 1;
    }

    printf("\nInitial buffer capacity: %d\n", capacity);

    /* Add elements */
    for (int i = 0; i < 6; i++) {

        /* Resize before buffer becomes full */
        if (size == capacity) {
            capacity *= 2;

            int *temp = realloc(buffer, capacity * sizeof(int));

            if (temp == NULL) {
                printf("Memory reallocation failed\n");
                free(buffer);
                return 1;
            }

            buffer = temp;

            printf("Buffer resized. New capacity: %d\n",
                   capacity);
        }

        buffer[size] = (i + 1) * 10;
        size++;
    }

    /* Display dynamic array */
    printf("\nDynamic Array Elements:\n");

    for (int i = 0; i < size; i++) {
        printf("%d ", buffer[i]);
    }

    printf("\n");

    /* Linked list */
    struct Node *head = NULL;
    struct Node *tail = NULL;

    printf("\nCreating linked list...\n");

    for (int i = 0; i < size; i++) {

        struct Node *newNode =
            malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Linked list memory allocation failed\n");

            /* Free linked list */
            struct Node *current = head;

            while (current != NULL) {
                struct Node *temp = current;
                current = current->next;
                free(temp);
            }

            free(buffer);
            return 1;
        }

        newNode->data = buffer[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    /* Display linked list */
    printf("\nLinked List:\n");

    struct Node *current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");

    /* Free linked list memory */
    current = head;

    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    /* Free dynamic array */
    free(buffer);

    printf("\nAll dynamically allocated memory freed.\n");
    printf("Program completed successfully.\n");

    return 0;
}
