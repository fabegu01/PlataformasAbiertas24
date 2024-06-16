#include <stdio.h>
#include "stack.h"

int main() {
    Stack stack;
    initStack(&stack);


 printf("Pushing 10, 20, 30 en la pila...\n");
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
   
    printf("Top element: %d\n", peek(&stack));

    printf("Popping elements...\n");
    while (!isEmpty(&stack)) {
        printf("Popped element: %d\n", pop(&stack));
    }

     if (isEmpty(&stack)) {
        printf("La pila está vacía.\n");
    } else {
        printf("La pila no está vacía.\n");
    }

    freeStack(&stack);

    
return 0;
}

