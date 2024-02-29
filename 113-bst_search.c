#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_search - Searches for a value in a Binary Search Tree.
 * @tree: Pointer to the root node of the BST to search.
 * @value: Value to search for in the tree.
 * Description:
 * This function searches for a value in a Binary Search Tree (BST). It returns
 * a pointer to the node containing the value, or NULL if the value is not found.
 * Return: Pointer to the node containing the value, or NULL if not found.
 */

bst_t *bst_search(const bst_t *tree, int value)
{
    if (!tree)
        return (NULL);

    if (value == tree->n)
        return ((bst_t *)tree);

    if (value < tree->n)
        return (bst_search(tree->left, value));
    return (bst_search(tree->right, value));
}
