#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 * A node is called a leaf if it has no children
 * A node with at least 1 child is called an internal node
 * @tree: Pointer to the root node of the tree to count the number of nodes
 * Return: Number of nodes with at least 1 child in a binary tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	/* if tree is NULL, return 0 */
	if (tree == NULL)
		return (0);

	/* if tree has at least 1 child, return 1 */
	if (tree->left != NULL || tree->right != NULL)
		return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
	return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
