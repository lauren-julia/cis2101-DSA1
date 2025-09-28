/* Bit Vector Set - Variation 1 (Bitmask, char holds int value)*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initialize(unsigned char *set);
void insert(unsigned char *set, int element);
void delete(unsigned char *set, int element);
bool find(unsigned char set, int element);
unsigned char set_union(unsigned char A, unsigned char B);
unsigned char set_intersection(unsigned char A, unsigned char B);
unsigned char set_difference(unsigned char A, unsigned char B);
void display(unsigned char set);

int main(){
    unsigned char A, B;
    
    initialize(&A);
    initialize(&A);
}

void initialize(unsigned char *set){
    *set = 0;
}

void insert(unsigned char *set, int element){
    if(element < 0 || element >= 8) return;

    unsigned char mask = 1 << element;
    *set |= mask;
}

void delete(unsigned char *set, int element){
    if(element < 0 || element >= 8) return;

    unsigned char mask = 1 << element;
    *set &= ~mask;
}

bool find(unsigned char set, int element){
    if(element < 0 || element >= 8) return false;

    unsigned char mask = 1 << element;
    return (set & mask) != 0;
}

unsigned char set_union(unsigned char A, unsigned char B){
    return A | B;
}

unsigned char set_intersection(unsigned char A, unsigned char B){
    return A & B;
}

unsigned char set_difference(unsigned char A, unsigned char B){
    return A & ~B;
}

void display(unsigned char set){
    printf("\n\n");

    printf("Decimal Value: %d\n", set);

    printf("Binary Value: ");
    for(int i = 7; i >= 0; i--)
        printf("%d", (set & (1 << i)) ? 1 : 0);
    printf("\n");
    
    printf("Set Elements: ");
    printf("{ ");
    for(int i = 0; i < 8; i++) 
        if(set & (1 << i))
            printf("%d ", i);
    printf("}");

    printf("\n\n");
}