#ifndef HASH_TABLE_H_INCLUDED

#define HASH_TABLE_H_INCLUDED



#include <stdio.h>
#include <string.h>


#define SIZE 50000
#define ERROR "Error...\n"


typedef
struct _item
{
	char *key;
	char *value;
} Item;

typedef
struct _list
{
	Item *item;
	struct _list *next;
} List;

typedef
struct _hash_table
{
	Item **items;

	List **overflow_buckets;

	size_t table_size;
	size_t num_of_elem;
} HashTable;


unsigned long long hash_table_hash_function(char *);

Item *hash_table_item_create(char *, char *);
Item *list_remove(List *);

HashTable *hash_table_create(size_t table_size);

char *hash_table_search(HashTable *, char *);

void hash_table_delete(HashTable *, char *);
void hash_table_insert(HashTable *, Item *);
void hash_table_item_free(Item *);
void hash_table_free(HashTable *);
void list_free(List *);
void overflow_buckets_free(HashTable *);

List *list_allocate();
List *list_insert(List *, Item *);
List **overflow_buckets_create(HashTable *);



#endif
