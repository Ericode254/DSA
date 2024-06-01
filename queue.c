#include <stdio.h>
#include <stdlib.h>

// NOTE: The size of the queue can also be dynamically allocated during runtime
#define MAX 100

char Queue[MAX];
int spos = 0;
int rpos = 0;
 
// function declarations
void qstore(char value);
char qretrieve();
void printQueue();

int main()
{
  qstore('A');
  qstore('B');
  qstore('C');
  qretrieve();
  
  printQueue();

  return 0;
}

// a function for adding an item into the queue
void qstore(char value) {
  if (spos == MAX) {
    printf("The queue is full\n");
    return;
  }

  Queue[spos] = value;
  spos++;
}

// a function for removing an item from the queue
char qretrieve() {
  if (rpos == spos) {
    printf("The queue is empty");
  }

  rpos++;
  return Queue[rpos-1];
}

// a function for printing what is in the queue
void printQueue() {
  for (int i = rpos; i < spos; i++) {
    printf("%c ", Queue[i]);
  }
}
