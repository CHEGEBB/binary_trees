#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 * Description: This function checks if a binary tree is complete.
 *binary tree is complete if all levels are filled except possibly
 * last level, which is filled from left to right.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	/* If the tree is empty, it cannot be complete */
	if (tree == NULL)
		return (0);

	/* If the tree has only one node, it is complete */
	if (binary_tree_is_leaf(tree))
		return (1);

	/* If either the left or right subtree is not complete*/
	if (!binary_tree_is_complete(tree->left) ||
    !binary_tree_is_complete(tree->right))
		return (0);

	/* If none of the above conditions are met, the tree is complete */
	return (1);
}


/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height of
 * Return: the height of the tree. If tree is NULL, return 0
 * Description: This function recursively measures the height of a binary tree.
 * The height of a binary tree is the length of the longest path from the root
 * node to a leaf node. If the tree is empty (NULL), the height is 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	/* If the tree is empty, return height as 0 */
	if (tree == NULL)
		return (0);

	/* Recursively calculate the height of the left and right subtrees */
	size_t left = binary_tree_height(tree->left);
	size_t right = binary_tree_height(tree->right);

	/* Return the height of the tree, which is the maximum of the heights
	 * of the left and right subtrees, plus 1 for the current node */
	if (left >= right)
		return (1 + left);
	return (1 + right);
}


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0
 *
 * Description: This function checks if a binary tree is perfect. A binary tree
 * is perfect if all its levels are completely filled, except possibly for the
 * last level, which is filled from left to right. Additionally, all leaf nodes
 * are at the same depth. If the tree is empty (NULL), it is considered perfect.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *l, *r;

	/* If the tree is empty, it is considered perfect */
	if (tree == NULL)
		return (1);

	/* Store the left and right subtrees */
	l = tree->left;
	r = tree->right;

	/* If the current node is a leaf node, return 1 */
	if (binary_tree_is_leaf(tree))
		return (1);

	/* If either left or right subtree is missing, the tree is not perfect */
	if (l == NULL || r == NULL)
		return (0);

	/* If the heights of the left and right subtrees are equal,
	 * recursively check if both subtrees are perfect */
	if (binary_tree_height(l) == binary_tree_height(r))
	{
		if (binary_tree_is_perfect(l) && binary_tree_is_perfect(r))
			return (1);
	}

	/* If any condition fails, the tree is not perfect */
	return (0);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 otherwise. If tree is NULL, return 0
 *
 * Description: This function checks if a binary tree is complete. A binary tree
 * is complete if all levels are filled except possibly for the last level,
 * which is filled from left to right. Additionally, if the last level is not
 * completely filled, its nodes should be as far left as possible.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t l_height, r_height;
	binary_tree_t *l, *r;

	/* If the tree is empty, it cannot be complete */
	if (tree == NULL)
		return (0);

	/* If the tree has only one node, it is complete */
	if (binary_tree_is_leaf(tree))
		return (1);

	/* Store the left and right subtrees */
	l = tree->left;
	r = tree->right;

	/* Calculate the heights of the left and right subtrees */
	l_height = binary_tree_height(l);
	r_height = binary_tree_height(r);

	/* If the heights of the left and right subtrees are equal,
	 * check if the left subtree is perfect and the right subtree is complete */
	if (l_height == r_height)
	{
		if (binary_tree_is_perfect(l) && binary_tree_is_complete(r))
			return (1);
	}
	/* If the height of the left subtree is one greater than the right subtree,
	 * check if the left subtree is complete and the right subtree is perfect */
	else if (l_height == r_height + 1)
	{
		if (binary_tree_is_complete(l) && binary_tree_is_perfect(r))
			return (1);
	}

	/* If none of the conditions are met, the tree is not complete */
	return (0);
}
