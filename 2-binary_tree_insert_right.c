#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
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

    
        new_node->right = parent->right;/*set the right child of the new node to the right child of the parent */
        parent->right->parent = new_node;/*set the parent of the right child of the parent to the new node */


    }
    
    parent->right = new_node;/*set the right child of the parent to the new node */
    return (new_node);/*return the new node */
}
