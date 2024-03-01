#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * bal - Measures balance factor of an AVL tree
 * @tree: tree to go through
 *
 * Return: balanced factor
 *
 * Description: This function measures the balance factor of an AVL tree.
 * It checks if the tree is unbalanced and performs rotations accordingly
 * to maintain the AVL property.
 */
void bal(avl_t **tree)
{
	int bval;

	/* If the tree or the current node is NULL, return */
	if (tree == NULL || *tree == NULL)
		return;

	/* If the current node is a leaf node, return */
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	/* Recursively balance the left and right subtrees */
	bal(&(*tree)->left);
	bal(&(*tree)->right);

	/* Calculate the balance factor of the current node */
	bval = binary_tree_balance((const binary_tree_t *)*tree);

	/* If the balance factor is greater than 1, perform a right rotation */
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	/* If the balance factor is less than -1, perform a left rotation */
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * successor - get the next successor i mean the min node in the right subtree
 * @node: tree to check
 *
 * Return: the min value of this tree
 *
 * Description: This function finds the next successor of a given node
 * in a binary search tree (BST), which is the minimum value in the right
 * subtree of the given node.
 */
int successor(bst_t *node)
{
	int left = 0;

	/* If the node is NULL, return 0 */
	if (node == NULL)
		return (0);

	/* Recursively find the minimum value in the left subtree */
	left = successor(node->left);
	/* If the minimum value in the left subtree is */
	if (left == 0)
		return (node->n);
	/* Otherwise, return the minimum value found in the left subtree */
	return (left);
}

/**
 * remove_type - function that removes a node depending on its children
 * @root: node to remove
 *
 * Return: 0 if it has no children, or the value of its successor if it has
 *
 * Description: This function removes a node from a binary search tree (BST)
 * depending on its children. If the node has no children, it is removed from
 * the tree. If the node has one child, the child replaces the node. If the
 * node has two children, its successor replaces the node.
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	/* If the node has no children */
	if (!root->left && !root->right)
	{
		/* Remove the node from the tree */
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
 * Description: This function removes a node with a specific value from
 * a binary search tree (BST) while maintaining its BST properties.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	/* If the root is NULL, return NULL */
	if (root == NULL)
		return (NULL);

	/* Search for the node with the given value */
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		/* Remove the node */
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);

	return (root);
}

/**
 * avl_remove - remove a node from an AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 *
 * Description: This function removes a node with a specific value from
 * an AVL tree while maintaining its AVL properties.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	/* Call the BST removal function */
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	/* Balance the tree */
	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}
