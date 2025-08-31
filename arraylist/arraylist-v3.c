/* ARRAY LIST - Variation 3 - Dynamic, by Value */

#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

List L;

List initialize(List);
List insertPos(List, int, int);
List deletePos(List, int);
int locate(List, int);
List insertSorted(List, int);
void display(List);
List resize(List);

int main(){
    L = initialize(L);

    L = insertPos(L, 1, 0);
    L = insertPos(L, 2, 1);
    L = insertPos(L, 3, 2);
    L = insertPos(L, 9, 1);
    display(L);

    L = deletePos(L, 1);
    display(L);

    L = insertSorted(L, 0);
    display(L);

    L = insertSorted(L, 10);
    display(L);
    
    printf("Locate: Value \"1\" is at index %d.\n", locate(L, 1));
}

List initialize(List L){
    L.elemPtr = (int*)malloc(sizeof(int) * LENGTH);
    L.count = 0;
    L.max = LENGTH;
    return L;
}

List insertPos(List L, int data, int position){
    if(L.count == L.max) 
        L = resize(L);
    if(position <= L.count && L.count < L.max){
        for(int i = L.count; i > position; i--)
            L.elemPtr[i] = L.elemPtr[i-1];
        L.elemPtr[position] = data;
        L.count++;
    }
    return L;
}

List deletePos(List L, int position){
    if(position >= 0 && position < L.count){
        for (int i = position; i < L.count - 1; i++)
            L.elemPtr[i] = L.elemPtr[i+1];
        L.count--;
    }
    return L;
}

int locate(List L, int data){
    for(int i = 0; i < L.count; i++){
        if(L.elemPtr[i] == data)
            return i;
    }
    return -1;
}

List insertSorted(List L, int data){
    if(L.count == L.max) 
        L = resize(L);    
    if(L.count < L.max){
        int i;
        for(i = L.count; i > 0 && L.elemPtr[i-1] > data; i--)
            L.elemPtr[i] = L.elemPtr[i-1];
        L.elemPtr[i] = data;
        L.count++;
    }
    return L;
}

void display(List L){
    for(int i = 0; i < L.count; i++)
        printf("%d ", L.elemPtr[i]);
    printf("\n");
}

List resize(List L){
    L.max *= 2;
    L.elemPtr = (int*)realloc(L.elemPtr, sizeof(int) * L.max);
    return L;
}

