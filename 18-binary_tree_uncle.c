#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 * An uncle refers to the sibling of a node's parent.
 * If the node has no uncle (e.g., it's the root node or has no grandparent),
 * the function returns NULL.
 * 
 * @node: A pointer to the node to find the uncle of.
 *
 * Return: A pointer to the uncle node, or NULL if no uncle exists.
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    /* If the node is NULL or has no parent, return NULL */
    
    if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
        return (NULL);

    /* If the node's parent is the left child, return the right child */
    if (node->parent->parent->left == node->parent)
        return (node->parent->parent->right);

    /* If the node's parent is the right child, return the left child */
    else
        return (node->parent->parent->left);

}
