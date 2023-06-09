#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created sorted hash table
 * or NULL if it fails
 */
shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *ht;
unsigned long int i;

if (size == 0)
return (NULL);

ht = malloc(sizeof(shash_table_t));
if (ht == NULL)
return (NULL);

ht->size = size;
ht->array = malloc(sizeof(shash_node_t *) * size);
if (ht->array == NULL)
{
free(ht);
return (NULL);
}

for (i = 0; i < size; i++)
ht->array[i] = NULL;

ht->shead = NULL;
ht->stail = NULL;

return (ht);
}

/****************************BEGIN************************************/



/**
 * create_node - Creates a new node for the sorted hash table
 * @key: The key to be inserted in the node
 * @value: The value to be inserted in the node
 *
 * Return: A pointer to the newly created node, or NULL on failure
 */
shash_node_t *create_node(const char *key, const char *value)
{
shash_node_t *node = malloc(sizeof(shash_node_t));

if (node == NULL)
return (NULL);

node->key = strdup(key);
node->value = strdup(value);
node->next = NULL;
node->sprev = NULL;
node->snext = NULL;

return (node);
}

/**
 * insert_node - Inserts a node into the sorted hash table
 * @ht: The sorted hash table
 * @node: The node to be inserted
 */
void insert_node(shash_table_t *ht, shash_node_t *node)
{
shash_node_t *temp = ht->shead;

if (ht->shead == NULL)
{
ht->shead = node;
ht->stail = node;
}
else
{
while (temp != NULL && strcmp(node->key, temp->key) > 0)
temp = temp->snext;

if (temp == NULL)
{
node->sprev = ht->stail;
ht->stail->snext = node;
ht->stail = node;
}
else if (temp == ht->shead)
{
node->snext = ht->shead;
ht->shead->sprev = node;
ht->shead = node;
}
else
{
node->sprev = temp->sprev;
node->snext = temp;
temp->sprev->snext = node;
temp->sprev = node;
}
}
}

/**
 * shash_table_set - Adds an element to the sorted hash table
 * @ht: The sorted hash table to add or update the key/value to
 * @key: The key (cannot be an empty string)
 * @value: The value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
shash_node_t *node, *temp;
unsigned long int index;

if (ht == NULL || key == NULL || *key == '\0')
return (0);

index = key_index((const unsigned char *)key, ht->size);
node = ht->array[index];

while (node != NULL)
{
if (strcmp(node->key, key) == 0)
{
free(node->value);
node->value = strdup(value);
return (1);
}
node = node->next;
}

node = create_node(key, value);
if (node == NULL)
return (0);

node->next = ht->array[index];
ht->array[index] = node;

insert_node(ht, node);

return (1);
}







/****************************END**************************************/

/**
 * shash_table_get - Retrieves the value associated with a key
 * @ht: The sorted hash table to look into
 * @key: The key to search for
 *
 * Return: The value associated with the key, or NULL if key couldn't be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
shash_node_t *node;
unsigned long int index;

if (ht == NULL || key == NULL || *key == '\0')
return (NULL);

index = key_index((const unsigned char *)key, ht->size);
node = ht->array[index];

while (node != NULL)
{
if (strcmp(node->key, key) == 0)
return (node->value);
node = node->next;
}

return (NULL);
}

/**
 * shash_table_print - Prints the elements of a sorted hash table
 * @ht: The sorted hash table to print
 */
void shash_table_print(const shash_table_t *ht)
{
shash_node_t *node;
int flag = 0;

if (ht == NULL)
return;

printf("{");
node = ht->shead;
while (node != NULL)
{
if (flag == 1)
printf(", ");
printf("'%s': '%s'", node->key, node->value);
flag = 1;
node = node->snext;
}
printf("}\n");
}

/**
 * shash_table_print_rev - Prints the elements of a sorted
 * hash table in reverse order
 * @ht: The sorted hash table to print in reverse order
 */
void shash_table_print_rev(const shash_table_t *ht)
{
shash_node_t *node;
int flag = 0;

if (ht == NULL)
return;

printf("{");
node = ht->stail;
while (node != NULL)
{
if (flag == 1)
printf(", ");
printf("'%s': '%s'", node->key, node->value);
flag = 1;
node = node->sprev;
}
printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The sorted hash table to delete
 */
void shash_table_delete(shash_table_t *ht)
{
shash_node_t *node, *temp;
unsigned long int i;

if (ht == NULL)
return;

for (i = 0; i < ht->size; i++)
{
node = ht->array[i];
while (node != NULL)
{
temp = node;
node = node->next;
free(temp->key);
free(temp->value);
free(temp);
}
}

free(ht->array);
free(ht);
}
