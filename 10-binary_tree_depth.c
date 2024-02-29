#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * depth of a node is the number of edges between the node and the root
 * when the node is the root, the depth is 0
 * @tree: Pointer to the node to measure the depth
 * Return: Depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	/* if tree is NULL, return 0 */
	size_t depth = 0;

	/* if tree is NULL, return 0 */
	if (tree == NULL)
		return (0);

	/* while tree has a parent, increment depth */
	while (tree->parent != NULL)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}
