#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binary_trees.h"

#define INIT_NODE {0, NULL, NULL, NULL}
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define CONVERT "0123456789ABCDEF"
#define SETUP_NODE_BLOC { \
	tmp = *root; \
	size = binary_tree_size(*root); \
	binary = &buffer[49]; \
	*binary = 0; \
}

#define FREE_NODE_BLOC { \
	res = tmp->n; \
	free(tmp); \
	*root = NULL; \
}

#define SWAP_HEAD_BLOC { \
	head = *root; \
	head = swap_head(head, tmp); \
	res = head->n; \
	free(head); \
	*root = tmp; \
	tmp = perc_down(tmp); \
	*root = tmp; \
}

#define CONVERT_LOOP { \
	*--binary = CONVERT[size % 2]; \
	size /= 2; \
}

/**
 * swap - Swaps two nodes in a binary tree.
 *
 * This function swaps the positions of two nodes in a binary tree. It updates
 * the parent, left child, and right child pointers accordingly to maintain
 * the tree structure.
 *
 * @a: Pointer to the first node to be swapped.
 * @b: Pointer to the second node to be swapped.
 * 
 * Return: Pointer to the new root of the tree after the swap.
 */
bst_t *swap(bst_t *a, bst_t *b)
{
    /* Local Declarations */
    bst_t a_copy = INIT_NODE;

    /* Main Execution */
    a_copy.n = a->n;
    a_copy.parent = a->parent;
    a_copy.left = a->left;
    a_copy.right = a->right;

    /*Update the first node with values of the second node*/
    a->parent = b;
    a->left = b->left;
    a->right = b->right;

    /*Update parent pointers of the second node's children*/
    if (b->left)
        b->left->parent = a;
    if (b->right)
        b->right->parent = a;

    /*Update the parent of the second node*/
    b->parent = a_copy.parent;

    /*Update the parent's left or right child pointer to the second node*/
    if (a_copy.parent)
    {
        if (a == a_copy.parent->left)
            a_copy.parent->left = b;
        else
            a_copy.parent->right = b;
    }

    /*Update the left or right child pointers of the second node*/
    if (b == a_copy.left)
    {
        b->left = a;
        b->right = a_copy.right;

        /*Update the parent pointer of the second node's right child*/
        if (a_copy.right)
            a_copy.right->parent = b;
    }
    else if (b == a_copy.right)
    {
        b->right = a;
        b->left = a_copy.left;

        /*Update the parent pointer of the second node's left child*/
        if (a_copy.left)
            a_copy.left->parent = b;
    }

    /*Move to the root of the tree*/
    while (b->parent)
        b = b->parent;

    return b;
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the binary tree.
 *
 * Description: This function recursively calculates the number of nodes
 * in the binary tree, including the root node.
 *
 * Return: The number of descendant child nodes in the binary tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
    /* Base case: If the tree is empty, return 0 */
        return (0);

    /*
     * Recursive case: Count the root node and recursively count nodes
     * in the left and right subtrees, then sum them up.
     */
    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}


/**
 * swap_head - helper func to swap head and node
 * @head: pointer to head
 * @node: pointer to node
 * Return: pointer to severed head of tree
 */
heap_t *swap_head(heap_t *head, heap_t *node)
{
	if (node->parent->left == node)
	{
		node->parent->left = NULL;
	} else
		node->parent->right = NULL;
	node->parent = NULL;
	node->left = head->left;
	node->right = head->right;
	if (head->left)
		head->left->parent = node;
	if (head->right)
		head->right->parent = node;
	return (head);
}

/**
 * perc_down - Percolates the head node into the correct position in the heap.
 * @node: Pointer to the head node of the heap.
 *
 * Description: This function ensures that the head node of the heap
 * satisfies the Max Heap property by recursively swapping it with its
 * largest child node if necessary.
 *
 * Return: Pointer to the head node of the heap after percolation.
 */
heap_t *perc_down(heap_t *node)
{
	int max;
	heap_t *next = node;

	if (!node)
		return (NULL); /* Base case: If the node is NULL, return NULL */

	/* Determine the maximum value among the node and its children */
	max = node->n;
	if (node->left)
		max = MAX(node->left->n, max);
	if (node->right)
		max = MAX(node->right->n, max);

	/* Find the child node with the maximum value */
	if (node->left && max == node->left->n)
		next = node->left;
	else if (node->right && max == node->right->n)
		next = node->right;

	/* If the largest child node is different from the current node, swap them */
	if (next != node)
	{
		swap(node, next);
		perc_down(node); /* Recursively percolate down */
	}
	return (next);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root of the heap.
 *
 * Description: This function extracts the root node of a Max Binary Heap,
 * replacing it with the last level-order node of the heap. It then
 * rebuilds the heap if necessary to maintain the Max Heap property.
 *
 * Return: The value stored in the root node of the heap, or 0 if failed.
 */
int heap_extract(heap_t **root)
{
	size_t size, i;
	char *binary, c, buffer[50];
	int res;
	heap_t *tmp, *head;

	if (!root || !*root)
		return (0); /* Return 0 if the root pointer is NULL */

	/* Set up necessary variables and data structures */
	SETUP_NODE_BLOC;

	/* If there is only one node in the heap */
	if (size == 1)
	{
		FREE_NODE_BLOC; /* Free the root node */
		return (res);   /* Return the value stored in the root node */
	}

	/* Convert the size of the heap to binary */
	do {
		CONVERT_LOOP;
	} while (size);

	/* Traverse the heap to find the last level-order node */
	for (i = 1; i < strlen(binary); i++)
	{
		c = binary[i];
		if (i == strlen(binary) - 1)
		{
			if (c == '1')
			{
				tmp = tmp->right;
				break;
			}
			else if (c == '0')
			{
				tmp = tmp->left;
				break;
			}
		}
		if (c == '1')
			tmp = tmp->right;
		else if (c == '0')
			tmp = tmp->left;
	}

	/* Swap the last level-order node with the root node */
	SWAP_HEAD_BLOC;

	return (res); /* Return the value stored in the root node */
}
