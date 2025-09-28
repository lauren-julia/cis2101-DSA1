/* Bit Vector Set - Variation 2 (Bitfields)*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    unsigned int field : 8;
} Set;

void initialize(Set *set);
void insert(Set *set, int element);
void delete(Set *set, int element);
bool find(Set set, int element);
Set set_union(Set A, Set B);
Set set_intersection(Set A, Set B);
Set set_difference(Set A, Set B);
void display(Set set);

int main(){
    Set A, B;

    initialize(&A);
    initialize(&B);
}

void initialize(Set *set){
    set->field = 0;
}

void insert(Set *set, int element){
    if(element < 0 || element >= 8) return;

    unsigned int mask = 1 << element;
    set->field |= mask;
}

void delete(Set *set, int element){
    if(element < 0 || element >= 8) return;
    
    unsigned int mask = 1 << element;
    set->field &= ~mask;
}

bool find(Set set, int element){
    if(element < 0 || element >= 8) return false;

    unsigned int mask = 1 << element;
    return (set.field & mask) != 0;
}

Set set_union(Set A, Set B){
    Set C;
    C.field = A.field | B.field;
    return C;
}

Set set_intersection(Set A, Set B){
    Set C;
    C.field = A.field & B.field;
    return C;
}

Set set_difference(Set A, Set B){
    Set C;
    C.field = A.field & ~B.field;
    return C;
}

void display(Set set){
    printf("\n\n");
    
    printf("Decimal Value: %d\n", set.field);

    printf("Binary Value: ");
    for(int i = 7; i >= 0; i--)
        printf("%d", (set.field & (1 << i)) ? 1 : 0);
    printf("\n");
    
    printf("Set Elements: ");
    printf("{ ");
    for(int i = 0; i < 8; i++) 
        if(set.field & (1 << i))
            printf("%d ", i);
    printf("}");

    printf("\n\n");
}