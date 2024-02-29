#include "binary_trees.h"
#include <stdlib.h>

/**
 * A binary tree is perfect if all levels are completely filled.
 * To have a perfect
 */

size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);
unsigned char is_leaf(const binary_tree_t *node);

/**
 * is_leaf - Checks if a node is a leaf of a binary tree.
 * A binary tree is a tree in which each node has exactly zero or two children.
 * @node: A pointer to the node to check.
 * if a node has no children, it is a leaf
 * Return: If the node is a leaf, 1, otherwise, 0.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - Returns the depth of a given node in a binary tree.
 * @tree: A pointer to the node to measure the depth of.
 * Return: The depth of node.
 */
size_t depth(const binary_tree_t *tree)
{
	/* if tree is NULL, return 0 */
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Returns a leaf of a binary tree.
 * A leaf is a node that has no children.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 * Return: A pointer to the first encountered leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
	{
		return (tree);
	}

	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Checks if a binary tree is perfect recursively.
 * A binary tree is perfect if all levels are completely filled.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @level: Level of the current node.
 * Return: If the tree is perfect, 1, otherwise 0.
 */
int is_perfect_recursive(const binary_tree_t *tree,
						 size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
	{
		return (level == leaf_depth ? 1 : 0);
	}
	if (tree->left == NULL || tree->right == NULL)
	{
		return (0);
	}

	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
			is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * A binary tree is perfect if all levels are completely filled.
 * @tree: A pointer to the root node of the tree to check.
 * Return: If tree is NULL or not perfect, 0.
 *if not 0 then, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	/* if tree is NULL, return 0 */
	if (tree == NULL)
	{
		return (0);
	}
	/* if tree is a leaf, return 1 */
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
