#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_full - checks if a binary tree is full
 * A full binary tree is a binary tree in which each node has exactly zero or two children
 *
 * If tree is NULL, return 0
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is full, 0 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
    /* if tree is NULL, return 0 */
    if (tree == NULL)
        return (0);

    /* if tree is a leaf, return 1 */
    if (tree->left == NULL && tree->right == NULL)
        return (1);
        

    /* if tree has two children, check if both are full */  
    if (tree->left != NULL && tree->right != NULL)
        return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

    return (0);
}
