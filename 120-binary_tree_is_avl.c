#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_insert - Inserts a value into a Binary Search Tree.
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: Value to store in the node to be inserted.
 * Description:
 * This function inserts a new node with the given value into the specified
 * Binary Search Tree (BST). It ensures that the resulting tree remains a valid
 * BST after insertion, preserving the ordering property of BSTs.
 * Return: Pointer to the created node, or NULL on failure.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node = NULL, *current = NULL;

    if (!tree)
        return (NULL);

    if (!*tree)
    {
        new_node = binary_tree_node(NULL, value);
        *tree = new_node;
        return (new_node);
    }

    current = *tree;
    while (current)
    {
        if (value == current->n)
            return (NULL);
        if (value < current->n)
        {
            if (!current->left)
            {
                new_node = binary_tree_node(current, value);
                current->left = new_node;
                return (new_node);
            }
            current = current->left;
        }
        else
        {
            if (!current->right)
            {
                new_node = binary_tree_node(current, value);
                current->right = new_node;
                return (new_node);
            }
            current = current->right;
        }
    }
    return (NULL);
}
