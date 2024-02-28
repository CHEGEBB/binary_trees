#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - Measures the size of a binary tree
 * The size of a binary tree is the number of nodes in the tree
 * size of a NULL tree is 0
 * @tree: Pointer to the root node of the tree to measure the size
 * Return: The size of the tree. If tree is NULL, the function must return 0.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
    /* Declare left_size and right_size */
    size_t left_size, right_size;

    /* If tree is NULL, return 0 */
    if (tree == NULL)
        return (0);

    /* Recursively call binary_tree_size on the left and right children of the tree */
    left_size = binary_tree_size(tree->left);
    right_size = binary_tree_size(tree->right);

    /* Return the sum of left_size, right_size, and 1 */
    return (left_size + right_size + 1);
}
