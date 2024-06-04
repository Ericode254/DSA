#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

// function declarations
struct Node *createNode(int value);
struct Node *insert(struct Node *root, int value);
int search(struct Node *root, int value);
void delete(struct Node *root, int value);
void printTree(struct Node *root);

int main()
{
  struct Node *root = NULL;
  root = insert(root, 8);
  insert(root, 4);
  insert(root, 6);
  insert(root, 5);
  insert(root, 9);

  printTree(root); 

  return 0;
}

// a function for creating a new node
struct Node *createNode(int value) {
  struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

// a function for inserting a node in the tree
struct Node *insert(struct Node *root, int value) {
  if (root == NULL) {
    return createNode(value);
  } else {
    if (value <= root->data) {
      root->left = insert(root->left, value);
    } else {
      root->right = insert(root->right, value);
    }
  }

  return root;
}

// a function for searching for an item in the tree
int search(struct Node *root, int value) {
  if (root == NULL) {
    return 0;
  } else if (value == root->data) {
    return 1;
  } else if (value <= root->data) {
    return search(root->left, value);
  } else {
    return search(root->right, value);
  }
}

// a function for printing out the contents of the tree
void printTree(struct Node *root) {
  if (root == NULL) {
    return;
  }
  
  printTree(root->left);
  printf("%d ", root->data);
  printTree(root->right);

}


