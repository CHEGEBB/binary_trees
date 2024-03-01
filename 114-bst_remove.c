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
 * 
 * It starts from the given node and traverses down the left subtree
 * recursively until it reaches the leftmost leaf node, which contains
 * the minimum value in the BST.
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
 * 
 * It handles different cases:
 * - If the node to delete has no children, it is simply removed.
 * - If the node has one child, the child replaces the node.
 * - If the node has two children, it is replaced by its inorder successor,
 *   and then the successor node is deleted recursively.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* No children or right-child only */
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

	/* Left-child only */
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

	/* Two children */
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
 * 
 * It handles different cases:
 * - If the node to remove is NULL, return the root.
 * - If the value to remove is less than the current node's value,
 *   recursively remove the node from the left subtree.
 * - If the value to remove is greater than the current node's value,
 *   recursively remove the node from the right subtree.
 * - If the value to remove is equal to the current node's value:
 *   - If the node has no children, it is simply removed.
 *   - If the node has one child, the child replaces the node.
 *   - If the node has two children, it is replaced by its inorder successor,
 *     and then the successor node is deleted recursively.
 */

bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
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
 * 
 * It handles different cases:
 * - If the node to remove is NULL, return the root.
 * - If the value to remove is less than the current node's value,
 *   recursively remove the node from the left subtree.
 * - If the value to remove is greater than the current node's value,
 *   recursively remove the node from the right subtree.
 * - If the value to remove is equal to the current node's value:
 *   - If the node has no children, it is simply removed.
 *   - If the node has one child, the child replaces the node.
 *   - If the node has two children, it is replaced by its inorder successor,
 *     and then the successor node is deleted recursively.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
