#include "data_structs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * init_dict - this function initialises a new Dictionary structure
 */
dictionary* init_dict()
{
	/* create a new dictionary type and allocate space for it on the heap */
	dictionary* result = malloc(sizeof(dictionary));
	if (!result)
		return NULL;

	result->cur_index = -1;
	/**
	 * initialise the stack that will store the positions of the dictionary
	 * we don't need to do anything after initialising the stack
	 */
	result->slots = init_stack();
	if (!result->slots) {
		printf("slots initialisation failed. aborting...");
		free(result);
		return NULL;
	}

	/**
	 * since we've hard coded a set limit for entries, we basically
	 * iterate through every dict_entry in the entries array and set
	 * them to their default settings. keys cannot be a negative num
	 * so we set every key to -1 and value to an empty string just
	 * waiting to be filled
	 */
	int i;
	for(i = 0; i < MAX_SIZE; i++) {
		result->entries[i].key = -1;
		result->entries[i].value = NULL;
	}

	return  result;
}

/**
 * search - this iterates through the entries of the dictionary
 * and returns the index of the key if found, else returns -1
 * @head: the dictionary structure to search
 * @key: the unique key to find
 * Return: returns the index of the key or -1 if not found
 */
int search_dict(dictionary** head, int key) {
	dictionary* dict = *head;
	int i;

	/* 
	 * we can iterate through 1024 values because our
	 * implementation always initialises with 1024 values
	 * in the entries array
	 */
	for (i = 0; i < MAX_SIZE; i++) {
		if (dict->entries[i].key == key)
			return i;
	}

	return -1;
}

/**
 * exists - this checks if the key actually exists. useful for
 * bool statements without checking for the number search returns
 * @head: the dictionary to check
 * @key: the key to check
 * Return: returns true if the key is found and vice versa
 */
bool exists(dictionary ** head, int key) {
	return search_dict(head, key) != -1;
}

/**
 * valueof - this returns the value at the key
 * @head: the dictionary to search
 * @key: the key whose value we're are finding
 * Return: returns the value as a str or NULL if the key doesn't
 * exist
 */
char* valueof(dictionary** head, int key) {
	dictionary* dict = *head;
	int i = search_dict(&dict, key);

	if (exists(&dict, key)) {
		return dict->entries[i].value;
	}else {
		printf("The operation failed because there's no entry for key %d\n", key);
		return NULL;
	}
}

/**
 * insert - this adds a new entry into an existing dictionary structure
 * @head: the dictionary to insert a new entry into
 * @key: the unique key to add to the dictionary
 * @value: the unique key's associated value as a string
 */
void insert(dictionary** head, int key, char* value) {
	dictionary* dict = *head;
	/* check if the dictionary is full */
	if (dict->cur_index < MAX_SIZE) {
		/* check if the key already exists and is not a negative num */
		if (key < 0 || exists(head, key)) {
			printf("Your key %d already exists or is a negative number and can't be inserted\n", key);
			printf("Consider using a unique key or non-negative number...\n");
			return;
		}

		/*
		 * the first check makes sure there are no empty slots in the slots stack
		 * that we can pop. if there are none, we insert by using the cur_index
		 * value
		 */
		if (stack_empty(&dict->slots)) {
			if (dict->cur_index <= MAX_SIZE - 1) {
				dict->cur_index++;
				dict->entries[dict->cur_index].key = key;
				dict->entries[dict->cur_index].value = malloc(strlen(value) + 1);
				dict->entries[dict->cur_index].value = strdup(value);
			}
		} else {
			int index = pop(&dict->slots);
			dict->entries[index].key = key;
			dict->entries[index].value = malloc(strlen(value) + 1);
			dict->entries[index].value = strdup(value);
		}
	} else {
		printf("dictionary is full consider creating a new one\n");
	}
}

/**
 * clear_dict - this clears every entry in the dictionary and is different
 * from free_dict because this doesn't free the values from memory. think
 * of this as a reset minus the memory free. useful for reusing the structure
 * @dict: the dictionary in question
 */
void clear_dict(dictionary** dict) {
	dictionary* d = *dict;
	int i;

	for (i = 0; i < MAX_SIZE; i++) {
		d->entries[i].key = -1;
		d->entries[i].value = NULL;
	}
	if (!stack_empty(&d->slots)) {
		clear_stack(&d->slots);
	}

	printf("cleared the dictionary\n");
}

/**
 * _delete - deletes an entry in the dictionary and frees the associated
 * value from memory
 * @dict: the dictionary to delete the entry from
 * @key: the unique key of the value to delete
 */
void _delete(dictionary** dict, int key) {
	dictionary* d = *dict;
	int i = search_dict(&d, key);
	
	if (i != -1) {
		d->entries[i].key = -1;
		free(d->entries[i].value);
		d->entries[i].value = NULL;
		push(&d->slots, i);
	}else{
		printf("The operation failed because the key doesn't exist in the dictionary\n");
		return;
	}
}

/**
 * update - helper to update the value of a key in the dictionary
 * @dict: the dicitonary to perform the operation on
 * @key: the key whose value we change
 * @new: the updated text to replace the former's with
 */
void update(dictionary** dict, int key, char* new) {
	dictionary* d = *dict;
	int pos = search_dict(&d, key);
	
	if (pos != -1) {
		d->entries[pos].value = strcpy(d->entries[pos].value, new);
	}else{
		printf("The operation failed because the key doesn't exist in the dictionary\n");
		return;
	}
}

/**
 * free_dict - this frees the dictionary from memory
 * @head: the dictionary to free
 */
void free_dict(dictionary** head) {
	dictionary* dict = *head;
	int i;

	/* 
	 * Deadass don't know if this the most efficient but it frees
	 * every malloc that is called by the program so everything's
	 * fine?
	 * I'll look into this more in the future but for now it works!
	 */
	for (i = 0; i < MAX_SIZE; i++) {
		if (dict->entries[i].key >= 0) {
			free(dict->entries[i].value);
		}
	}

	/* we need to free the stack as well */
	free_stack(dict->slots);
	dict->slots = NULL;
	free(dict);
	(*head) = NULL;
	dict->slots = NULL;
}


/**
 * print_dict - prints every entry in the dictionary grouped by key-value
 * @head: the dictionary to print
 */
void print_dict(dictionary** head) {
	dictionary* dict = *head;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (dict->entries[i].key >= 0) {
            printf("Key: %d, Value: %s\n", dict->entries[i].key, dict->entries[i].value);
        }
    }
    printf("\n");
}
