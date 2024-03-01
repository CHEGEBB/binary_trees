#include "binary_trees.h"
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>


/**
 * is_heap_recursive - Helper function to recursively check if a binary tree
 *satisfies the Max Heap property.
 * @tree: Pointer to the current node in the binary tree.
 * @index: Current index of the node in the binary tree.
 * @size: Total number of nodes in the binary tree.
 * Return: 1 if the subtree rooted at 'tree' satisfies the Max Heap property,
 *and 0 otherwise.
 */

int is_heap_recursive(const binary_tree_t *tree, size_t index, size_t size)
{
    /* If the current node is NULL, it is a heap */
    if (tree == NULL)
        return (1);

/* If an index is greater than or equal to the size of the tree, it is not a heap */
    if (index >= size)
        return (0);

    if (tree->n > INT_MAX)
        return (0);

    if (tree->left != NULL && tree->left->n > tree->n)
        return (0);

    if (tree->right != NULL && tree->right->n > tree->n)
        return (0);

    return (is_heap_recursive(tree->left, 2 * index + 1, size) &&
        is_heap_recursive(tree->right, 2 * index + 2, size));
}
