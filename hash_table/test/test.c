#include "test.h"

int test_hash_table()
{
	printf("Hello World!!!\n");

	char str[5] = {"abcd\0"};
	int tmp = hash_function(str);
	printf("%d ", tmp);

	return 0;
}
