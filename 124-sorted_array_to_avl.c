#include "binary_trees.h"

/**
 * create_avl_node - Create a new AVL node
 * @value: Value to be stored in the node
 * @parent: Pointer to the parent node
 * Return: Pointer to the newly created AVL node
 */
avl_t *create_avl_node(int value, avl_t *parent)
{
    avl_t *node = malloc(sizeof(avl_t));

    if (node == NULL)
        return (NULL);

    node->n = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

/**
 * sorted_array_to_avl_recursive - Recursively builds an AVL tree from an array
 * @array: Pointer to the first element of the array
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray
 * @parent: Pointer to the parent node
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl_recursive(int *array, size_t start, size_t end, avl_t *parent)
{
    if (start > end)
        return (NULL);

    size_t mid = (start + end) / 2;

    avl_t *node = create_avl_node(array[mid], parent);
    if (node == NULL)
        return (NULL);

    node->left = sorted_array_to_avl_recursive(array, start, mid - 1, node);
    node->right = sorted_array_to_avl_recursive(array, mid + 1, end, node);

    return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return (NULL);

    return (sorted_array_to_avl_recursive(array, 0, size - 1, NULL));
}
