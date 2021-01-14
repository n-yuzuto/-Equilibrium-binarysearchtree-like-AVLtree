#ifndef INCLUDE_GUARD_BST_ADVANCED_H
#define INCLUDE_GUARD_BST_ADVANCED_H

#include <stdbool.h>

typedef struct node {
  int value;
  int height;
  struct node *left;
  struct node *right;
} Node;

// advanced bst-specific functions
Node *insert_bst(Node *root, int d);
Node *delete_bst( Node *root,int x); 
Node *delete_min_bst(Node *root);
// Reuse the following functions implemented for the binarytree and binarysearchtree
int min_bst(Node *root);
bool search_bst(Node *root, int d);
void inorder(Node *root);
void display(Node *root);
void delete_tree(Node *root);
int search_min(Node *node);


#endif  // INCLUDE_GUARD_BST_ADVANCED_H