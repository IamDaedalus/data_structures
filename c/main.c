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
	dictionary* entry = init_dict();
	int i = 0;

	for (i = 0; i < MAX_SIZE; i++) {
		char* str = "hello";
		insert(&entry, i, str);
		printf("inserted entry %d\n", i);
	}
	printf("done inserting...\n");

	print_dict(&entry);
}

int main() {
    run_tests();
    return 0;
}

