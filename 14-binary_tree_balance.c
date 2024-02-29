#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 * Return: Balance factor of the tree, or 0 if tree is NULL.
 * Description:
 * This function measures the balance factor of a binary tree.
 * The balance factor of a binary tree is defined as the difference between the
 * height of the left subtree and the height of the right subtree. If the tree
 * is empty (tree is NULL), the balance factor is considered 0. Otherwise, the
 * balance factor is calculated recursively by subtracting the height of the
 * right subtree from the height of the left subtree.
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
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL, your function must return 0, else return height.
 * Description:
 * This function measures the height of a binary tree.
 * The height of a binary tree is defined as the length
 * the root node to a leaf node. If the tree is empty
 * is considered 0. Otherwise, the height is calculated recursively by adding 1
 * to the maximum height of the left and right subtrees.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t L = 0, R = 0;

		L = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		R = tree->right ? 1 + binary_tree_height(tree->right) : 1;

		return ((L > R) ? L : R);
	}

	return (0);
}
