#include "binary_trees.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - Calculates the height of a binary tree.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Description:
 * This function computes the height of a given binary tree. The height is defined
 * as the length of the longest path from the root node to a leaf node. If the tree
 * is empty (NULL), the function returns 0.
 *
 * Return: The height of the binary tree.
 */

size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Description:
 * This function determines whether a given binary tree is a valid AVL Tree or not.
 * An AVL Tree is a Binary Search Tree (BST) where the height difference between
 * the left and right subtrees of any node is not more than one. The left and right
 * subtrees must also be AVL trees.
 *
 * Return: Returns 1 if the binary tree is a valid AVL Tree, and 0 otherwise.
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_avl_helper - Assesses if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to be examined.
 * @lo: The value of the smallest node visited so far.
 * @hi: The value of the largest node visited so far.
 *
 * Description:
 * This function recursively checks whether the given binary tree satisfies
 * the properties of an AVL (Adelson-Velsky and Landis) tree. An AVL tree is
 * a self-balancing binary search tree where the height difference between the
 * left and right subtrees of any node is at most one, and both the left and
 * right subtrees are also AVL trees.
 *
 * Return: 1 if the tree is a valid AVL tree, and 0 otherwise.
 */

int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t lhgt, rhgt, diff;

	if (tree != NULL)
	{
		/* Check if the current node is within the valid range */
		if (tree->n < lo || tree->n > hi)
			return (0);
		/* Check if the left and right subtrees are AVL trees */
		lhgt = height(tree->left);
		rhgt = height(tree->right);
		diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}
