#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * it is a leaf if it has no children
 * children are left and right nodes of a parent node
 * @tree: Pointer to the root node of the tree to count the number of leaves
 *number of leaves in a binary tree are the nodes that have no children
 * Return: Number of leaves in the tree
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
    /* if tree is NULL, return 0 */
    if (tree == NULL)
        return (0);

    /* if tree has no children, return 1 */
    if (tree->left == NULL && tree->right == NULL)
        return (1);

    /* else, return the sum of the leaves of the left and right children */
    return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
