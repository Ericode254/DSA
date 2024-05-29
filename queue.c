#include <stdio.h>
#include <stdlib.h>

#define MAX 100

char Queue[MAX];
int spos = 0;
int rpos = 0;

void qstore(char value);
char qretrieve();
void printQueue();

int main(int argc, char *argv[])
{
  qstore('A');
  qstore('B');
  qstore('C');
  qretrieve();
  
  printQueue();

  return 0;
}

void qstore(char value) {
  if (spos == MAX) {
    printf("The queue is full\n");
    return;
  }

  Queue[spos] = value;
  spos++;
}

char qretrieve() {
  if (rpos == spos) {
    printf("The queue is empty");
  }

  rpos++;
  return Queue[rpos-1];
}

void printQueue() {
  for (int i = rpos; i < spos; i++) {
    printf("%c ", Queue[i]);
  }
}
