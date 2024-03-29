#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_inorder - Goes through a binary tree using in-order traversal.
 * in-order traversal goes through a binary tree using in-order traversal.
 * in in-order traversal, the left node is visited, then the root node
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 * If tree or func is NULL, do nothing.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Check if the tree or func is NULL */
	if (tree == NULL || func == NULL)
		return;

	/* Go through the left node */
	binary_tree_inorder(tree->left, func);

	/* Call the function pointer func with the value of the node */
	func(tree->n);

	/* Go through the right node */
	binary_tree_inorder(tree->right, func);
}
