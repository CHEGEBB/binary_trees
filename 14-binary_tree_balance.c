#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * The balance factor is calculated as the difference between the height of the
 * left subtree and the right subtree
 * A balance factor of 0 indicates that the subtrees are balanced
 * A balance factor of -1 indicates that the left subtree is higher than the right
 * A balance factor of 1 indicates that the right subtree is higher than the left
 * @tree: Pointer to the root node of the tree to measure the balance factor
 * Return: Balance factor of the tree
 */

int binary_tree_balance(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (left_height - right_height);
}
