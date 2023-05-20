#ifndef DATA_STRUCTS_H
#define DATA_STRUCTS_H

#include <stdbool.h>

#define MAX_SIZE 2048
/* STRUCTS IMPLEMENTATION PROTOTYPES */
/**
 * @data: 	the actual data stored in the item as an array
 * 			of integers
 * @top: stores the item's index in the array
 */
typedef struct {
	int* data;
	int top;
} stack;

stack* init_stack();
int peek(stack**);
int pop(stack**);
bool stack_empty(stack**);
void clear_stack(stack**);
void push(stack**, int);
void free_stack(stack*);



/* >>>>> DICTIONARY IMPLEMENTATION PROTOTYPES <<<<< */

/**
 * dict_entry - this the "backend" of the dictionary type that holds
 * 				the key and pair value
 * @key: the unique key of the dictionary as an int
 * @value: the value of the dictionary as a string
 */
typedef struct {
	int key;
	char* value;
} dict_entry;

/**
 * dictionary - the actual dictionary that a user will be required to
 * 				call. this references the dict_entry and creates an arr
 * 				of dict_entry and a stack to keep track of the position
 * 				of each entry
 * @entries: 	an array of dict_entry for storing the dictionary's
 * 				entries. this is where the actual key-pair values are
 * 				store and retrieved based on their position on the stack
 * @slots:		the slots is a stack that keeps track of entries and their
 * 				positions when they are inserted into the entries array
 */
typedef struct {
	dict_entry entries[MAX_SIZE];
	int cur_index;
	stack* slots;
} dictionary;

/* >>>>>> DICTIONARY HELPER PROTOTYPES <<<<< */
dictionary* init_dict();
bool exists(dictionary**, int);
int search_dict(dictionary**, int);
char* valueof(dictionary**, int);
void print_dict(dictionary**);
void insert(dictionary**, int, char*);
void _delete(dictionary**, int);
void clear_dict(dictionary**);
void update(dictionary**, int, char*);
void free_dict(dictionary**);

#endif
