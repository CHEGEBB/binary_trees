#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree recursively.
 * @tree: Pointer to the root node of the binary tree.
 * This function recursively calculates the size of the binary tree by counting
 * the number of nodes in both the left and right subtrees, then adding 1 for
 * the current node.
 * @return: Size of the binary tree, or 0 if the tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    /* Check if the tree is NULL */
    if (tree == NULL)
        return (0);

    /* Recursively calculate the size of the left and right subtrees */
    return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the binary tree.
 * @i: Index of the current node in a complete binary tree.
 * @cnodes: Total number of nodes in the binary tree.
 *
 * This function recursively checks if the binary tree is complete by
 * traversing the tree in an inorder manner and verifying if each node
 * has the correct index based on the total number of nodes.
 * @return: 1 if the binary tree is complete, 0 otherwise.
 */
int tree_is_complete(const binary_tree_t *tree, unsigned int i, unsigned int cnodes)
{
    /* Check if the tree is NULL */
    if (tree == NULL)
        return (1);

    /* Check if the current node index exceeds the total number of nodes */
    if (i >= cnodes)
        return (0);

    /* Recursively check if the left and right subtrees are complete */
    return (tree_is_complete(tree->left, 2 * i + 1, cnodes) &&
            tree_is_complete(tree->right, 2 * i + 2, cnodes));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the binary tree.
 * This function calls the tree_is_complete function to check if the binary tree
 * is complete by traversing the tree in an inorder manner and verifying if each
 * node has the correct index based on the total number of nodes.
 * @return: 1 if the binary tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    /* Variable to store the total number of nodes in the binary tree */
    unsigned int total_nodes = binary_tree_size(tree);

    /* Check if the tree is NULL */
    if (tree == NULL)
        return (0);

    /* Call the tree_is_complete function to check if the binary tree is complete */
    return (tree_is_complete(tree, 0, total_nodes));
}

/**
 * check_parent - Checks if a node's parent has a greater value than its children.
 * @tree: Pointer to the node.
 * This function recursively checks if a node's parent has a greater value
 * than its children in a binary tree.
 * @return: 1 if the parent has a greater value, 0 otherwise.
 */
int check_parent(const binary_tree_t *tree)
{
    /* Check if the tree is NULL */
    if (tree == NULL)
        return (1);

    /* Check if the parent's value is greater than the node's value */
    if (tree->parent != NULL && tree->n > tree->parent->n)
        return (0);

    /* Recursively check the left and right subtrees */
    return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a Max Binary Heap.
 * @tree: Pointer to the root node of the binary tree.
 * This function checks if the input binary tree is a Max Binary Heap by
 * verifying if it is complete and if each node's parent has a greater value
 * than its children.
 * @return: 1 if the binary tree is a Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    /* Check if the binary tree is complete */
    if (!binary_tree_is_complete(tree))
        return (0);

    /* Check if each node's parent has a greater value than its children */
    return (check_parent(tree->left) && check_parent(tree->right));
}
