#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * bal - Measures balance factor of an AVL tree.
 * @tree: Pointer to the root node of the AVL tree.
 * Return: Balance factor of the AVL tree.
 *
 * Description: This function calculates the balance factor of an AVL tree.
 * The balance factor of a node is calculated as the height of its left
 * subtree minus the height of its right subtree.
 * A balanced tree has a balance factor of -1, 0, or 1.
 */
void bal(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	bval = binary_tree_balance((const binary_tree_t *)*tree);
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * successor - Finds the minimum value in the right subtree
 * @node: Pointer to the node to examine
 * 
 * Description:
 *   This function recursively finds the minimum value in the right subtree
 *   of the given node in a binary search tree (BST).
 *
 * Return: The minimum value of the right subtree.
 */

int successor(bst_t *node)
{
  /*Initialize a variable to store the result from the left subtree*/
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}
/**
 * remove_type - Removes a node based on its children.
 * @root: Pointer to the node to remove.
 * Description:
 *   This function removes a node from the tree based on its children. If the
 *   node has no children, it is simply removed. If the node has one child, 
 *   the child is linked to the parent of the node to be removed. If the node 
 *   has two children, it is replaced by its successor.
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
 * bst_remove - Removes a node with a specific value from a BST tree.
 * @root: Pointer to the root of the BST tree.
 * @value: Value of the node to remove.
 *   This function removes a node with a specific value from a Binary Search
 *   Tree (BST). If the value is found in the tree, the node containing that
 *   value is removed, and the tree is rebalanced if necessary
 *   Pointer to the root of the BST tree after removal.
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
 * avl_remove - Removes a node with a specific value from an AVL tree.
 * @root: Pointer to the root of the AVL tree.
 * @value: Value of the node to remove
 * Description:
 *   This function removes a node with a specific value from an AVL
 *   (Adelson-Velsky and Landis) tree. If the value is found in the tree,
 *   the node containing that value is removed, and the tree is rebalanced
 *   if necessary to maintain the AVL property.
 * Return:
 *   Pointer to the root of the AVL tree after removal.
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}
