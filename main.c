#include "data_structs.h"
#include <stdio.h>

int main(void) {
	dictionary* dict = init_dict();

	insert(&dict, 0, "hello");
	insert(&dict, 1, "world");
	insert(&dict, 2, "Manny");

	printf("\nPrinting a new dictionary\n");
	print_dict(&dict);

	printf("before change 0 was %s\n", valueof(&dict, 0));
	_delete(&dict, 0);
	printf("after change 0 is %s\n", valueof(&dict, 0));

	insert(&dict, 756, "another insert");
	printf("\nPrinting a new dictionary\n");
	print_dict(&dict);

	free_dict(dict);

	return 0;
}
