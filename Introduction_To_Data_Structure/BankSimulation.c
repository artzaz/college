#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int customer_id;
    char event_type[10];  
    int timestamp;
    struct Node* next;
} Node;

Node* create_node(int customer_id, const char* event_type, int timestamp) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->customer_id = customer_id;
    snprintf(new_node->event_type, sizeof(new_node->event_type), "%s", event_type);
    new_node->timestamp = timestamp;
    new_node->next = NULL;
    return new_node;
}

void append_event(Node** head, int customer_id, const char* event_type, int timestamp) {
    Node* new_node = create_node(customer_id, event_type, timestamp);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void print_event_list(Node* head) {
    Node* temp = head;
    printf("\nEvent list:\n");
    while (temp != NULL) {
        printf("Customer %d - %s at %d\n", temp->customer_id, temp->event_type, temp->timestamp);
        temp = temp->next;
    }
}

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void initialize_queue(Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(Queue* q, int customer_id) {
    Node* new_node = create_node(customer_id, "arrival", 0);
    if (q->rear == NULL) {
        q->front = q->rear = new_node;
        return;
    }
    q->rear->next = new_node;
    q->rear = new_node;
}

// Function to dequeue a customer
int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1; // Queue is empty
    }
    int customer_id = q->front->customer_id;
    Node* temp = q->front;
    q->front = q->front->next;
      
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return customer_id;
}

void display_queue(Queue* q) {
    Node* temp = q->front;
    if (temp == NULL) {
        printf("The queue is currently empty.\n");
        return;
    }
    printf("Current queue: ");
    while (temp != NULL) {
        printf("Customer %d ", temp->customer_id);
        temp = temp->next;
    }
    printf("\n");
}

void customer_arrives(Queue* q, Node** event_list, int* current_time, int* customer_counter) {
    append_event(event_list, *customer_counter, "arrival", *current_time);
    enqueue(q, *customer_counter);
    printf("Customer %d arrives at time %d.\n", *customer_counter, *current_time);
    (*customer_counter)++;
    display_queue(q);
}

void serve_customer(Queue* q, Node** event_list, int* current_time) {
    int customer_id = dequeue(q);
    if (customer_id != -1) {
        append_event(event_list, customer_id, "served", *current_time);
        printf("Customer %d is served at time %d.\n", customer_id, *current_time);
    } else {
        printf("No customers to serve at time %d.\n", *current_time);
    }
    display_queue(q);
}

void detailed_queue_status(Queue* q) {
    printf("\n--- Detailed Queue Status ---\n");
    Node* temp = q->front;
    int position = 1;
    if (temp == NULL) {
        printf("Queue is empty.\n");
    } else {
        while (temp != NULL) {
            printf("Position %d: Customer %d\n", position, temp->customer_id);
            temp = temp->next;
            position++;
        }
    }
    printf("--- End of Status ---\n\n");
}

void simulate_bank(int total_events) {
    Queue q;
    initialize_queue(&q);
    Node* event_list = NULL;
    int current_time = 0;
    int customer_counter = 1;

    for (int i = 0; i < total_events; i++) {
        char action;
        printf("Enter 'a' for arrival or 's' for service: ");
        scanf(" %c", &action);

        if (action == 'a') {
            customer_arrives(&q, &event_list, &current_time, &customer_counter);
        } else if (action == 's') {
            serve_customer(&q, &event_list, &current_time);
        } else {
            printf("Invalid input, please enter 'a' or 's'.\n");
        }
        current_time++;
        detailed_queue_status(&q); 
    }

    print_event_list(event_list);

    // Free event list memory
    Node* temp;
    while (event_list != NULL) {
        temp = event_list;
        event_list = event_list->next;
        free(temp);
    }
}

int main() {
    int num_events;
    printf("Enter the number of events to simulate: ");
    scanf("%d", &num_events);
    simulate_bank(num_events);
    return 0;
}
