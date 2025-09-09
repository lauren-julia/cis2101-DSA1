#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

Stack S;

Stack* initialize();
bool isFull(Stack*);
bool isEmpty(Stack*);
void push(Stack*, int);
int pop(Stack*);
int peek(Stack*);
void display(Stack*);

int main(){
    Stack *s = &S;
    s = initialize(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    display(s);
    
    pop(s);
    printf("Peeking: %d\n", peek(s));
    display(s);
}

Stack* initialize(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = MAX;
    return s;
}

bool isFull(Stack* s){
    return s->top == 0;
}

bool isEmpty(Stack* s){
    return s->top == MAX;
}

void push(Stack* s, int value){
    if(isFull(s)) return;
    
    s->top--;
    s->items[s->top] = value;
}

int pop(Stack* s){
    if(isEmpty(s)) return -1;
    
    int n = s->items[s->top];
    s->top++;
    return n;
}

int peek(Stack* s){
    if(isEmpty(s)) return -1;
    return s->items[s->top];
}

void display(Stack* s){
    if(isEmpty(s)) return;
    
    for(int i = s->top; i < MAX; i++)
        printf("%d -> ", s->items[i]);
    printf("\n");
}
