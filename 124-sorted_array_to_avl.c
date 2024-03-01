#include "binary_trees.h"

/**
 * sorted_array_to_avl - Creates an AVL tree from a sorted array
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return (NULL);

    return (aux_sort(NULL, array, 0, (int)(size) - 1));
}
