#include "error_codes.h"
#include "data_structs.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * init_stack_cap - 	creates a new empty stack that needs to
 * freed once it's done
 * Return: returns an empty stack that can be populated
 */
stack* init_stack() {
	stack* new = malloc(sizeof(stack));
	int i;
	if (!new)
		return NULL;

	new->data = malloc(sizeof(int) * MAX_SIZE);
	new->top = -1;

	return new;
}

/**
 * push - adds an element on top of the stack
 * @head: the stack to push the item on top of
 * @value: the value of the item being pushed
 * Return: returns void
 */
void push(stack** head, int value) {
	stack* s = *head;
	/*
	 * checks the current index if its smaller than the
	 * MAX_SIZE. if it is, increase the index and push
	 * the new item on top of the stack
	 */
	if (s->top < MAX_SIZE - 1) {
		s->top++;
		s->data[(*head)->top] = value;
	} else {
		printf("The stack is full.\nConsider creating a new one");
	}
}

/**
 * peek - 	peek returns the value at the top of the stack
 * 			without removing or modifying the stack
 * @head: 	the stack that we'll be peeking
 * Return: 	returns the value of the item at the top of the
 * 			stack without removing it
 */
int peek(stack** head) {
	stack* s = *head;
	/*
	 * check the top if it's more than -1 we set initially
	 */
	if (s->top >= 0) {
		return s->data[(*head)->top];
	}
	else {
		printf("The stack doesn't exist or is empty\nConsider populating it");
		return -1;
	}
}

/**
 * pop - removes the item at the top and returns it
 * @head: the stack to remove the item from
 * Return: return the value in the item at the top
 */
int pop(stack** head) {
	stack* s = *head;
	int result = 0;
	if (s->top >= 0) {
		result = s->data[(*head)->top];
		s->top--;
		return result;
	}
	else {
		printf("The stack doesn't exist or is empty\nConsider populating it");
		return -1;
	}
}

/**
 * is_empty - this checks if an initialised stack contains items
 * @head: the pre initialised stack
 * Return: returns true or false depending on if it contains elements
 */
bool stack_empty(stack** head) {
	stack* s = *head;
	/*
	 * this works because per the init function every stack is initialised
	 * with the top value as -1 which is an invalid index for any array
	 * and also means an unpopulated stack
	 */
	return (*head)->top == -1;
}

void free_stack(stack* s) {
	free(s->data);
	free(s);
	printf("stack successfully freed\n");
}
