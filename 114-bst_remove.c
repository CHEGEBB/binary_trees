#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * inorder_successor - Returns the minimum value of a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value in @tree.
 *
 * Description: This function returns the node with the minimum value in a
 * binary search tree (BST), given its root node.
 */
bst_t *inorder_successor(bst_t *root)
{
	/* Traverse leftmost nodes to find the minimum value */
	while (root->left != NULL)
		root = root->left;

	/* Return the node with the minimum value */
	return (root);
}


/**
 * bst_delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 *
 * Description: This function deletes a node from a binary search tree (BST)
 * while maintaining the BST properties.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;
	if (node->left == NULL)
		
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}
	successor = inorder_successor(node->right);
	node->n = successor->n;
	return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - Removes a node from a binary search tree recursively.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 *
 * Description: This function removes a node from a binary search tree (BST)
 * recursively, while maintaining the BST properties.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		/* If the current node's value matches the value to be removed*/
		if (node->n == value)
			return (bst_delete(root, node));

		/* If the value to be removed is less than the current node's value*/
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));

		/* If the value to be removed is greater than the current node's value*/
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 *
 * Return: A pointer to the new root node after deletion.
 *
 * Description: This function removes a node from a binary search tree (BST)
 * while maintaining the BST properties. If the node to be deleted has two
 * children, it is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	/* Call the recursive removal function with the root node */
	return (bst_remove_recursive(root, root, value));
}
