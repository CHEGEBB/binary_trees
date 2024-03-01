#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 *
 * Description:
 * This function builds an AVL tree from an array. The array is assumed to be
 * sorted in ascending order, and the tree is built using the AVL insertion
 * algorithm.
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i;

<<<<<<< HEAD
	if (array == NULL || size == 0)
		return (NULL);
	for (i = 0; i < size; i++)
		avl_insert(&tree, array[i]);
=======
	/* Check if the array is NULL or empty */
	if (array == NULL || size == 0)
		return (NULL);

	/* Insert each element of the array into the AVL tree */
	for (i = 0; i < size; i++)
		avl_insert(&tree, array[i]);

	/* Return the root of the AVL tree */
>>>>>>> 57259eae5901c1b79f27c9992f451230db466f27
	return (tree);
}
