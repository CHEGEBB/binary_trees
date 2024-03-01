#include "binary_trees.h"
#include <stdlib.h>

/**
 * array_to_bst - Builds a Binary Search Tree from an array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in the array.
 * Description:
 * This function builds a Binary Search Tree (BST) from an array of integers.
 * It ensures that the resulting tree remains a valid BST after insertion,
 * preserving the ordering property of BSTs.
 * Return: Pointer to the root node of the created BST, or NULL on failure.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i;

	if (!array || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
		bst_insert(&tree, array[i]);
	return (NULL);return (tree);
}
