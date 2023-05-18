#include <stdio.h>
#include <stdlib.h>
#include "data_structs.h"

int main() {
    stack* s = init_stack();

    // Test push operation
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    // Test peek operation
    printf("Peek: %d\n", peek(&s));

    // Test pop operation
    printf("Pop: %d\n", pop(&s));
    printf("Pop: %d\n", pop(&s));
    printf("Pop: %d\n", pop(&s));

    // Test pop operation on an empty stack
    printf("Pop: %d\n", pop(&s));

    // Clean up memory
	free(s);

    return 0;
}

