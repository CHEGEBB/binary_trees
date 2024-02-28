#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 * A sibling refers to nodes that share the same parent.
 * If the node has no sibling (e.g., it's the root node or has no parent),
 * the function returns NULL.
 * 
 * @node: A pointer to the node to find the sibling of.
 *
 * Return: A pointer to the sibling node, or NULL if no sibling exists.
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    /* If the node is NULL or has no parent, return NULL */
    
    if (node == NULL || node->parent == NULL)
        return (NULL);

    /* If the node is the left child, return the right child */
    if (node->parent->left == node)
        return (node->parent->right);

    /* If the node is the right child, return the left child */
    else
        return (node->parent->left);

}
