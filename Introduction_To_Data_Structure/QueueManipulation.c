#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5  // Size of the queue (excluding the extra empty field)

typedef struct {
    int items[MAX_SIZE + 1];  // Queue array with an extra space for differentiating full/empty
    int front, rear;
} Queue;

// Initialize the queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

// Check if the queue is empty
bool isEmpty(Queue *q) {
    return q->front == q->rear;
}

// Check if the queue is full
bool isFull(Queue *q) {
    return (q->rear + 1) % (MAX_SIZE + 1) == q->front;
}

// Enqueue an item into the queue
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    q->items[q->rear] = value;
    q->rear = (q->rear + 1) % (MAX_SIZE + 1);  // Circular increment
    printf("Enqueued: %d\n", value);
}

// Dequeue an item from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;  // Return a sentinel value to indicate an empty queue
    }
    int value = q->items[q->front];
    q->front = (q->front + 1) % (MAX_SIZE + 1);  // Circular increment
    printf("Dequeued: %d\n", value);
    return value;
}

// Print the current state of the queue
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->items[i]);
        i = (i + 1) % (MAX_SIZE + 1);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);  // This will show an error as the queue is full

    printQueue(&q);

    dequeue(&q);  // Removes 10
    dequeue(&q);  // Removes 20

    printQueue(&q);

    enqueue(&q, 60);  // Adds 60

    printQueue(&q);

    dequeue(&q);  // Removes 30
    dequeue(&q);  // Removes 40
    dequeue(&q);  // Removes 50
    dequeue(&q);  // Removes 60

    printQueue(&q);  // Empty queue

    return 0;
}
