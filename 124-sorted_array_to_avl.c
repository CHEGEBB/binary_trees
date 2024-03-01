#include "binary_trees.h"
/**
 * aux_sort - Recursively constructs an AVL tree from a sorted array.
 * @parent: Parent node of the current subtree being constructed.
 * @array: Pointer to the sorted array.
 * @start_index: Start index of the current subtree in the array.
 * @end_index: End index of the current subtree in the array.
 *
 * Description:
 * This function recursively constructs an AVL tree from a sorted array. It starts
 * by finding the middle element of the array and creates a node for it. Then, it
 * recursively builds the left and right subtrees using the elements to the left and
 * right of the middle element, respectively.
 *
 * Return:
 * - Pointer to the root node of the constructed AVL tree.
 * - NULL if the start index is greater than the end index.
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root;
	binary_tree_t *aux;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		root->left = aux_sort(root, array, begin, mid - 1);
		root->right = aux_sort(root, array, mid + 1, last);
		return (root);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - create a alv tree from sorted array
 * @array: sorted array
 * @size: size of the sorted array
 * Return: alv tree form sorted array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}
