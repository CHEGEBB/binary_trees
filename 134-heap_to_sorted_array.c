#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array of
 *integers.
 * @heap: Pointer to the root node of the heap to convert.
 * @size: Address to store the size of the array.
 * Description: This function takes the root node of a Binary Max Heap and
 *converts it into a sorted array of integers. It also updates
 *the size variable with the size of the resulting array.
 * Return: Sorted array of integers.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *array; /* Pointer to store the sorted array */
    int extract; /* Variable to store extracted value from the heap */
    size_t heap_size; /* Variable to store the size of the heap */
    int i = 0; /* Index variable for array traversal */

    /* If heap is NULL, return NULL */
    if (!heap)
        return (NULL);
    
    /* Calculate the size of the heap */
    heap_size = binary_tree_size(heap);
    /* Update the size variable with the size of the resulting array */
    *size = heap_size;
    
    /* Allocate memory for the array */
    array = malloc(heap_size * sizeof(int));
    /* If memory allocation fails, return NULL */
    if (!array)
        return (NULL);
    
    /* Extract elements from the heap and store them in the array */
    while (heap)
    {
        /* Extract root node of the heap */
        extract = heap_extract(&heap);
        /* Store the extracted value in the array */
        array[i] = extract;
        /* Increment array index */
        i++;
    }
    
    /* Return the sorted array */
    return (array);
}
