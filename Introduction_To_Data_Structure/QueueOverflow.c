#include <stdio.h>
#define MAX 5  

int queue[MAX];
int front = -1, rear = -1;


int isFull() {
    return (rear == MAX - 1);
}


int isEmpty() {
    return (front == -1 || front > rear);
}

void enqueue(int element) {
    if (isFull()) {
        printf("Queue overflow! Cannot insert %d.\n", element);
        return;
    }
    if (front == -1) front =0;
    queue[++rear] = element;
    printf("Inserted %d\n", element);
}

void dequeue() {
    if (isEmpty()) {
        printf("Qeue underflow! Cannot dequeue.\n");
        return;
        
    }
    printf("Removed %d\n", queue[front++]);
}

int main() {
    
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    
    enqueue(6);
    
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    
    enqueue(7);
    
    return 0;
}
