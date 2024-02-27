//function that creates a binary tree node
#include "binary_trees.h"

/**
 * binary_tree_node - This function creates a new node for a binary tree.
 *
 * Description: This function creates a new node for a binary tree with the
 * specified value and parent node. It allocates memory for the new node and
 * initializes its value and parent pointer.
 *
 * @parent: A pointer to the parent node of the node to create.
 * @value: The value to store in the new node.
 *
 * Return: If successful, a pointer to the newly created node is returned.
 * If memory allocation fails or the parent pointer is NULL, NULL is returned
 * to indicate failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}