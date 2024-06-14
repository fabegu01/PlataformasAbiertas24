#include <stdio.h>
#include "stack.h"

int main() {
    Stack stack;
    initStack(&stack);


 printf("Pushing 10, 20, 30 en la pila...\n");
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);


return 0;


}