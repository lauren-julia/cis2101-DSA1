#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int count;
} List;

List* initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);

struct Node* createNode(int data);
void deleteNode(struct Node **node, List *list);

int main(){
    List *list;
    list = initialize();
    
    insertFirst(list, 2);
    insertLast(list, 3);
    insertPos(list, 1, 0);
    insertLast(list, 4);
    insertLast(list, 5);
    display(list);
    
    deleteStart(list);
    deleteLast(list);
    deletePos(list, 1);
    display(list);
    
    printf("[Locating]   The index of value 4: %d\n", locate(list, 4));
    printf("[Retrieving] The value at index 1: %d\n", retrieve(list, 1));
}

List* initialize(){
    List *list = (List *)malloc(sizeof(List));
    list->head = NULL;
    list->count = 0;
    return list;
}

//separate function for creating node
struct Node* createNode(int data) {                        
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//separate function for deleting node
void deleteNode(struct Node **node, List *list){
    if (*node == NULL) return;

    struct Node *temp = *node;
    *node = temp->next;
    free(temp);

    list->count--;
}

void empty(List *list){
    for(struct Node *trav = list->head; list->head != NULL;){
        trav = list->head;
        list->head = list->head->next;
        free(trav);
    }
    list->count = 0;
}

void insertFirst(List *list, int data){
    struct Node *newNode = createNode(data);
    
    newNode->next = list->head;
    list->head = newNode;     
    
    list->count++;
}

void insertLast(List *list, int data){
    struct Node *newNode = createNode(data);
    
    struct Node **trav = &list->head;
    for(; *trav != NULL; trav = &(*trav)->next){}
    
    *trav = newNode;   

    list->count++;
}

void insertPos(List *list, int data, int index){
    struct Node *newNode = createNode(data);
    
    struct Node **trav = &list->head;
    for(int i = 0; *trav != NULL && i < index; trav = &(*trav)->next, i++){}

    newNode->next = *trav;
    *trav = newNode;

    list->count++;
}

void deleteStart(List *list){
    if (list->head == NULL) return;
    deleteNode(&list->head, list);
}

void deleteLast(List *list){
    if(list->head == NULL) return;
    
    struct Node **trav = &list->head;
    for(; (*trav)->next != NULL; trav = &(*trav)->next){}

    deleteNode(trav, list);
}

void deletePos(List *list, int index){
     if(list->head == NULL) return;
    
    struct Node **trav = &list->head;
    for(int i = 0; *trav != NULL && i < index; trav = &(*trav)->next, i++){}

    if(*trav == NULL) return;
    deleteNode(trav, list);
}

int retrieve(List *list, int index){
    struct Node *trav = list->head;
    for (int i = 0; i < index; i++, trav = trav->next) {}

    return trav->data;
}

int locate(List *list, int data){
     if(list->head == NULL) return -1;
     
    struct Node *trav = list->head;
    for(int i = 0; i < list->count; i++, trav = trav->next){
        if (trav->data == data) 
            return i;
    }
    
    return -1;
}

void display(List *list){
    for(struct Node *trav = list->head; trav != NULL; trav = trav->next)
        printf("%d -> ", trav->data);   
    printf("NULL\n");       
}

