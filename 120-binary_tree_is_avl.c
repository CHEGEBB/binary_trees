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

int is_balanced(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (1);

    left_height = height(tree->left);
    right_height = height(tree->right);

    if (abs(left_height - right_height) <= 1 &&
        is_balanced(tree->left) &&
        is_balanced(tree->right))
        return (1);

    return (0);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, otherwise 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    if (!is_balanced(tree))
        return (0);

    if (!binary_tree_is_bst(tree))
        return (0);

    return (1);
}
