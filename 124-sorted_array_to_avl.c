#include "binary_trees.h"

/**
 * sorted_array_to_avl_recursive - Recursively builds an AVL tree from an array
 * @array: Pointer to the first element of the array
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl_recursive(int *array, size_t start, size_t end)
{
    avl_t *node;
    size_t mid;

    /* Base case: if start index exceeds end index, return NULL */
    if (start > end)
        return (NULL);

    /* Calculate mid index */
    mid = (start + end) / 2;

    /* Create a new AVL node with the value at the mid index */
    node = avl_node(array[mid]);

    /* Check if node creation failed */
    if (node == NULL)
        return (NULL);

    /* Recursively build the left subtree with elements before mid */
    node->left = sorted_array_to_avl_recursive(array, start, mid - 1);

    /* Recursively build the right subtree with elements after mid */
    node->right = sorted_array_to_avl_recursive(array, mid + 1, end);

    /* Return the root of the AVL tree */
    return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    /* Check if the array is NULL or empty */
    if (array == NULL || size == 0)
        return (NULL);

    /* Call the recursive function to build the AVL tree */
    return (sorted_array_to_avl_recursive(array, 0, size - 1));
}
