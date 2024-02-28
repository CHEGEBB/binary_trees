#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_leaf - Checks if a node is a leaf in a binary tree.
 * function that checks if a node is a leaf
 * if the node is a leaf, return 1
 * @node: Pointer to the node to check.
 *
 * Return: 1 if node is a leaf, 0 otherwise.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
    /* Check if the node pointer is NULL */
    if (node == NULL)
        return (0);

    /* Check if the node has no children */
    if (node->left == NULL && node->right == NULL)
        return (1); /* Node is a leaf */

    return (0); /* Node is not a leaf */
}
