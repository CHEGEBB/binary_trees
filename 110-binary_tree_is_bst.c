#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

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
    /* Base case: an empty tree is considered a valid BST */
    if (tree == NULL)
        return (1);

    /* Check if the left child is less than the current node */
    if (tree->left != NULL && tree->left->n >= tree->n)
        return (0);

    /* Check if the right child is greater than or equal to the current node */
    if (tree->right != NULL && tree->right->n <= tree->n)
        return (0);

    /* Recursively check the left and right subtrees */
    if (!binary_tree_is_bst(tree->left) || !binary_tree_is_bst(tree->right))
        return (0);

    /* If all conditions are met, the tree is a valid BST */
    return (1);
}
