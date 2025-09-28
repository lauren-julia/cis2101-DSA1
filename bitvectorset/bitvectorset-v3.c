/* Bit Vector Set - Variation 3 (Boolean/enum array)*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ARRAY_SIZE 8

typedef bool Set[ARRAY_SIZE];

void initialize(Set set);
void insert(Set set, int element);
void delete(Set set, int element);
bool find(Set set, int element);
void set_union(Set A, Set B, Set C);
void set_intersection(Set A, Set B, Set C);
void set_difference(Set A, Set B, Set C);
void display(Set set);

int main(){
    Set A, B, C;

    initialize(A);
    initialize(B);
    initialize(C);
}

void initialize(Set set){
    for(int i = 0; i < ARRAY_SIZE; i++)
        set[i] = false;
}

void insert(Set set, int element){
    if(element < 0 || element >= ARRAY_SIZE) return;
    
    set[element] = true;
}

void delete(Set set, int element){
    if(element < 0 || element >= ARRAY_SIZE) return;
    
    set[element] = false;
}

bool find(Set set, int element){
    if(element < 0 || element >= ARRAY_SIZE) return false;

    return set[element];
}

void set_union(Set A, Set B, Set C){
    for(int i = 0; i < ARRAY_SIZE; i++)
        C[i] = (A[i] || B[i]);
}

void set_intersection(Set A, Set B, Set C){
    for(int i = 0; i < ARRAY_SIZE; i++)
        C[i] = (A[i] && B[i]);
}

void set_difference(Set A, Set B, Set C){
    for(int i = 0; i < ARRAY_SIZE; i++)
        C[i] = (A[i] && !B[i]);
}

void display(Set set){
    printf("Array Elements: [ ");
    for(int i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", set[i]);
    printf("]\n");

    printf("Set Elements: { ");
    for(int i = 0; i < ARRAY_SIZE; i++)
        if(set[i])
            printf("%d ", i);
    printf("}\n");
}
