#include "test.h"

int test_hash_table()
{
	HashTable *hash_table = hash_table_create(SIZE);
	if(hash_table == NULL) {
		printf(ERROR);

		return -1;
	}

	char *first_key = "1";
	char *first_value = "First address";
	Item *first_item = hash_table_item_create(first_key, first_value);
	if(first_item == NULL) {
		printf(ERROR);

		hash_table_free(hash_table);

		return -1;
	}

	char *second_key = "2";
	char *second_value = "Second address";
	Item *second_item = hash_table_item_create(second_key, second_value);
	if(second_item == NULL) {
		printf(ERROR);

		hash_table_free(hash_table);

		return -1;
	}

	char *third_key = "Hel";
	char *third_value = "Third address";
	Item *third_item = hash_table_item_create(third_key, third_value);
	if(third_item == NULL) {
		printf(ERROR);

		hash_table_free(hash_table);

		return -1;
	}

	char *fourth_key = "Cau";
	char *fourth_value = "Fourth address";
	Item *fourth_item = hash_table_item_create(fourth_key, fourth_value);
	if(fourth_item == NULL) {
		printf(ERROR);

		hash_table_free(hash_table);

		return -1;
	}

	hash_table_insert(hash_table, first_item);
	hash_table_insert(hash_table, second_item);
	hash_table_insert(hash_table, third_item);
	hash_table_insert(hash_table, fourth_item);

	hash_table_search_print(hash_table, "1");
	hash_table_search_print(hash_table, "2");
	hash_table_search_print(hash_table, "3");
	hash_table_search_print(hash_table, "Hel");
	hash_table_search_print(hash_table, "Cau");

	hash_table_print(hash_table);

	hash_table_delete(hash_table, first_key);
	hash_table_delete(hash_table, fourth_key);

	hash_table_print(hash_table);

	hash_table_free(hash_table);
	return 0;
}
