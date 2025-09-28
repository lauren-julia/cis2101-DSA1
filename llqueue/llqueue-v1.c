#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* initialize();
bool isFull(Queue*);
bool isEmpty(Queue*);
void enqueue(Queue*, int);
int dequeue(Queue*);
int front(Queue*);
void display(Queue*);

int main(){
    Queue* q = initialize();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);

    printf("Front: %d\n", front(q));
    printf("Dequeue: %d\n", dequeue(q));
    display(q);

    printf("Dequeue: %d\n", dequeue(q));
    printf("Dequeue: %d\n", dequeue(q));
    printf("Dequeue: %d\n", dequeue(q)); 
}

Queue* initialize(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isFull(Queue* q){
    return false;
}

bool isEmpty(Queue* q){
    return (q->front == NULL);
}

void enqueue(Queue* q, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear) 
        q->rear->next = newNode;
    else 
        q->front = newNode;

    q->rear = newNode;
}

int dequeue(Queue* q){
    if (isEmpty(q)) return -1;

    Node* temp = q->front;
    int value = temp->data;

    q->front = temp->next;
    if (q->front == NULL) q->rear = NULL;

    free(temp);
    return value;
}

int front(Queue* q){
    if (isEmpty(q)) return -1;
    return q->front->data;
}

void display(Queue* q){
    for(Node* trav = q->front; trav != NULL; trav = trav->next)
        printf("%d ", trav->data);
    printf("\n");
}




