#ifndef DATA_STRUCTS_H
#define DATA_STRUCTS_H

#define MAX_SIZE 1024
/* STRUCTS IMPLEMENTATION PROTOTYPES */
/**
 * @data: 	the actual data stored in the item as an array
 * 			of integers
 * @top: stores the item's index in the array
 */
typedef struct {
	int data[MAX_SIZE];
	int top;
} stack;

stack* init_stack();
int peek(stack**);
int pop(stack**);
void push(stack**, int);



/* DICTIONARY IMPLEMENTATION PROTOTYPES */
typedef struct {
	int key;
	char* value;
} dictionary;


#endif
