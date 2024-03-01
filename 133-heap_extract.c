#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

#define INIT_NODE {0, NULL, NULL, NULL}

#define CONVERT "0123456789ABCDEF"

#define SETUP_NODE_BLOC { \
	tmp = *root; \
	size = binary_tree_size(*root); \
	binary = &buffer[49]; \
	*binary = 0; \
	}

#define FREE_NODE_BLOC { \
		res = tmp->n; \
		free(tmp); \
		*root = NULL; \
	}

#define SWAP_HEAD_BLOC { \
		head = *root; \
		head = swap_head(head, tmp); \
		res = head->n; \
		free(head); \
		*root = tmp; \
		tmp = perc_down(tmp); \
		*root = tmp; \
	}

#define CONVERT_LOOP { \
		*--binary = CONVERT[size % 2]; \
		size /= 2; \
	}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the binary tree.
 * Return: Height of the binary tree, or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * swap_values - Swaps the values of two binary tree nodes.
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 */
void swap_values(binary_tree_t *a, binary_tree_t *b)
{
    int temp = a->n;
    a->n = b->n;
    b->n = temp;
}

/**
 * heapify_down - Restores the Max Heap property by moving a node down.
 * @root: Pointer to the root node of the Max Binary Heap.
 */
void heapify_down(binary_tree_t *root)
{
    binary_tree_t *largest = root;
    binary_tree_t *left = root->left;
    binary_tree_t *right = root->right;

    if (left && left->n > largest->n)
        largest = left;

    if (right && right->n > largest->n)
        largest = right;

    if (largest != root)
    {
        swap_values(root, largest);
        heapify_down(largest);
    }
}

/**
 * remove_last_node - Removes the last node in the last level-order of the heap.
 * @root: Pointer to the root node of the Max Binary Heap.
 */
void remove_last_node(binary_tree_t *root)
{
    binary_tree_t *last_node = NULL;
    size_t height = binary_tree_height(root);

    if (height == 0)
        return;

    if (height == 1)
    {
        free(root);
        return;
    }

    if (binary_tree_height(root->right) == height - 1)
        last_node = root->right;
    else
        last_node = root->left;

    while (height > 2)
    {
        if (binary_tree_height(last_node->right) == height - 2)
            last_node = last_node->right;
        else
            last_node = last_node->left;
        height--;
    }

    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    else
        last_node->parent->right = NULL;

    free(last_node);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the Max Binary Heap.
 * Return: The value stored in the root node of the Max Binary Heap,
 *         or 0 if the heap is empty or an error occurs.
 */
int heap_extract(heap_t **root)
{
    int extracted_value;

    if (root == NULL || *root == NULL)
        return (0);

    extracted_value = (*root)->n;

    if ((*root)->left == NULL && (*root)->right == NULL)
    {
        free(*root);
        *root = NULL;
        return (extracted_value);
    }

    swap_values(*root, *root);
    remove_last_node(*root);
    heapify_down(*root);

    return (extracted_value);
}
