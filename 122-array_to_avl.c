#include "binary_trees.h"
#include <stdlib.h>

/**
 * array_to_avl - Constructs an AVL tree from an array of integers.
 * @array: Pointer to the first element of the integer array.
 * @size: Number of elements in the array.
 * This function takes an integer array and its size as input and constructs
 * an AVL tree using the elements of the array. Each element of the array
 * is considered a unique key in the AVL tree.
 * Return: Pointer to the root node of the created AVL tree, or NULL if failure.
 */

avl_t *array_to_avl(int *array, size_t size)
{
    /* Declare a pointer to the root node of the AVL tree. */
    avl_t *tree = NULL;
    size_t i;

    /* If the array is NULL or empty, return NULL. */
    for (i = 0; i < size; i++)
        avl_insert(&tree, array[i]);
    return (tree);
}