#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
typedef struct Node {
    int info;           // The data element
    struct Node *next;  // Pointer to the next node
} Node;

// Definition of the header node structure
typedef struct HeaderNode {
    Node *info;         // Pointer to the first node in the list
} HeaderNode;

// Function to create a new node
Node* createNode(int x) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->info = x;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to search for a node containing element x
Node* search(HeaderNode *header, int x) {
    Node *current = header->info;  // Start from the first node

    // Traverse the list
    while (current != NULL) {
        if (current->info == x) {
            return current;  // Return the pointer to the node containing x
        }
        current = current->next;  // Move to the next node
    }

    return NULL;  // Return NULL if x is not found
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(HeaderNode *header, int x) {
    Node *newNode = createNode(x);
    if (newNode) {
        newNode->next = header->info;  // New node points to the old first node
        header->info = newNode;        // Update header to point to the new first node
    }
}

// Function to print the list
void printList(HeaderNode *header) {
    Node *current = header->info;
    while (current != NULL) {
        printf("%d -> ", current->info);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a header node
    HeaderNode header;
    header.info = NULL;  // Initialize the list as empty

    // Insert elements into the list
    insertAtBeginning(&header, 10);
    insertAtBeginning(&header, 20);
    insertAtBeginning(&header, 30);
    insertAtBeginning(&header, 40);

    // Print the list
    printf("List: ");
    printList(&header);

    // Search for element 20 in the list
    int searchElement = 20;
    Node *result = search(&header, searchElement);

    if (result) {
        printf("Element %d found in the list.\n", searchElement);
    } else {
        printf("Element %d not found in the list.\n", searchElement);
    }

    return 0;
}
