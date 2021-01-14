#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst_advanced.h"

int min_bst(Node *root) {
    if(root==NULL) return -1;
    Node *p = root;
    while(p -> left != NULL) p = p -> left;
    return p -> value;
}
Node *createnode(int d, int h, Node *left, Node *right){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL){
        printf("fail to secure area");
        return NULL;
    }
    else if(new_node != NULL){
        new_node -> value = d;
        new_node -> left = left;
        new_node -> right = right;
        new_node -> height = reset_height(new_node);
    }
    return new_node;
}
bool search_bst(Node *root, int d){
    struct node *p;
    p = root;
    bool t = true;
    bool f = false;
    while(p != NULL){
        if(d < p -> value){
            p = p -> left;
        }
        else if(d > p -> value){
            p = p -> right;
        }
        else{
            return t;
        }
    }
    return f;
}
int get_height(Node *root) {
  if (root == NULL) return 0;
  else              return root->height;
}

int reset_height(Node *root) {
  int lh = get_height(root->left);
  int rh = get_height(root->right);
  return 1 + (lh > rh ? lh : rh);
} 

Node *insert_bst(Node *root, int d){
  Node *copy;
  if (root == NULL){
    root = createnode(d, 1, NULL, NULL);
      root->height = reset_height(root);

    return root;
  }
  if (root->value == d){
      root->height = reset_height(root);
  
    return root;
  }
  else if (root->value > d){
    if (root->left == NULL){
      root->left = createnode(d, 1, NULL, NULL);
    }
    else{
      copy = insert_bst(root->left, d);
    }
  }
  else if (root->value < d){
    if (root->right == NULL){
      root->right = createnode(d, 1, NULL, NULL);
    }
    else{
      copy = insert_bst(root->right, d);
    }
  }
  root->height = reset_height(root);
  return root;
}

int search_min(Node *node)
{
  while (node->left != NULL) node = node->left;
  return node->value;
}

Node *delete_min_bst(Node *root) { 
    if (root->left == NULL) {
    Node *copy = root->right;
    free(root);
    return copy;
  }
  root->left = delete_min_bst(root->left);
  return root;
}

Node *delete_bst( Node *root,int x) { 
    if (root == NULL) return NULL;
  if (x == root->value) {
    if (root->left == NULL) {
      Node *copy = root->right;
      free(root);
      return copy;
    }
    if (root->right == NULL) {
      Node *copy = root->left;
      free(root);
      return copy;
    }
    root->value = min_bst(root->right);
    root->right = delete_min_bst(root->right);
  } else if (x < root->value)
    root->left = delete_bst(root->left,x);
  else
    root->right = delete_bst( root->right,x);
  return root;
}

void inorder(Node *n){
    if(n == NULL)return;
    inorder(n -> left);
    printf("%s ",n -> value);
    inorder(n -> right);
}
void display(Node *n) {
    if (n == NULL) {
        printf("null");
    }
    else {
        printf("%s(", n -> value);
        display(n -> left);
        printf(",");
        display(n -> right);
        printf(")");
    }
}
void delete_tree(Node *n){
    if(n != NULL){
        delete_tree(n -> left);
        delete_tree(n -> right);
        free(n);
    }
}