#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array.
 * This function constructs a Max Binary Heap tree from the given array of
 * elements. It takes the input array and its size as arguments. If successful,
 * it returns a pointer to the root node of the created Max Binary Heap; otherwise,
 * it returns NULL.
 * @array: Pointer to the first element of the input array.
 * @size: The number of elements in the array.
 * Return: Pointer to the root node of the created Max Binary Heap, or NULL on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	/* Local Declarations */
	size_t i = 0;
	heap_t *root = NULL;

	/* Main Execution */
	if (!array)
		return (NULL);
	while (i < size)
	{
		/* Insert each element into the heap */
		heap_insert(&root, array[i]);
		i++;
	}
	return (root);
}
