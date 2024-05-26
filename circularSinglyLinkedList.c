#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head = NULL;

// function declarations
struct Node *createNode(int value);
void insertNodeFirst(int value);
void insertingAtPosition(int value, int position);
void deleteFirst();
void deleteAtPosition(int position);
void reverse();
void printList();

int main(int argc, char *argv[])
{
  insertNodeFirst(1);
  insertNodeFirst(2);
  insertNodeFirst(3);
  insertingAtPosition(4, 4);
  deleteFirst();
  deleteAtPosition(2);
  reverse();

  printList();

  return 0;
}

// a function for creating new nodes
struct Node *createNode(int value) {
  struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;

  return newNode;
}

// a function for inserting a node at the beginning of the list
void insertNodeFirst(int value) {
  struct Node *newNode = createNode(value);

  if (head == NULL) {
    head = newNode;
    head->next = head;
    return;
  }
  
  struct Node *temp = head;
  while (temp->next != head) {
    temp = temp->next;
  }

  temp->next = newNode;
  newNode->next = head;
  head = newNode;
}

// a function for inserting a node at a particular position
void insertingAtPosition(int value, int position) {
  struct Node *newNode = createNode(value);

  if (position == 1) {
    newNode->next = head;
    head->next = newNode;
    head = newNode;
    return;
  }

  struct Node *temp = head;
  for (int i = 0; i < position-2; i++) {
    temp = temp->next;
  }

  newNode->next = temp->next;
  temp->next = newNode;
}

// a function for deleting a node at the first position
void deleteFirst() {
  if (head == NULL) {
    printf("The list is empty");
    return;
  }

  struct Node *temp = head;
  while (temp->next != head) {
    temp = temp->next;
  }

  struct Node *temp2 = temp->next;
  temp->next = temp2->next;
  head = temp->next;
  free(temp2);
}

// a function for deleting a node at a specific position in a list
void deleteAtPosition(int position) {
  if (position == 1 && head->next == head) {
    head = NULL;
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

// a function for reversing the linked list
void reverse() {
  struct Node *current, *prev, *next;
  current = head->next;
  prev = head;

  while (current != head) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  head = prev;
}

// a function for printing the entire linked list to the console
void printList() {
  struct Node *temp = head;

  while (temp->next != head) {
    printf("%d->", temp->data);
    temp = temp->next;
  }

  printf("%d", temp->data);

  printf("\n");
}
