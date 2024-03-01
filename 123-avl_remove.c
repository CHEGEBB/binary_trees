#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: Pointer to the root node of the AVL tree.
 * @value: Value of the node to remove.
 * Return: Pointer to the new root node of the AVL tree after removal and rebalancing.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (root == NULL)
		return NULL;

	if (value < root->n)
	{
		root->left = avl_remove(root->left, value);
	}
	else if (value > root->n)
	{
		root->right = avl_remove(root->right, value);
	}
	else
	{
		if (root->left == NULL)
		{
			avl_t *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			avl_t *temp = root->left;
			free(root);
			return temp;
		}

		avl_t *temp = root->right;
		while (temp->left != NULL)
			temp = temp->left;

		root->n = temp->n;
		root->right = avl_remove(root->right, temp->n);
	}

	int balance = avl_balance_factor(root);

	if (balance > 1 && avl_balance_factor(root->left) >= 0)
		return avl_rotate_right(root);

	if (balance < -1 && avl_balance_factor(root->right) <= 0)
		return avl_rotate_left(root);

	if (balance > 1 && avl_balance_factor(root->left) < 0)
	{
		root->left = avl_rotate_left(root->left);
		return avl_rotate_right(root);
	}

	if (balance < -1 && avl_balance_factor(root->right) > 0)
	{
		root->right = avl_rotate_right(root->right);
		return avl_rotate_left(root);
	}

	return root;
}
