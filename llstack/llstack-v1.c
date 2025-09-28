#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

Stack* initialize();
bool isFull(Stack*);
bool isEmpty(Stack*);
void push(Stack*, int);
int pop(Stack*);
int peek(Stack*);
void display(Stack*);
Node* createNode(int);

int main(){
    Stack* s = initialize();

    push(s, 10);
    push(s, 20);
    push(s, 30);
    display(s);

    printf("Peek: %d\n", peek(s));
    printf("Pop: %d\n", pop(s));
    display(s);

    printf("Pop: %d\n", pop(s));
    printf("Pop: %d\n", pop(s));
    printf("Pop: %d\n", pop(s));
}

Stack* initialize(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

bool isFull(Stack* s){
    return false;
}

bool isEmpty(Stack* s){
    return s->top == NULL;
}

void push(Stack* s, int value){
    Node* newNode = createNode(value);

    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s){
    if (isEmpty(s)) return -1;

    Node* temp = s->top;
    int popped = temp->data;
    s->top = temp->next;
    free(temp);

    return popped;
}

int peek(Stack* s){
    if (isEmpty(s)) return -1;
    return s->top->data;
}

void display(Stack* s){
    for(Node* trav = s->top; trav != NULL; trav = trav->next)
        printf("%d ", trav->data);
    printf("\n");
}

Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


