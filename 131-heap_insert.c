#include "binary_trees.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define INIT_NODE {0, NULL, NULL, NULL}

/**
 * swap - Swaps the positions of two nodes in a binary tree.
 * This function swaps the positions of two nodes in a binary tree. It takes
 * two pointers to nodes (a and b) as arguments and swaps their positions. The
 * function returns a pointer to the root node of the tree after the swap.
 * @a: Pointer to the first node to be swapped.
 * @b: Pointer to the second node to be swapped.
 * Return: Pointer to the root node of the tree after the swap.
 */
bst_t *swap(bst_t *a, bst_t *b)
{
    bst_t a_copy = INIT_NODE;

    /* Copy the values of a into a_copy */
    a_copy.n = a->n;
    a_copy.parent = a->parent;
    a_copy.left = a->left;
    a_copy.right = a->right;
    a->parent = b;
    a->left = b->left;
    a->right = b->right;

    /* Update the parent of b's left child */
    if (b->left)
        b->left->parent = a;
    if (b->right)
        b->right->parent = a;

    /* Copy the values of b into a */
    b->parent = a_copy.parent;
    if (a_copy.parent)
    {
        if (a == a_copy.parent->left)
            a_copy.parent->left = b;
        else
            a_copy.parent->right = b;
    }
    /* Update the parent of a's left child */
    if (b == a_copy.left)
    {
        b->left = a;
        b->right = a_copy.right;
        if (a_copy.right)
            a_copy.right->parent = b;
    }
    /* Update the parent of a's right child */
    else if (b == a_copy.right)
    {
        b->right = a;
        b->left = a_copy.left;
        if (a_copy.left)
            a_copy.left->parent = b;
    }
    while (b->parent)
        b = b->parent;
    return (b);
}

/**
 * convert - Converts a number from base 10 to another base and returns the string representation.
 * This function takes an input number (num) in base 10 and converts it to the specified base,
 * generating a string representation of the converted number. The base can be any integer value
 * greater than 1. Additionally, if the lowercase flag is set to 1, hexadecimal values will be
 * represented in lowercase letters; otherwise, they will be uppercase.
 * @num: The input number to be converted.
 * @base: The base to convert the number to.
 * @lowercase: A flag indicating whether hexa values should be lowercase (1) or uppercase (0).
 * Return: A pointer to the string representation of the converted number.
 */
char *convert(unsigned long int num, int base, int lowercase)
{
    static char *rep;
    static char buffer[50];
    char *ptr;

    /* Set the representation to lowercase or uppercase */
    rep = (lowercase) ? "0123456789abcdef" : "0123456789ABCDEF";
    ptr = &buffer[49];
    *ptr = 0;
    do
    {
        *--ptr = rep[num % base];
        num /= base;
    } while (num);

    return (ptr);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * This function calculates the number of descendant nodes (both children and grandchildren)
 * in a binary tree rooted at the given node. It recursively traverses the tree and counts
 * each node encountered.
 * @tree: Pointer to the root node of the binary tree.
 * Return: The number of descendant nodes in the binary tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    /* If the tree is empty, return 0 */
    if (!tree)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * insert - Inserts a node into the correct location in a Max Heap.
 * This function is a helper function that inserts a node into the correct
 * location in a Max Heap. It takes a double pointer to the root of the heap
 * and a pointer to the node to be inserted as arguments.
 * @root: Double pointer to the root of the Max Heap.
 * @node: Pointer to the node to be inserted.
 */
void insert(heap_t **root, heap_t *node)
{
    /* Create a binary string representation of the heap size */
    heap_t *tmp;
    int size;
    unsigned int i;
    char *binary;
    char c;

    /* Find the parent of the new node */
    tmp = *root;
    size = binary_tree_size(tmp) + 1;
    binary = convert(size, 2, 1);
    for (i = 1; i < strlen(binary); i++)
    {
        c = binary[i];
        if (i == strlen(binary) - 1)
        {
            if (c == '1')
            {
                node->parent = tmp;
                tmp->right = node;
                break;
            }
            else if (c == '0')
            {
                node->parent = tmp;
                tmp->left = node;
                break;
            }
        }
        if (c == '1')
            tmp = tmp->right;
        else if (c == '0')
            tmp = tmp->left;
    }
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * This function inserts a value into a Max Binary Heap rooted at the given
 * root node. It takes a double pointer to the root of the tree and the value
 * to be inserted as arguments. If successful, it returns a pointer to the
 * newly created node; otherwise, it returns NULL.
 * @root: Double pointer to the root of the Max Binary Heap.
 * @value: The value to be inserted into the heap.
 * Return: Pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *ht = NULL, *ret;

    /* If the root is NULL, create a new node and set it as the root */
    if (!root)
        return (NULL);
    ht = calloc(1, sizeof(heap_t));
    ht->n = value;
    if (!*root)
    {
        *root = ht;
        return (ht);
    }
    insert(root, ht);
    while (ht->parent && ht->n > ht->parent->n)
    {
        ret = swap(ht->parent, ht);
        if (ret)
            *root = ret;
    }
    return (ht);
}
