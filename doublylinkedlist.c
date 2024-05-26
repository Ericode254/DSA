#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node *prev;
  int data;
  struct Node *next;
};

struct Node *head = NULL;

// function declarations
struct Node *createNode(int value);
void insertFirst(int value);
void insertLast(int value);
void insertAtPosition(int value, int position);
void deleteFirst();
void deleteLast();
void deleteAtPosition(int position);
void reverseList();
void printList();

int main(int argc, char *argv[])
{
  insertFirst(1);
  insertFirst(2);
  insertFirst(3);
  insertLast(5);
  insertLast(6);
  insertAtPosition(7, 3);
  deleteFirst();
  deleteLast();
  deleteAtPosition(3);
  reverseList();
  printList();

  return 0;
}

// a function for creatin a node
struct Node *createNode(int value) {
  struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->prev = NULL;
  newNode->data = value;
  newNode->next = NULL;

  return newNode;
}

// a function for inserting a node at the first position of the list
void insertFirst(int value) {
  struct Node *newNode = createNode(value);

  if (head == NULL) {
    head = newNode;
    return;
  }

  newNode->next = head;
  head->prev = newNode;
  head = newNode;
}

// a function for inserting a node at the end of the list
void insertLast(int value) {
  struct Node *newNode = createNode(value);

  if (head == NULL) {
    head = newNode;
    return;
  }

  struct Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = newNode;
  newNode->prev = temp;
}

// a function for inserting a node at any given position in the list
void insertAtPosition(int value, int position) {
  struct Node *newNode = createNode(value);

  if (position == 1) {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return;
  }

  struct Node *temp = head;
  for (int i = 0; i < position-2; i++) {
    temp = temp->next;
  }
  
  newNode->next = temp->next;
  temp->next = newNode;
  newNode->prev = temp;
}

// a function for deleting the first node in the list
void deleteFirst() {
  if (head == NULL) {
    printf("The list is empty");
    return;
  }

  struct Node *temp = head;
  head = head->next;
  free(temp);
}

// a function for deleting the last node in the list
void deleteLast() {
  if (head == NULL) {
    printf("The list is empty");
    return;
  }

  struct Node *temp = head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }

  struct Node *temp2 = temp->next;
  temp->next = NULL;
  free(temp2);
}

// a function for deleting a node at any position in the list
void deleteAtPosition(int position) {
  if (head == NULL) {
    printf("The list is empty");
    return;
  }

  if (position == 1) {
    free(head);
    return;
  }

  struct Node *temp = head;
  for (int i = 0; i < position-2; i++) {
    temp = temp->next;
  }

  struct Node *temp2 = temp->next;
  temp->next = temp2->next;
  free(temp2);
}

// a function for reversing the list 
void reverseList() {
  struct Node *current, *next, *prev;
  current = head;
  prev = NULL;

  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  head = prev;
}
// a function for printing the whole list to the console
void printList() {
  struct Node *temp = head;

  while (temp != NULL) {
    printf("%d->", temp->data);
    temp = temp->next;
  }

  printf("\n");
}
