#ifndef STACK_H
#define STACK_H


// Estructura para un nodo de la lista doblemente enlazada
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Estructura para el stack
typedef struct Stack {
    Node* top;
} Stack;



void initStack(Stack* stack);
void push(Stack* stack, int data);

#endif 
