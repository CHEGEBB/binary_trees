#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * aux_sort - Recursively creates an AVL tree from a sorted array.
 * @parent: Parent node of the current subtree.
 * @array: Pointer to the sorted array.
 * @begin: Starting index of the current subtree in the array.
 * @last: Ending index of the current subtree in the array.
 *
 * Return: Pointer to the root of the created AVL tree.
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
    avl_t *root;
    binary_tree_t *temp_node;
    int mid_index = 0;

    /* Base case: If the beginning index is greater than the last index, return NULL */
    if (begin <= last)
    {
        /* Calculate the middle index */
        mid_index = (begin + last) / 2;

        /* Create a new node with the value of the middle element */
        temp_node = binary_tree_node((binary_tree_t *)parent, array[mid_index]);
        if (temp_node == NULL)
            return (NULL);

        /* Cast the node to an AVL node */
        root = (avl_t *)temp_node;

        /* Recursively build the left subtree with elements to the left of the middle */
        root->left = aux_sort(root, array, begin, mid_index - 1);

        /* Recursively build the right subtree with elements to the right of the middle */
        root->right = aux_sort(root, array, mid_index + 1, last);

        return (root);
    }
    return (NULL);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in the array.
 *
 * Description:
 * This function constructs an AVL tree from a sorted array. The array is expected
 * to be sorted in ascending order. AVL insertion algorithm is utilized for building
 * the tree.
 *
 * Return:
 * - Pointer to the root node of the created AVL tree if successful.
 * - NULL if the array is NULL or empty.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    /* Check if the array is NULL or empty */
    if (array == NULL || size == 0)
        return NULL;
    
    /* Call the auxiliary function to recursively build the AVL tree */
    return aux_sort(NULL, array, 0, (int)(size) - 1);
}
