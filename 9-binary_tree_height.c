#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_height - Measures the height of a binary tree.
 * The height of a binary tree is the number of edges between
 * If tree is NULL, the function must return 0.
 * @tree: Pointer to the root node of the tree to measure the height.
 * Return: The height of the tree. If tree is NULL, the function must return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	/* Declare left_height and right_height */
	size_t left_height, right_height;

	/* If tree is NULL, return 0 */
	if (tree == NULL)
		return (0);

	/* If tree has no left or right child, return 0 */
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/* If left_height is greater than right_height, return left_height + 1 */
	if (left_height > right_height)
		return (left_height + 1);
	return (right_height + 1);
}
