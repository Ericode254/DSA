#include <stdio.h>

#define MAX 100

int Stack[MAX];
int top = -1;

// function declarations
int isEmpty();
void push(int value);
void pop();
int Top();
void printSack();

int main()
{
  push(1);
  push(2);
  push(3);
  push(4);
  pop();
  push(5);
  printSack();

  return 0;
}

// a function for checking whether the satck is empty
int isEmpty() {
  if (top == -1) {
    return 1;
  } else {
    return 0;
  }
}

// a function for pushing an item on to the stack
void push(int value) {
  if (top != MAX) {
    top += 1;
    Stack[top] = value;
  } else {
    printf("The stack is full");
  }
}

// a function for removing an item from the stack
void pop() {
  if (isEmpty()) {
    printf("The stack is empty");
  } else {
    top -= 1;
  }
}

// a function for checking the item on top of the stack
int Top() {
  if (isEmpty()) {
    printf("The stack is empty");
    return top;
  } else {
    return Stack[top];
  }
}

// a function for printing what is in the stack
void printSack() {
  for (int i = 0; i <= top; i++) {
    printf("%d ", Stack[i]);
  }
}
