#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *top = NULL;

// function declarations
void push(int value);
void pop();
int isEmpty();
int Top();
void printStack();

int main()
{
  push(1);
  push(2);
  push(3);
  push(4);
  pop();
  printStack();

  return 0;
}

// a function for checking if the stack is empty
int isEmpty() {
  if (top == NULL) {
    return 1;
  } else {
    return 0;
  }
}

// a function for pushing an item onto the stack
void push(int value) {
  struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = value;
  temp->next = top;
  top = temp;
}

// a function for removing an item from the stack
void pop() {
  struct Node *temp;
  if (isEmpty()) 
    printf("The stack is empty");
  temp = top;
  top = top->next;
  free(temp);

}

// a function for checking the item on top of the stack
int Top() {
  if (isEmpty()) {
    printf("The stack is empty");
    return -1;
  } else {
    return top->data;
  }
}

// a function for printing the contents in the stack
void printStack() {
  struct Node *temp = top;
  while (temp != NULL) {
    printf("%d->", temp->data);
    temp = temp->next;
  }
}
