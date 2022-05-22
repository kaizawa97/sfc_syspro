#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
  struct list *next;
  char *data;
};

int main() {
  struct list *p, *q;

  p = malloc(sizeof(struct list));
  p->data = malloc(sizeof(char) * (strlen("Hello") + 1));
  strcpy(p->data, "Hello");
  q = malloc(sizeof(struct list));
  p->next = q;
  q->next = NULL;
  q->data = malloc(sizeof(char) * (strlen("World") + 1));
  strcpy(q->data, "World");
  exit(0);
}