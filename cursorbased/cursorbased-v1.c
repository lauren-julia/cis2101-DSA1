//Variation 1 		- Lacking / doesn’t work as intended
#include <stdio.h>
#define MAX 4

typedef struct {
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;

int main(){
    VHeap V;
    List L = -1;
    initialize(&V);

    insertFirst(&L, &V, 3);
    insertFirst(&L, &V, 1);
    insertLast(&L, &V, 5);
    insertSorted(&L, &V, 4);
    insertSorted(&L, &V, 2);
    printf("List after inserts: ");
    display(L, V);

    deleteElem(&L, &V, 3);
    printf("List after deleting 3: ");
    display(L, V);

    insertLast(&L, &V, 2);
    insertFirst(&L, &V, 2);
    printf("List with duplicates: ");
    display(L, V);

    deleteAllOccurrence(&L, &V, 2);
    printf("List after deleting all 2s: ");
    display(L, V);
}
void initialize(VHeap *V){
    V->avail = 0;
    for(int i = 0; i < MAX - 1; i++)
        V->H[i].next = i + 1;
    V->H[MAX-1].next = -1;
}

int allocSpace(VHeap* V){
    int ret = V->avail;
    if(ret != -1)
        V->avail = V->H[ret].next;
    return ret;
}

void deallocSpace(VHeap* V, int index){
    V->H[index].next = V->avail;
    V->avail = index;
}

void display(int L, VHeap V){
    for (int i = L; i != -1; i = V.H[i].next) 
        printf("%d ", V.H[i].elem);
    printf("\n");    
}


/* INSERTING */
void insertFirst(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    if(newCell == -1) return;
    
    V->H[newCell].elem = elem;
    V->H[newCell].next = *L;
    *L = newCell;
}

void insertLast(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    if(newCell == -1) return;
    
    V->H[newCell].elem = elem;
    V->H[newCell].next = -1;

	int *trav;
	for(trav = L; *trav != -1; trav = &V->H[*trav].next) {}

   *trav = newCell;
}

void insertSorted(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    if (newCell == -1) return;
    
    int *trav = L;
    while (*trav != -1 && V->H[*trav].elem < elem) 
        trav = &V->H[*trav].next;
    
    V->H[newCell].elem = elem;
    V->H[newCell].next = *trav;
    *trav = newCell;
}


/* DELETING */
void deleteElem(int* L, VHeap* V, int elem){
    int *trav = L;
    while(*trav != -1 && V->H[*trav].elem != elem)
        trav = &V->H[*trav].next;
    
    if(*trav == -1) return;
    
    int temp = *trav;
    *trav = V->H[*trav].next;
    deallocSpace(V, temp);
}

void deleteAllOccurrence(int* L, VHeap* V, int elem){
    int *trav = L;
    while(*trav != -1){
        if(V->H[*trav].elem == elem){
            int temp = *trav;
            *trav = V->H[*trav].next;
            deallocSpace(V, temp);    
        }
        else trav = &V->H[*trav].next;
    }
}













