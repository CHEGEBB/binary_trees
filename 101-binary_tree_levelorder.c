#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 *                           It uses a queue to store the nodes.
 *                           A queue is a data structure that uses a FIFO
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 *
 * Return: Void.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue;
	int front = 0, rear = 0;
	const binary_tree_t *current;

	/* Check if the tree or func is NULL */
	if (!tree || !func)
		return;

	/* Allocate memory for the queue */
	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (!queue)
		return;

	/* Enqueue the root node */
	queue[rear] = (binary_tree_t *)tree;
	rear = (rear + 1) % 1024;

	/* Perform level-order traversal */
	while (front != rear)
	{
		current = queue[front];
		front = (front + 1) % 1024;
		func(current->n);

		/* Enqueue left child if exists */
		if (current->left)
		{
			queue[rear] = (binary_tree_t *)current->left;
			rear = (rear + 1) % 1024;
		}

		/* Enqueue right child if exists */
		if (current->right)
		{
			queue[rear] = (binary_tree_t *)current->right;
			rear = (rear + 1) % 1024;
		}
	}
	free(queue);
}
