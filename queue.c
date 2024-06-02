#include <stdio.h>

// NOTE: The size of the queue can also be dynamically allocated during runtime
#define MAX 100

char Queue[MAX];
int rear = -1;
int front = -1;
 
// function declarations
void Enqueue(char value);
char Dequeue();
void printQueue();
int isEmpty();
int Front();

int main()
{
  Enqueue('A');
  Enqueue('B');
  Enqueue('C');
  Dequeue();
  
  printQueue();
  // printf("%c\n", Front());

  return 0;
}

// a function for checking whether the queue is empty
int isEmpty() {
  if (front == -1 && rear == -1) {
    return 1;
  } else {
    return 0;
  }
}

// a function for adding an item into the queue
void Enqueue(char value) {
  if ((rear+1) % MAX == front) {
    printf("The queue is full\n");
    return;
  } else if (isEmpty()) {
    front = 0;
    rear = 0;
  } else {
    rear = (rear + 1) % MAX;
  }

  Queue[rear] = value;
}

// a function for removing an item from the queue
char Dequeue() {
  if (isEmpty()) {
    printf("The queue is empty");
  } else if (front == rear) {
    front = -1;
    rear = -1;
  }

  front = (front + 1) % MAX;
  return Queue[front-1];
}

int Front() {
  return Queue[front];
}
// a function for printing what is in the queue
void printQueue() {
  for (int i = front; i <= rear; i++) {
    printf("%c ", Queue[i]);
  }
}
