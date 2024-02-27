# About Binary trees Alx project 
This project is aimed at equipping alx students with the requisite skills  and knowledge of how to tackle binary trees

# Author:
This project is a collaborative effort of :
```c
-Brian Chege
-Sheilah Wanyama
```

# Binary Trees

This repository contains C programs that implement various operations on binary trees. The basic structure of the binary tree is defined in the `binary_trees.h` header file. The following operations are implemented:

## 0. New Node

The function `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)` creates a new binary tree node with the given parent and value. The node is initialized with no children.

```c
binary_tree_t *root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
root->left->left = binary_tree_node(root->left, 6);
root->left->right = binary_tree_node(root->left, 16);
root->right = binary_tree_node(root, 402);
root->right->left = binary_tree_node(root->right, 256);
root->right->right = binary_tree_node(root->right, 512);

binary_tree_print(root);
```

Output:
```
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (016)     (256)     (512)
```

## 1. Insert Left

The function `binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)` inserts a node as the left child of another node. If the parent already has a left child, the new node takes its place, and the old left child becomes the left child of the new node.

```c
binary_tree_t *root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
root->right = binary_tree_node(root, 402);
binary_tree_print(root);

binary_tree_insert_left(root->right, 128);
binary_tree_insert_left(root, 54);
binary_tree_print(root);
```

Output:
```
  .--(098)--.
(012)     (402)

       .--(098)-------.
  .--(054)       .--(402)
(012)          (128)
```

## 2. Insert Right

The function `binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)` inserts a node as the right child of another node. If the parent already has a right child, the new node takes its place, and the old right child becomes the right child of the new node.

```c
binary_tree_t *root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
root->right = binary_tree_node(root, 402);
binary_tree_print(root);

binary_tree_insert_right(root->left, 54);
binary_tree_insert_right(root, 128);
binary_tree_print(root);
```

Output:
```
  .--(098)--.
(012)     (402)

  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
```

## 3. Delete

The function `void binary_tree_delete(binary_tree_t *tree)` deletes an entire binary tree.

```c
binary_tree_t *root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
root->right = binary_tree_node(root, 402);
binary_tree_insert_right(root->left, 54);
binary_tree_insert_right(root, 128);
binary_tree_print(root);

binary_tree_delete(root);
```

## 4. Is Leaf

The function `int binary_tree_is_leaf(const binary_tree_t *node)` checks if a node is a leaf.

```c
binary_tree_t *root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
root->right = binary_tree_node(root, 402);
binary_tree_insert_right(root->left, 54);
binary_tree_insert_right(root, 128);
binary_tree_print(root);

int result = binary_tree_is_leaf(root);
printf("Is %d a leaf: %d\n", root->n, result);
result = binary_tree_is_leaf(root->right);
printf("Is %d a leaf: %d\n", root->right->n, result);
result = binary_tree_is_leaf(root->right->right);
printf("Is %d a leaf: %d\n", root->right->right->n, result);
```

Output:
```
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Is 98 a leaf: 0
Is 128 a leaf: 0
Is 402 a leaf: 1
```

## 5. Is Root

The function `int binary_tree_is_root(const binary_tree_t *node)` checks if a given node is a root.

```c
binary_tree_t *root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
root->right = binary_tree_node(root, 402);
binary_tree_insert_right(root->left, 54);
binary_tree_insert_right(root, 128);
binary_tree_print(root);

int result = binary_tree_is_root(root);
printf("Is %d a root: %d\n", root->n, result);
result = binary_tree_is_root(root->right);
printf("Is %d a root: %d\n", root->right->n, result);
result = binary_tree_is_root(root->right->right);
printf("Is %d a root: %d\n", root->right->right->n, result);
```

Output:
```
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Is 98 a root: 1
Is 128 a root: 0
Is 402 a root: 0
```

## 6. Pre-order Traversal

The function `void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))` performs pre-order traversal on a binary tree.

```c
binary_tree_t *root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
root->right = binary_tree_node(root, 402);
root->left->left = binary_tree_node(root->left, 6);
root->left->right = binary_tree_node(root->left, 56);
root->right->left = binary_tree_node(root->right, 256);
root->right->right = binary_tree_node(root->right, 512);

binary_tree_print(root);
binary_tree_preorder(root, &print_num);
```

Output:
```
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (056)     (256)     (512)
98
12
6
56
402
256
512
```

## 7. In-order Traversal

The function `void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))` performs in-order traversal on a binary tree.

```c
binary_tree_t *root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
root->right = binary_tree_node(root, 402);
root->left->left = binary_tree_node(root->left, 6);
root->left->right = binary_tree_node(root->
