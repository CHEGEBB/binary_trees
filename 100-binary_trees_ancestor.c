#include "binary_trees.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
    binary_tree_t *mom, *pop; /* Pointers to store parents of the nodes */

    /* If either node is NULL, return NULL */
    if (!first || !second)
    {
        return (NULL);
    }
    /* If both nodes are the same, return either node */
    if (first == second)
    {
        return ((binary_tree_t *)first);
    }

    /* Get parents of the nodes */
    mom = first->parent, pop = second->parent;

    /* Recursively find the lowest common ancestor */
    if (first == pop || !mom || (!mom->parent && pop))
    {
        return (binary_trees_ancestor(first, pop));
    }
    else if (mom == second || !pop || (!pop->parent && mom))
    {
        return (binary_trees_ancestor(mom, second));
    }
    return (binary_trees_ancestor(mom, pop));
}
