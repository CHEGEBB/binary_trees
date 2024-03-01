#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * create_avl_tree - Recursively creates an AVL tree from a sorted array.
 * @parent: Parent node of the current subtree.
 * @array: Pointer to the sorted array.
 * @start: Starting index of the current subtree in the array.
 * @end: Ending index of the current subtree in the array.
 *
 * Return: Pointer to the root of the created AVL tree.
 */
avl_t *create_avl_tree(avl_t *parent, int *array, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;

    avl_t *root = malloc(sizeof(avl_t));
    if (root == NULL)
        return NULL;

    root->n = array[mid];
    root->parent = parent;
    root->left = create_avl_tree(root, array, start, mid - 1);
    root->right = create_avl_tree(root, array, mid + 1, end);

    return root;
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return NULL;

    return create_avl_tree(NULL, array, 0, (int)size - 1);
}
