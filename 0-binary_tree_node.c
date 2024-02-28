#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - Creates a new node for a binary tree
 * @parent: A pointer to the parent node of the node to be created
 * @value: The value to be stored in the new node
 *
 * Return: A pointer to the newly created node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = value; /* Set the value of the new node */
    new_node->parent = parent; /* Set the parent of the new node */
    new_node->left = NULL; /* Initialize the left child of the new node */
    new_node->right = NULL; /* Initialize the right child of the new node */

    return (new_node);
}
