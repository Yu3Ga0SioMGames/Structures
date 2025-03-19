#ifndef HASH_TABLE_H_INCLUDED

#define HASH_TABLE_H_INCLUDED



#include <string.h>


#define SIZE 1000


typedef
struct _item
{
	char *key;
	char *value;
} Item;

typedef
struct _hash_table
{
	Item **items;

	size_t num_of_elem;
	size_t table_size;
} HashTable;


Item *create_item(char *, char *);

HashTable *create_hash_table(size_t table_size);

void free_item(Item *);
void free_hash_table(HashTable *);



#endif
