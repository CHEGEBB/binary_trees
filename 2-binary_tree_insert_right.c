#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node = NULL;

    if (!parent)
        return (NULL);

    new_node = binary_tree_node(parent, value);
    if (!new_node)
        return (NULL);

    if (parent->right)
    {
        new_node->right = parent->right; /* Set right child of new node to right child of parent */
        parent->right->parent = new_node; /* Set parent of right child of parent to new node */
    }

    parent->right = new_node; /* Set right child of parent to new node */
    return (new_node); /* Return the new node */
}
