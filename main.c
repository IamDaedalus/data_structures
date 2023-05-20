#include "data_structs.h"
#include <stdio.h>

void print_stack(stack** st) {
	if (!stack_empty(st)) {
		for (int i = 0; i < MAX_SIZE; i++) {
			if ((*st)->data[i]) {
				printf("Entry %d is %d\n", i + 1, (*st)->data[i]);
			}
		}
	} else {
		printf("The stack is empty\n");
	}
}

void run_tests() {
    stack* st = init_stack();
    
    // Test init_stack
    printf("Test init_stack:\n");
    printf("Stack initialized successfully.\n");
    
    // Test stack_empty
    printf("\nTest stack_empty:\n");
    printf("Stack is empty: %s\n", stack_empty(&st) ? "true" : "false");
    
    // Test push and peek
    printf("\nTest push and peek:\n");
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    printf("Pushed elements: 10, 20, 30\n");
    int top = peek(&st);
    printf("Top element: %d\n", top);
    
    // Test pop
    printf("\nTest pop:\n");
    int popped = pop(&st);
    printf("Popped element: %d\n", popped);
    top = peek(&st);
    printf("Top element: %d\n", top);
    
    // Test stack_empty after pop
    printf("\nTest stack_empty after pop:\n");
    printf("Stack is empty: %s\n", stack_empty(&st) ? "true" : "false");
    
    // Test clear_stack
    printf("\nTest clear_stack:\n");
    push(&st, 40);
    push(&st, 50);
    printf("Pushed elements: 40, 50\n");
    clear_stack(&st);
    printf("Stack cleared.\n");
    printf("Stack is empty: %s\n", stack_empty(&st) ? "true" : "false");
    
    // Test free_stack
    printf("\nTest free_stack:\n");
    free_stack(st);
    printf("Stack freed from memory.\n");
}

int main() {
    run_tests();
    return 0;
}

