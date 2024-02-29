#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - goes through a binary tree using level-order traversal
 * it uses a queue to store the nodes
 * A queue is a data structure that uses a FIFO (First In First Out) order
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * It uses a queue to store the nodes
 * Return: void
 */