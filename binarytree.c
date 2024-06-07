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
struct Node *deleteNode(struct Node *root, int value);
struct Node *findMin(struct Node *root);
int findMax(struct Node *root);
int findHeight(struct Node *root);
void preorderTraversal(struct Node *root);
void inorderTraversal(struct Node *root);
void postorderTraversal(struct Node *root);

int main()
{
  struct Node *root = NULL;
  root = insert(root, 8);
  insert(root, 4);
  insert(root, 6);
  insert(root, 5);
  insert(root, 9);
  
  deleteNode(root, 6);
  preorderTraversal(root);

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

// a function for finding the min of a tree
struct Node  *findMin(struct Node *root) {
  if (root == NULL) {
    printf("The tree is empty\n");
    return NULL;
  }

  while (root->left != NULL) {
    root = root->left;
  }

  return root;
}

// a function for finding the largest item in the tree
int findMax(struct Node *root) {
  if (root == NULL) {
    printf("The tree is empty");
    return -1;
  }

  while (root->right != NULL) {
    root = root->right;
  }

  return root->data;
}

// a function for finding the height of the tree
int max(int a, int b) {
  int largest = 0;

  if (a > b) {
    largest = a;
  } else {
    largest = b;
  }

  return largest;
}

int findHeight(struct Node *root) {
  if (root == NULL) {
    return -1;
  }

  return max(findHeight(root->left), findHeight(root->right)) + 1;
}

// a function for deleting a node in the tree
struct Node *deleteNode(struct Node *root, int value) {
  if (root == NULL) {
    return root;
  } else if (value < root->data) {
    root->left = deleteNode(root->left, value);
  } else if (value > root->data) {
    root->right = deleteNode(root->right, value);
  } else {
    if (root->left == NULL && root->right == NULL) {
      free(root);
      root = NULL;
      return root;
    } else if (root->left == NULL) {
      struct Node *temp = root;
      root = root->right;
      free(temp);
      return root;
    } else if (root->right == NULL) {
      struct Node *temp = root;
      root = root->left;
      free(temp);
      return root;
    } else {
      struct Node *temp = findMin(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
      return root;
    }
  }
  return root;
}

//  functions for printing out the contents of the tree
void preorderTraversal(struct Node *root) {
  if (root == NULL) {
    return;
  }

  printf("%d ", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);

}

void inorderTraversal(struct Node *root) {
  if (root == NULL) {
    return;
  }

  inorderTraversal(root->left);
  printf("%d ", root->data);
  inorderTraversal(root->right);
}

void postorderTraversal(struct Node *root) {
  if (root == NULL) {
    return;
  }

  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ", root->data);
}
