/* ARRAY LIST - Variation 4 - Dynamic, by Pointer */

#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

List L;

void initialize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);
int retrieve(List *L, int position);
void insertSorted(List *L, int data);
void display(List *L);
void resize(List *L);
void makeNULL(List *L);

int main(){
    initialize(&L);

    insertPos(&L, 1, 0);
    insertPos(&L, 2, 1);
    insertPos(&L, 3, 2);
    insertPos(&L, 9, 1);
    display(&L);

    deletePos(&L, 1);
    display(&L);

    insertSorted(&L, 0);
    insertSorted(&L, 10);
    display(&L);

    printf("Locate: Value \"1\" is at index %d.\n", locate(&L, 1));
    printf("Retrieve: The value at index \"1\" is %d.\n", retrieve(&L, 1));
}

void initialize(List *L){
    L->elemPtr = (int*)malloc(sizeof(int) * LENGTH);
    L->count = 0;
    L->max = LENGTH;
}

void insertPos(List *L, int data, int position){
    if(L->count == L->max) resize(L);    
    if(position <= L->count && L->count < L->max){
        for(int i = L->count; i > position; i--)
            L->elemPtr[i] = L->elemPtr[i-1];
        L->elemPtr[position] = data;
        L->count++;
    }
}

void deletePos(List *L, int position){
    if(position >= 0 && position < L->count){
        for (int i = position; i < L->count - 1; i++)
            L->elemPtr[i] = L->elemPtr[i+1];
        L->count--;
    }
}

int locate(List *L, int data){
    for(int i = 0; i < L->count; i++){
        if(L->elemPtr[i] == data)
            return i;
    }
    return -1;
}

int retrieve(List *L, int position){
    if(position >= 0 && position < L->count)
        return L->elemPtr[position];
    return -1;
}

void insertSorted(List *L, int data){
    if(L->count == L->max) resize(L);   
    if(L->count < L->max){
        int i;
        for(i = L->count; i > 0 && L->elemPtr[i-1] > data; i--)
            L->elemPtr[i] = L->elemPtr[i-1];
        L->elemPtr[i] = data;
        L->count++;
    }
}

void display(List *L){
    for(int i = 0; i < L->count; i++)
        printf("%d ", L->elemPtr[i]);
    printf("\n");
}

void resize(List *L){
    L->max *= 2;
    L->elemPtr = (int*)realloc(L->elemPtr, sizeof(int) * L->max);
}

void makeNULL(List *L){
    free(L->elemPtr);
    L->elemPtr = NULL;
    L->count = 0;
    L->max = 0;
}

