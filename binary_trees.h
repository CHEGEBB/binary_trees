#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

/* Function Prototypes */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
/* Creates a new binary tree node */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
/* Inserts a new left child node in the binary tree */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
/* Inserts a new right child node in the binary tree */
void binary_tree_delete(binary_tree_t *tree);
/* Deletes an entire binary tree */
int binary_tree_is_leaf(const binary_tree_t *node);
/* Checks if a node is a leaf */
int binary_tree_is_root(const binary_tree_t *node);
/* Checks if a node is a root */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
/* Traverse the binary tree using pre-order traversal */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
/* Traverse the binary tree using in-order traversal */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
/* Traverse the binary tree using post-order traversal */
size_t binary_tree_height(const binary_tree_t *tree);
/* Measures the height of a binary tree */
void binary_tree_print(const binary_tree_t *);
/* Prints a binary tree */

#endif /* _BINARY_TREES_H_ */
