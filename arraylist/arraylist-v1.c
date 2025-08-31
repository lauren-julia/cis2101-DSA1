/* ARRAY LIST - Variation 1 - Static, by Value */

#include <stdio.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

List L;

List initialize(List);
List insertPos(List, int, int);
List deletePos(List, int);
int locate(List, int);
List insertSorted(List, int);
void display(List);

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
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    if(position <= L.count && L.count < MAX){
        for(int i = L.count; i > position; i--)
            L.elem[i] = L.elem[i-1];
        L.elem[position] = data;
        L.count++;
    }
    return L;
}

List deletePos(List L, int position){
    if(position >= 0 && position < L.count){
        for (int i = position; i < L.count - 1; i++)
            L.elem[i] = L.elem[i+1];
        L.count--;
    }
    return L;
}

int locate(List L, int data){
    for(int i = 0; i < L.count; i++){
        if(L.elem[i] == data)
            return i;
    }
    return -1;
}

List insertSorted(List L, int data){
    int i;
    if(L.count < MAX){
        for(i = L.count; i > 0 && L.elem[i-1] > data; i--)
            L.elem[i] = L.elem[i-1];
        L.elem[i] = data;
        L.count++;
    }
    return L;
}

void display(List L){
    for(int i = 0; i < L.count; i++)
        printf("%d ", L.elem[i]);
    printf("\n");
}
