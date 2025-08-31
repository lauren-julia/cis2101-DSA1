/* ARRAY LIST - Variation 2 - Static, by Pointer */

#include <stdio.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;

EPtr L;

void initialize(EPtr);
void insertPos(EPtr, int, int);
void deletePos(EPtr, int);
int locate(EPtr, int);
int retrieve(EPtr, int);
void insertSorted(EPtr, int);
void display(EPtr);
void makeNULL(EPtr);

int main(){
    Etype list;
    L = &list;

    initialize(L);

    insertPos(L, 1, 0);
    insertPos(L, 2, 1);
    insertPos(L, 3, 2);
    insertPos(L, 9, 1);
    display(L);

    deletePos(L, 1);
    display(L);

    insertSorted(L, 0);
    insertSorted(L, 10);
    display(L);

    printf("Locate: Value \"1\" is at index %d.\n", locate(L, 1));
    printf("Retrieve: The value at index \"1\" is %d.\n", retrieve(L, 1));
}

void initialize(EPtr L){
    L->count = 0;
}

void insertPos(EPtr L, int data, int position){
    if(position <= L->count && L->count < MAX){
        for(int i = L->count; i > position; i--)
            L->elem[i] = L->elem[i-1];
        L->elem[position] = data;
        L->count++;
    }
}

void deletePos(EPtr L, int position){
    if(position >= 0 && position < L->count){
        for (int i = position; i < L->count - 1; i++)
            L->elem[i] = L->elem[i+1];
        L->count--;
    }
}

int locate(EPtr L, int data){
    for(int i = 0; i < L->count; i++){
        if(L->elem[i] == data)
            return i;
    }
    return -1;
}

int retrieve(EPtr L, int position){
    if(position >= 0 && position < L->count)
        return L->elem[position];
    return -1;
}

void insertSorted(EPtr L, int data){
    int i;
    if(L->count < MAX){
        for(i = L->count; i > 0 && L->elem[i-1] > data; i--)
            L->elem[i] = L->elem[i-1];
        L->elem[i] = data;
        L->count++;
    }
}

void display(EPtr L){
    for(int i = 0; i < L->count; i++)
        printf("%d ", L->elem[i]);
    printf("\n");
}

void makeNULL(EPtr L){
    L->count = 0;
}
