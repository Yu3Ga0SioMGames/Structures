#include "hash_table.h"


unsigned long long hash_function(char *str)
{
	unsigned long long i = 0;

	for(int j = 0; str[j]; ++j) {
		i += str[j];
	}

	return i % SIZE;
}

Item *create_item(char *input_key, char *input_value)
{
	Item *item = (Item *)malloc(sizeof(Item));
	if(item == NULL) {
		return NULL;
	}

	item->key = (char *)malloc(strlen(input_key) + 1);
	item->value = (char *)malloc(strlen(input_value) + 1);

	strcpy(item->key, input_key);
	strcpy(item->value, input_value);

	return item;
}

HashTable *create_hash_table(size_t input_table_size)
{
	HashTable *hash_table = (HashTable *)malloc(sizeof(HashTable));
	if(hash_table == NULL) {
		return NULL;
	}

	hash_table->table_size = input_table_size;
	hash_table->num_of_elem = 0;

	hash_table->items = (Item **)calloc(hash_table->table_size, sizeof(Item *));
	for(size_t i = 0; i < hash_table->table_size; ++i) {
		hash_table->items[i] = NULL;
	}

	return hash_table;
}

void free_item(Item *item)
{
	free(item->key);
	free(item->value);
	free(item);
}

void free_hash_table(HashTable *hash_table)
{
	for(int i = 0; i < hash_table->table_size; ++i) {
		Item *item = hash_table->items[i];
		if(item != NULL) {
			free_item(item);
		}
	}

	free(hash_table->items);
	free(hash_table);
}
