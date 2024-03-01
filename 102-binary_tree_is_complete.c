#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if complete, 0 otherwise. If tree is NULL, return 0
 * Description: This function checks if a binary tree is complete.
 * A binary tree is complete if all levels are filled
 * which is filled from left to right. Additionally, if the last
 * level is not completely filled, its nodes should be as far left as possible.
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

	/* If the heights of the left and right subtrees are equal*/
	if (l_height == r_height)
	{
		if (binary_tree_is_perfect(l) && binary_tree_is_complete(r))
			return (1);
	}
	/* If the height of the left subtree is one greater than the right subtree*/
	else if (l_height == r_height + 1)
	{
		if (binary_tree_is_complete(l) && binary_tree_is_perfect(r))
			return (1);
	}

	/* If none of the conditions are met, the tree is not complete */
	return (0);
}
