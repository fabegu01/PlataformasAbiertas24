#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Inicializa el stack
// Esta función establece el puntero 'top' del stack a NULL, indicando que la pila está vacía.
void initStack(Stack* stack) {
    stack->top = NULL;
}

// Agrega un elemento a la parte superior de la pila

void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Asigna memoria para el nuevo nodo
    if (!newNode) {  // Verifica si la asignación de memoria falló
        fprintf(stderr, "Error: No se pudo asignar memoria\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;  // Asigna el nuevo nodo
    newNode->next = stack->top;  // El siguiente nodo del nuevo nodo es el nodo actualmente en la cima
    newNode->prev = NULL;  // El nodo previo del nuevo nodo es nulo por que será ls nueva cabeza
        if (stack->top) {  // Si la pila no está vacía
        stack->top->prev = newNode;  // El nodo anterior del nodo actual en la cabeza es el nuevo nodo
    }
    stack->top = newNode;  // Actualiza el top de la pila al nuevo nodo
}

// Elimina y devuelve el elemento en la parte superior de la pila

int pop(Stack* stack) {
    if (isEmpty(stack)) {  // Verifica si la pila está vacía
        fprintf(stderr, "Error: La pila está vacía\n");  // Imprime un mensaje de error si está vacía
        exit(EXIT_FAILURE);
    }
    Node* temp = stack->top;  // Almacena el nodo superior temporalmente
    int poppedData = temp->data;  // Almacena el valor del nodo superior
    stack->top = stack->top->next;  // Actualiza el top de la pila al siguiente nodo
    if (stack->top) {  // Si la pila no está vacía después de la actualización
        stack->top->prev = NULL;  // El nuevo nodo superior no tiene nodo anterior
    }
    free(temp);  // Libera la memoria del nodo eliminado
    return poppedData;  // Devuelve el valor del nodo eliminado
}

// Devuelve el elemento en la parte superior de la pila sin eliminarlo

int peek(Stack* stack) {
    if (isEmpty(stack)) {  // Verifica si la pila está vacía
        fprintf(stderr, "Error: La pila está vacía\n");  // Imprime un mensaje de error si está vacía
        exit(EXIT_FAILURE);
    }
    return stack->top->data;  // Devuelve el valor del nodo superior
}

// Verifica si la pila está vacía
// Esta función retorna true si la pila está vacía y false en caso contrario.
bool isEmpty(Stack* stack) {//para este caso se uso el tipo bool que verifica verdaderos y falsos
    return stack->top == NULL;  // Retorna true si top es NULL, indicando que la pila está vacía
}

// Libera toda la memoria utilizada por la pila

void freeStack(Stack* stack) {
    while (!isEmpty(stack)) {  // Mientras la pila no esté vacía
        pop(stack);  // Elimina el nodo superior
    }
}

