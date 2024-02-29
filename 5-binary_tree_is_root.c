#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_root - Checks if a node is a root in a binary tree.
 * function that checks if a node is a root
 * if the node is a root, return 1
 * @node: Pointer to the node to check.
 *
 * Return: 1 if node is a root, 0 otherwise.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	/* Check if the node pointer is NULL */
	if (node == NULL)
		return (0);

	/* Check if the node has no parent */
	if (node->parent == NULL)
		return (1); /* Node is a root */

	return (0); /* Node is not a root */
}
