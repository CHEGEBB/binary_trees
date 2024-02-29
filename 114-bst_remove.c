#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: Pointer to the root node of the BST to remove the value from.
 * @value: Value to remove from the tree.
 * Description:
 * This function removes a node with the given value from the specified Binary
 * Search Tree (BST). It ensures that the resulting tree remains a valid BST
 * after removal, preserving the ordering property of BSTs.
 * Return: Pointer to the new root of the tree after removing the value.
 */

bst_t *bst_remove(bst_t *root, int value)
{
    bst_t *node = NULL, *successor = NULL;

    if (!root)
        return (NULL);

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else
    {
        if (!root->left)
        {
            node = root->right;
            free(root);
            return (node);
        }
        else if (!root->right)
        {
            node = root->left;
            free(root);
            return (node);
        }
        successor = root->right;
        while (successor->left)
            successor = successor->left;
        root->n = successor->n;
        root->right = bst_remove(root->right, successor->n);
    }
    return (root);
}
