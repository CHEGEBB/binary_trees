#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * avl_rotate_left - Rotate an AVL tree to the left.
 * @tree: Pointer to the root node of the AVL tree.
 * Return: Pointer to the new root node of the rotated AVL tree.
 */
avl_t *avl_rotate_left(avl_t *tree);

/**
 * avl_rotate_right - Rotate an AVL tree to the right.
 * @tree: Pointer to the root node of the AVL tree.
 * Return: Pointer to the new root node of the rotated AVL tree.
 */
avl_t *avl_rotate_right(avl_t *tree);

/**
 * avl_balance_factor - Calculate the balance factor of an AVL tree.
 * @tree: Pointer to the root node of the AVL tree.
 * Return: Balance factor of the AVL tree.
 */
int avl_balance_factor(const avl_t *tree);

/**
 * bst_remove - Remove a node from a BST tree.
 * @root: Pointer to the root node of the BST tree.
 * @value: Value of the node to remove.
 * Return: Pointer to the new root node of the BST tree after removal.
 */
bst_t *bst_remove(bst_t *root, int value);

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: Pointer to the root node of the AVL tree.
 * @value: Value of the node to remove.
 * Return: Pointer to the new root node of the AVL tree after removal and rebalancing.
 */
avl_t *avl_remove(avl_t *root, int value)
{
    if (root == NULL)
        return NULL;

    /* Remove the node from the BST */
    root = bst_remove(root, value);

    /* Rebalance the tree */
    while (root != NULL)
    {
        int balance = avl_balance_factor(root);

        if (balance > 1)
            root = avl_rotate_right(root);
        else if (balance < -1)
            root = avl_rotate_left(root);
        else
            break;
    }

    return root;
}
