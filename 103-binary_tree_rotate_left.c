#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree.
 *
 * Description:
 * This function performs a left rotation on a binary tree. A left rotation
 * involves moving the right child of the given node up to the node's position,
 * with the original node becoming the left child of the new node.
 *
 * @tree: Pointer to the root node of the tree to rotate.
 *
 * Return:
 * Pointer to the new root node of the tree after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	new_root = tree->right;
	tree->right = new_root->left;
	if (new_root->left != NULL)
		new_root->left->parent = tree;
	new_root->left = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

    return (new_root);
}
