#include "binary_trees.h"

/* Macro definitions */
#define INIT_NODE {0, NULL, NULL, NULL}

#define BINARY_SIZE 50
#define BINARY_BASE 2
#define BINARY_INDEX_OFFSET (BINARY_SIZE - 1)

#define SETUP_NODE_BLOCK { \
    node_tmp = *root; \
    node_count = binary_tree_size(*root); \
    binary_str = &binary_buffer[BINARY_INDEX_OFFSET]; \
    *binary_str = '\0'; \
}

#define FREE_NODE_BLOCK { \
    result = node_tmp->n; \
    free(node_tmp); \
    *root = NULL; \
}

#define SWAP_HEAD_BLOCK { \
    head_node = *root; \
    head_node = swap_head(head_node, node_tmp); \
    result = head_node->n; \
    free(head_node); \
    *root = node_tmp; \
    node_tmp = percolate_down(node_tmp); \
    *root = node_tmp; \
}

#define CONVERT_LOOP { \
    *--binary_str = CONVERT[node_count % BINARY_BASE]; \
    node_count /= BINARY_BASE; \
}

/**
 * swap - swaps two nodes in a binary tree
 * @a: first node
 * @b: second node
 * Return: pointer to the new root
 */
bst_t *swap(bst_t *a, bst_t *b)
{
    bst_t a_copy = INIT_NODE;

    a_copy.n = a->n;
    a_copy.parent = a->parent;
    a_copy.left = a->left;
    a_copy.right = a->right;
    a->parent = b;
    a->left = b->left;
    a->right = b->right;
    if (b->left)
        b->left->parent = a;
    if (b->right)
        b->right->parent = a;

    b->parent = a_copy.parent;
    if (a_copy.parent)
    {
        if (a == a_copy.parent->left)
            a_copy.parent->left = b;
        else
            a_copy.parent->right = b;
    }
    if (b == a_copy.left)
    {
        b->left = a;
        b->right = a_copy.right;
        if (a_copy.right)
            a_copy.right->parent = b;
    }
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
 * binary_tree_size - measures the size of a binary tree
 * @tree: input binary tree
 * Return: number of descendant child nodes
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * swap_head - helper function to swap head and node
 * @head: pointer to head node
 * @node: pointer to node
 * Return: pointer to severed head of tree
 */
heap_t *swap_head(heap_t *head, heap_t *node)
{
    if (node->parent->left == node)
    {
        node->parent->left = NULL;
    } else
        node->parent->right = NULL;
    node->parent = NULL;
    node->left = head->left;
    node->right = head->right;
    if (head->left)
        head->left->parent = node;
    if (head->right)
        head->right->parent = node;
    return (head);
}

/**
 * percolate_down - percolate head into correct position
 * @node: pointer to head node
 * Return: pointer to head of tree
 */
heap_t *percolate_down(heap_t *node)
{
    int max_value;
    heap_t *next_node = node;

    if (!node)
        return (NULL);
    max_value = node->n;
    if (node->left)
        max_value = MAX(node->left->n, max_value);
    if (node->right)
        max_value = MAX(node->right->n, max_value);
    if (node->left && max_value == node->left->n)
        next_node = node->left;
    else if (node->right && max_value == node->right->n)
        next_node = node->right;
    if (next_node != node)
    {
        swap(node, next_node);
        percolate_down(node);
    }
    return (next_node);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to root of tree
 * Return: value stored in the root node
 */
int heap_extract(heap_t **root)
{
    size_t node_count, i;
    char *binary_str, c, binary_buffer[BINARY_SIZE];
    int result;
    heap_t *node_tmp, *head_node;

    if (!root || !*root)
        return (0);
    SETUP_NODE_BLOCK;
    if (node_count == 1)
    {
        FREE_NODE_BLOCK;
        return (result);
    }
    do {
        CONVERT_LOOP;
    } while (node_count);

    for (i = 1; i < strlen(binary_str); i++)
    {
        c = binary_str[i];
        if (i == strlen(binary_str) - 1)
        {
            if (c == '1')
            {
                node_tmp = node_tmp->right;
                break;
            }
            else if (c == '0')
            {
                node_tmp = node_tmp->left;
                break;
            }
        }
        if (c == '1')
            node_tmp = node_tmp->right;
        else if (c == '0')
            node_tmp = node_tmp->left;
    }
    SWAP_HEAD_BLOCK;
    return (result);
}
