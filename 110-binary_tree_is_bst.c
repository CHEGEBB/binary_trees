#include "binary_trees.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * is_bst_helper - Checks if a binary tree
 * examining each node and ensuring that its value falls within the specified
 * range defined by the minimum and maximum values.
 * @tree: A pointer to the root node of the tree to check.
 * @min: The minimum value allowed for nodes in the tree.
 * @max: The maximum value allowed for nodes in the tree.
 * Return: 1 if the tree is a valid BST, otherwise 0.
 */

int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst_helper(tree->left, min, tree->n) &&
		is_bst_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Determines whether a binary tree
 * This function recursively examines each node in the binary tree
 * the properties of a Binary Search Tree (BST)
 * The left subtree of a node contains only nodes with values less
 * The right subtree of a node contains only nodes with values greater
 * Both left and right subtrees must also be BSTs.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if the tree is a valid BST, otherwise 0.
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
