#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;


Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}


void enqueue(Queue* queue, int value) {
    Node* newNode = createNode(value);
    if (queue->rear == NULL) {

        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}


void dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty, cannot dequeue.\n");
        return;
    }
    Node* temp = queue->front;
    queue->front = queue->front->next;


    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    printf("Dequeued: %d\n", temp->data);
    free(temp);
}


void display(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node* current = queue->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


int main() {
    Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);  
    free(queue);     
    return 0;
}
