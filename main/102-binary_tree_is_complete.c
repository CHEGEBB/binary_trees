#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * A complete binary tree is a binary tree in which every level, except possibly
 * the last, is completely filled, and all nodes are as far left as possible.
 * This function uses a level-order traversal to determine if the tree is complete.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 * If the tree is NULL, returns 0.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Initialize a queue to perform level-order traversal */
	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (queue == NULL)
		return (0);

	int front = 0, rear = 0;
	int complete_flag = 0; /* Flag to track completeness */

	queue[rear] = (binary_tree_t *)tree;
	rear = (rear + 1) % 1024;

	while (front != rear)
	{
		binary_tree_t *current = queue[front];
		front = (front + 1) % 1024;

		/* If a node has no left child but has a right child, it's not complete */
		if (current->left == NULL && current->right != NULL)
		{
			free(queue);
			return (0);
		}

		/* If we have encountered a NULL node, mark the flag */
		if (current == NULL)
			complete_flag = 1;
		else
		{
			/* If a node has a left child but no right child, mark the flag */
			if (complete_flag == 1 && current->right != NULL)
			{
				free(queue);
				return (0);
			}

			/* Enqueue left child */
			if (current->left)
			{
				queue[rear] = current->left;
				rear = (rear + 1) % 1024;
			}

			/* Enqueue right child */
			if (current->right)
			{
				queue[rear] = current->right;
				rear = (rear + 1) % 1024;
			}
		}
	}

	free(queue);
	return (1);
}
