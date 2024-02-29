#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 *
 * Description:
 * This function checks whether the given binary tree satisfies the properties
 * of a Binary Search Tree (BST). A BST is a binary tree where the value of
 * every node in the left subtree is less than the value of the node itself,
 * and the value of every node in the right subtree is greater than the value
 * of the node itself.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return:
 * 1 if the tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (1); // Empty tree is a valid BST

    return (bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * bst_helper - Helper function to recursively check if a binary tree is a BST.
 *
 * @tree: Pointer to the root node of the tree to check.
 * @min: Minimum value allowed for nodes in the tree.
 * @max: Maximum value allowed for nodes in the tree.
 *
 * Return:
 * 1 if the subtree rooted at 'tree' is a valid BST, 0 otherwise.
 */
int bst_helper(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1); // Empty subtree is a valid BST

    if (tree->n <= min || tree->n >= max)
        return (0); // Node violates BST property

    // Recursively check left and right subtrees
    return (bst_helper(tree->left, min, tree->n) &&
            bst_helper(tree->right, tree->n, max));
}
