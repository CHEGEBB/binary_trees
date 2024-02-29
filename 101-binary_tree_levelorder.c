#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - goes through a binary tree using level-order traversal
 * it uses a queue to store the nodes
 * A queue is a data structure that uses a FIFO (First In First Out) order
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * It uses a queue to store the nodes
 * Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    binary_tree_t **queue;
    int front = 0, rear = 0, i = 0;
    const binary_tree_t *current;

    if (!tree || !func)
        return;

    queue = malloc(sizeof(binary_tree_t *) * 1024);
    if (!queue)
        return;

    queue[rear] = (binary_tree_t *)tree;
    rear = (rear + 1) % 1024;

    while (front != rear)
    {
        current = queue[front];
        front = (front + 1) % 1024;
        func(current->n);

        if (current->left)
        {
            queue[rear] = (binary_tree_t *)current->left;
            rear = (rear + 1) % 1024;
        }
        if (current->right)
        {
            queue[rear] = (binary_tree_t *)current->right;
            rear = (rear + 1) % 1024;
        }
    }
    free(queue);
}
