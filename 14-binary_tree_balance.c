#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * The balance factor of a binary tree is the difference between the height of the left subtree and the right subtree
 * If tree is NULL, return 0
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor of the tree, or 0 if tree is NULL
 */


int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}

	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * The height of a binary tree is the number of edges between the tree's root and its furthest leaf.
 * If tree is NULL, the function must return 0.
 * 
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
 
size_t binary_tree_height(const binary_tree_t *tree)
{
	/* if tree is NULL, return 0 */
    if (tree)
	{
		size_t L = 0, R = 0;

        /*if tree has no left or right child, return 0 */

		L = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		R = tree->right ? 1 + binary_tree_height(tree->right) : 1;

		return ((L > R) ? L : R);
	}

	return (0);
}
