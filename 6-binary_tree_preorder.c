#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_preorder - Goes through a binary tree using pre-order traversal.
 * pre-order traversal goes through a binary tree using pre-order traversal.
 * in pre-order traversal, the node is first visited, then the left and right nodes.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 * If tree or func is NULL, do nothing.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Check if the tree or func is NULL */
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);

	/* Go through the left and right nodes */
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
