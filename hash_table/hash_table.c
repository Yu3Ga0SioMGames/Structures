#include "hash_table.h"



unsigned long long hash_table_hash_function(char *str)
{
	unsigned long long i = 0;

	for(int j = 0; str[j]; ++j) {
		i += str[j];
	}

	return i % SIZE;
}


Item *hash_table_item_create(char *input_key, char *input_value)
{
	Item *item = (Item *)malloc(sizeof(Item));
	if(item == NULL) {
		printf(ERROR);

		return NULL;
	}

	item->key = (char *)malloc(strlen(input_key) + 1);
	item->value = (char *)malloc(strlen(input_value) + 1);

	strcpy(item->key, input_key);
	strcpy(item->value, input_value);

	return item;
}

Item *list_remove(List *list)
{
	if(list == NULL) {
		return NULL;
	}

	if(list->next == NULL) {
		return NULL;
	}

	List *node = list->next;

	List *tmp = list;
	tmp->next = NULL;

	list = node;

	Item *item = NULL;
	memcpy(tmp->item, item, sizeof(Item));

	free(tmp->item->key);
	free(tmp->item->value);
	free(tmp->item);
	free(tmp);
	return item;
}


HashTable *hash_table_create(size_t input_table_size)
{
	HashTable *hash_table = (HashTable *)malloc(sizeof(HashTable));
	if(hash_table == NULL) {
		printf(ERROR);

		return NULL;
	}

	hash_table->table_size = input_table_size;
	hash_table->num_of_elem = 0;

	hash_table->items = (Item **)calloc(hash_table->table_size, sizeof(Item *));
	for(size_t i = 0; i < hash_table->table_size; ++i) {
		hash_table->items[i] = NULL;
	}

	hash_table->overflow_buckets = overflow_buckets_create(hash_table);

	return hash_table;
}


char *hash_table_search(HashTable *hash_table, char *input_key)
{
	unsigned long long index = hash_table_hash_function(input_key);

	Item *item = hash_table->items[index];

	List *head = hash_table->overflow_buckets[index];
	while(item != NULL) {
		if(strcmp(item->key, input_key) == 0) {
			return item->value;
		}

		if(head == NULL) {
			return NULL;
		}

		item = head->item;
		head = head->next;
	}

}


void hash_table_delete(HashTable *hash_table, char *input_key)
{
	int index = hash_table_hash_function(input_key);
	Item *item = hash_table->items[index];
	List *head = hash_table->overflow_buckets[index];

	if(item == NULL) {
		return;
	} else {
		if(head == NULL && strcmp(item->key, input_key) == 0) {
			hash_table->items[index] = NULL;

			hash_table_item_free(item);

			--hash_table->num_of_elem;

			return;
		} else if(head != NULL) {
			if(strcmp(item->key, input_key) == 0) {
				hash_table_item_free(item);

				List *node = head;
				head = head->next;
				node->next = NULL;
				hash_table->items[index] = hash_table_item_create(node->item->key, node->item->value);

				list_free(node);

				hash_table->overflow_buckets[index] = head;

				return;
			}

			List *current = head;
			List *previous = NULL;

			while(current) {
				if(strcmp(current->item->key, input_key) == 0) {
					if(previous == NULL) {
						list_free(head);

						hash_table->overflow_buckets[index] = NULL;

						return;
					} else {
						previous->next = current->next;
						current->next = NULL;

						list_free(current);

						hash_table->overflow_buckets[index] = head;

						return;
					}
				}

				current = current->next;
				previous = current;
			}
		}
	}
}

void hash_table_search_print(HashTable *hash_table, char *input_key)
{
	char *final_value = NULL;
	if((final_value = hash_table_search(hash_table, input_key)) == NULL) {
		printf("Key: %s, does not exist... ", input_key);
		printf(ERROR);

		return;
	} else {
		printf("Key: %s, Value: %s;\n", input_key, final_value);
	}
}

void hash_table_print(HashTable *hash_table)
{
	printf("\nHash Table:\n<<<-<<<-<<<=-------------------=>>>->>>->>>\n");

	for(int i = 0; i < hash_table->table_size; ++i) {
		if(hash_table->items[i]) {
			printf("Index: %d, Key: %s, Value: %s;", i,
			       hash_table->items[i]->key,
			       hash_table->items[i]->value);

			if(hash_table->overflow_buckets[i]) {
				printf(" >=< Overflow Bucket >=< ");

				List *head = hash_table->overflow_buckets[i];
				while(head) {
					printf("Key: %s, Value: %s;", head->item->key, head->item->value);

					head = head->next;
				}
			}

			printf("\n");
		}
	}

	printf("<<<-<<<-<<<=-------------------=>>>->>>->>>\n");
}

void hash_table_handle_collision(HashTable *hash_table, unsigned long long index, Item *input_item)
{
	List *head = hash_table->overflow_buckets[index];

	if(head == NULL) {
		head = list_allocate();
		head->item = input_item;
		hash_table->overflow_buckets[index] = head;

		return;
	} else {
		hash_table->overflow_buckets[index] = list_insert(head, input_item);

		return;
	}
}

void hash_table_insert(HashTable *hash_table, Item *item)
{
	int index = hash_table_hash_function(item->key);
	Item *current_item = hash_table->items[index];
	if(current_item == NULL) {
		if(hash_table->num_of_elem == hash_table->table_size) {
			printf("Insert Error: Hash Table is full\n");
			printf(ERROR);

			return;
		}


		hash_table->items[index] = item;
		hash_table->num_of_elem++;
	} else {
		if(strcmp(current_item->key, item->key) == 0) {
			strcpy(hash_table->items[index]->value, item->value);

			return;
		} else {
			hash_table_handle_collision(hash_table, index, item);

			return;
		}
	}
}

void hash_table_item_free(Item *item)
{
	free(item->key);
	free(item->value);
	free(item);
}

void hash_table_free(HashTable *hash_table)
{
	for(int i = 0; i < hash_table->table_size; ++i) {
		Item *item = hash_table->items[i];
		if(item != NULL) {
			hash_table_item_free(item);
		}
	}

	overflow_buckets_free(hash_table);

	free(hash_table->items);
	free(hash_table);
}

void list_free(List *list)
{
	List *tmp = list;
	while(list) {
		tmp = list;

		list = list->next;

		free(tmp->item->key);
		free(tmp->item->value);
		free(tmp->item);
		free(tmp);
	}
}

void overflow_buckets_free(HashTable *hash_table)
{
	List **buckets = hash_table->overflow_buckets;
	for(int i = 0; i < hash_table->table_size; ++i) {
		list_free(buckets[i]);
	}

	free(buckets);
}


List *list_allocate()
{
	List *list = (List *)malloc(sizeof(List));
	if(list == NULL) {
		printf(ERROR);

		return NULL;
	}

	list->item = NULL;
	list->next = NULL;

	return list;
}

List *list_insert(List *list, Item *input_item)
{
	if(list == NULL) {
		List *head = list_allocate();
		head->item = input_item;
		head->next = NULL;
		list = head;

		return list;
	} else if(list->next == NULL) {
		List *node = list_allocate();
		node->item = input_item;
		node->next = NULL;
		list->next = node;

		return list;
	}

	List *tmp = list;
	while(tmp->next->next) {
		tmp = tmp->next;
	}

	List *node = list_allocate();
	node->item = input_item;
	node->next = NULL;
	tmp->next = node;

	return list;
}

List **overflow_buckets_create(HashTable *hash_table)
{
	List **buckets = (List **)calloc(hash_table->table_size, sizeof(List *));
	for(int i = 0; i < hash_table->table_size; ++i) {
		buckets[i] = NULL;
	}

	return buckets;
}
