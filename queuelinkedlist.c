#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// function declarations
struct Node *createNode(int value);
void Enqueue(int value);
void Dequeue();
int Top();
void printQueue();

int main()
{
  Enqueue(1);
  Enqueue(2);
  Enqueue(3);
  Dequeue();

  printQueue();

  return 0;
}

// a function for creating a new node
struct Node *createNode(int value) {
  struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;

  return newNode;
}

// a function for puting an item into the queue
void Enqueue(int value) {
  if (front == NULL && rear == NULL) {
    front = createNode(value);
    rear = front;
    return;
  } else if (front == rear) {
    rear = createNode(value);
    front->next = rear;
    return;
  } else {
    struct Node *temp = createNode(value);
    rear->next = temp;
    rear = temp;
    return;
  }
}

// a function for removing an item from the queue
void Dequeue() {
  if (front == NULL && rear == NULL) {
    printf("The queue is empty\n");
    return;
  } else if (front == rear) {
    front = NULL;
    rear = NULL;
    return;
  } else {
    struct Node *temp = front;
    front = front->next;
    free(temp);
    return;
  }
}

// a function for returning the item at the front of the queue
int Top() {
  if (front == NULL && rear == NULL) {
    printf("The queue is empty\n");
  } else {
    return front->data;
  }
}

// a function for printing what is in the queue
void printQueue() {
  struct Node *temp = front;
  while (temp != NULL) {
    printf("%d->", temp->data);
    temp = temp->next;
  }
}
