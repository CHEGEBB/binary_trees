#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * balance_factor - Calculates the balance factor of an AVL tree.
 * @tree: Pointer to the root of the AVL tree.
 * This function computes the balance factor of the AVL tree,
 * which is the difference in height between the left and right subtrees.
 * Return: The balance factor of the AVL tree.
 */
void bal(avl_t **tree)
{
	if (tree == NULL || *tree == NULL)
		return;

	bal_recursive(tree);
}

/**
 * bal_recursive - Recursively balances an AVL tree.
 * @tree: Pointer to the root of the AVL tree.
 * This function recursively calculates the balance factor of each node,
 * then performs rotations if necessary.
 */
void bal_recursive(avl_t **tree)
{
	int bval;

	if (*tree == NULL)
		return;

	bal_recursive(&((*tree)->left));
	bal_recursive(&((*tree)->right));

	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	bval = avl_balance_factor(*tree);
	if (bval > 1)
		*tree = avl_rotate_right(*tree);
	else if (bval < -1)
		*tree = avl_rotate_left(*tree);
}

/**
 * successor - Finds the minimum value node in the right subtree.
 * @node: Pointer to the node to start from.
 * This function traverses the right subtree of a given node to find
 * the minimum value node, which is the successor in a BST.
 * Return: The value of the minimum node in the right subtree,
 *or 0 if the node is NULL or if there is no right subtree.
 */
int successor(bst_t *node)
{
    if (node == NULL)
        return 0;

    while (node->left != NULL)
        node = node->left;

    return node->n;
}

/**
 * remove_type - Removes a node from a binary search tree depending on its children.
 * @root: Pointer to the node to remove.
 * This function removes a node from a binary search tree based on its children.
 * If the node has no children, it is simply removed from the tree.
 * If the node has only one child, that child is connected to the parent of the node.
 * If the node has two children, the value of the node is replaced with the value of its successor,
 * and then the successor node is removed.
 * Return: 0 if the node has no children, or the value of the successor node.
 */

int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}
/**
 * bst_remove - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - remove a node from a AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}
