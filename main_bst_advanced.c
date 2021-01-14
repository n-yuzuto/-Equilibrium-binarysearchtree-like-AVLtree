#include <stdio.h>
#include <stdlib.h>
#include "bst_advanced.h"

int main(void) {
  // Build an advanced binary search tree
  Node *root = NULL;
  root = insert_bst(root, 10);
  root = insert_bst(root, 15);
  root = insert_bst(root, 18);
  root = insert_bst(root, 6);
  root = insert_bst(root, 12);
  root = insert_bst(root,  20);
  root = insert_bst(root,  19);
  root = insert_bst(root,  9);

  void preorder(Node *n){
    if(n == NULL)return;
    printf("%d ",n -> height);
    preorder(n -> left);
    preorder(n -> right);
  }
  preorder(root); 
  printf("\n");
  root = delete_bst(root, 15);
  printf("Value 15 deleted\n");
  preorder(root);
  printf("\n");
  root = delete_bst(root, 19);
  printf("Value 19 deleted\n");
  preorder(root); 
  printf("\n");

  delete_tree(root);

  return EXIT_SUCCESS;
}