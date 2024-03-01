#include "binary_trees.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define INIT_NODE {0, NULL, NULL, NULL}

#include "binary_trees.h"

/**
 * swap - Swaps two nodes in a binary tree.
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 * This function swaps the positions of two nodes in a binary tree.
 * @return: Pointer to the root node of the tree after swapping.
 */
binary_tree_t *swap(binary_tree_t *a, binary_tree_t *b)
{
    binary_tree_t *temp;

    temp = a->parent;
    a->parent = b->parent;
    b->parent = temp;

    if (a->parent != NULL)
    {
        if (a->parent->left == b)
            a->parent->left = a;
        else
            a->parent->right = a;
    }

    if (b->parent != NULL)
    {
        if (b->parent->left == a)
            b->parent->left = b;
        else
            b->parent->right = b;
    }

    return (a->parent == NULL ? a : b);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the Heap to insert the value.
 * @value: Value to store in the node to be inserted.
 * Return: Pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *inserted_node;

    if (root == NULL)
        return NULL;

    new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return NULL;

    if (*root == NULL)
    {
        *root = new_node;
        return new_node;
    }

    inserted_node = binary_tree_insert_left(*root, value);
    if (inserted_node == NULL)
    {
        free(new_node);
        return NULL;
    }

    return swap(inserted_node, inserted_node->parent);
}


/**
 * convert - converts number and base into string
 * @num: input number
 * @base: input base
 * @lowercase: flag if hexa values need to be lowercase
 * Return: result string
 */
 
char *convert(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = 0;
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num);

	return (ptr);
}


/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: input binary tree
 * Return: number of descendant child nodes
 */
 
 
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}


/**
 * insert - helper func to insert node to correct location
 * @root: double pointer to root of max heap
 * @node: node to insert
 */
 
 
void insert(heap_t **root, heap_t *node)
{
	heap_t *tmp;
	int size;
	unsigned int i;
	char *binary;
	char c;

	tmp = *root;
	size = binary_tree_size(tmp) + 1;
	binary = convert(size, 2, 1);
	for (i = 1; i < strlen(binary); i++)
	{
		c = binary[i];
		if (i == strlen(binary) - 1)
		{
			if (c == '1')
			{
				node->parent = tmp;
				tmp->right = node;
				break;
			}
			else if (c == '0')
			{
				node->parent = tmp;
				tmp->left = node;
				break;
			}
		}
		if (c == '1')
			tmp = tmp->right;
		else if (c == '0')
			tmp = tmp->left;
	}
}


/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: double pointer to root of tree
 * @value: input value
 * Return: pointer to the created node, or NULL on failure
 */
 
 
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *ht = NULL, *ret;

	if (!root)
		return (NULL);
	ht = calloc(1, sizeof(heap_t));
	ht->n = value;
	if (!*root)
	{
		*root = ht;
		return (ht);
	}
	insert(root, ht);
	while (ht->parent && ht->n > ht->parent->n)
	{
		ret = swap(ht->parent, ht);
		if (ret)
			*root = ret;
	}
	return (ht);
}
