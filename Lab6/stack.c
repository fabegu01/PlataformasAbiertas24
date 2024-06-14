#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Inicializa el stack
void initStack(Stack* stack) {
    stack->top = NULL;
}

// Agrega un elemento a la parte superior de la pila
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Error: No se pudo asignar memoria\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = stack->top;
    newNode->prev = NULL;
    if (stack->top) {
        stack->top->prev = newNode;
    }
    stack->top = newNode;
}