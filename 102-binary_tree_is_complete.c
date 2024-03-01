#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 * Description: This function checks if a binary tree is complete.
 * A binary tree is complete if all levels are filled except possibly
 * the last level, which is filled from left to right.
 */


int binary_tree_is_leaf(const binary_tree_t *node)
{
	/* If the tree is empty, it cannot be complete */
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}


/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height of
 * Return: the height of the tree. If tree is NULL, return 0
 *
 * Description: This function recursively measures the height of a binary tree.
 * The height of a binary tree is the length of the longest path from the root
 * node to a leaf node. If the tree is empty (NULL), the height is 0.
 */
 
size_t binary_tree_height(const binary_tree_t *tree)
{
	/* If the tree is empty, return height as 0 */
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left >= right)
		return (1 + left);
	return (1 + right);
}


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0
 */
 
 
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *l, *r;

	if (tree == NULL)
		return (1);
	l = tree->left;
	r = tree->right;
	if (binary_tree_is_leaf(tree))
		return (1);
	if (l == NULL || r == NULL)
		return (0);
	if (binary_tree_height(l) == binary_tree_height(r))
	{
		if (binary_tree_is_perfect(l) && binary_tree_is_perfect(r))
			return (1);
	}
	return (0);
}


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0
 * Description: This function checks if a binary tree is perfect.
 * A binary tree is perfect if all its levels
 * the last level, which is filled from left to right. Additionally,
 * all leaf nodes are at the same depth. If the tree is empty (NULL),
 * it is considered perfect.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t l_height, r_height;
	binary_tree_t *l, *r;

	/* If the tree is empty, it is considered perfect */
	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	l = tree->left;
	r = tree->right;
	l_height = binary_tree_height(l);
	r_height = binary_tree_height(r);
	if (l_height == r_height)
	{
		if (binary_tree_is_perfect(l) && binary_tree_is_complete(r))
			return (1);
	}
	else if (l_height == r_height + 1)
	{
		if (binary_tree_is_complete(l) && binary_tree_is_perfect(r))
			return (1);
	}
	return (0);
}
