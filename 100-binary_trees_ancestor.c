#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes in a binary tree.
 * The lowest common ancestor is the node that is the parent of both nodes.
 * If either node is the root, the function returns the root.
 * If either node is NULL, the function returns NULL.
 * 
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor node, or NULL if no ancestor exists.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)

{
    binary_tree_t *ancestor = NULL;

    /* If either node is NULL, the function returns NULL. */
    if (first == NULL || second == NULL)
        return (NULL);

    /* If either node is the root, the function returns the root. */
    if (first == second)
        return ((binary_tree_t *)first);

    /* If either node is the root, the function returns the root. */
    if (first->parent == second)
        return ((binary_tree_t *)second);

    /* If either node is the root, the function returns the root. */
    if (second->parent == first)
        return ((binary_tree_t *)first);

    /* If either node is the root, the function returns the root. */
    if (first->parent == second->parent)
        return ((binary_tree_t *)first->parent);

    if (first->parent == second)
        return ((binary_tree_t *)second);

    if (second->parent == first)
        return ((binary_tree_t *)first);

    if (first->parent != NULL)
        ancestor = binary_trees_ancestor(first->parent, second);

    if (ancestor != NULL)
        return (ancestor);

    if (second->parent != NULL)
        ancestor = binary_trees_ancestor(first, second->parent);

    return (ancestor);
}
