#include "error_codes.h"
#include "data_structs.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * init - 	creates a new empty stack that needs to
 * 			freed once it's doen
 * Return: returns an empty stack that can be populated
 */
stack* init_stack() {
	stack* new = malloc(sizeof(stack));
	if (!new)
		return NULL;

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
	/*
	 * checks the current index if its smaller than the
	 * MAX_SIZE. if it is, increase the index and push
	 * the new item on top of the stack
	 */
	if ((*head)->top < MAX_SIZE - 1) {
		(*head)->top++;
		(*head)->data[(*head)->top] = value;
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
	/*
	 * check the top if it's more than -1 we set initially
	 */
	if ((*head)->top >= 0) {
		return (*head)->data[(*head)->top];
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
	int result = 0;
	if ((*head)->top >= 0) {
		result = (*head)->data[(*head)->top];
		(*head)->top--;
		return result;
	}
	else {
		printf("The stack doesn't exist or is empty\nConsider populating it");
		return -1;
	}
}
