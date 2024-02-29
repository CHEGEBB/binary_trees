#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_rotate_right - Rotates a binary tree to the right.
 * Description:
 * This function performs a right rotation on a binary tree. A right rotation
 * involves moving the left child of the given node up to the node's position,
 * with the original node becoming the right child of the new node.
 * @tree: Pointer to the root node of the tree to rotate.
 * Return:
 * Pointer to the new root node of the tree after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    binary_tree_t *new_root;

    /* Check if the tree or its left child is NULL */
    if (tree == NULL || tree->left == NULL)
        return (NULL);

    /* Store the left child of the current root as the new root */
    new_root = tree->left;

    /* Make the right subtree of the new root*/
    tree->left = new_root->right;

    /* Update the parent of the right subtree, if it exists */
    if (new_root->right != NULL)
        new_root->right->parent = tree;

    /* Make the original root the right child of the new root */
    new_root->right = tree;

    /* Update the parent of the new root */
    new_root->parent = tree->parent;

    /* Update the parent of the original root */
    tree->parent = new_root;

    /* Return the new root of the tree */
    return (new_root);
}

