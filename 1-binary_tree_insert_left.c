#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node = NULL;

    if (!parent)
        return (NULL);
    new_node = binary_tree_node(parent, value);
    if (!new_node)
        return (NULL);
    if (parent->left)
    {
        new_node->left = parent->left;/* Set the left child of the new node to the left child of the parent */
        parent->left->parent = new_node;/* Set the parent of the left child of the parent to the new node */

    }
    parent->left = new_node;/* Set the left child of the parent to the new node */
    return (new_node);/* Return the new node */
}
