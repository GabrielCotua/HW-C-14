// Gabriel Cotua HW #14

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZE 100
#define FILENAME "HW14Data.txt"
#define BINARY_FILENAME "Books.bin"
#define FLUSH while(getchar() != '\n')

typedef struct Book {
  char Title[STRSIZE];
  char Author[STRSIZE];
  int year;
} BOOK;

typedef struct Node {
  BOOK Item;
  struct Node * Next;
} NODE;

int AppendNode(NODE * head, BOOK value);
int FreeList(NODE * head);

int GettingFileInfo(NODE * node, BOOK * book);

int main(void) {
  
  NODE * head = NULL;
  BOOK book = {"HA","HA",2};
  AppendNode(head, book); 
  
  return 0;
}

int AppendNode(NODE * head, BOOK value) {

  NODE * temp = (NODE*) malloc(sizeof(NODE));
  if (!temp) {
    printf("Memory allocation failed!\n");
    return -1;
  }
  
  temp->Next = NULL;
  temp->Item = value;

  if (head == NULL) {
    head = temp;
  }
  else {
    while (temp->Next != NULL) {
      temp = temp->Next;
    }
  }
  printf("List loaded successfully");

  free(temp);
  return 0;
}

int FreeList(NODE * head) {
  
  return 0;
}

int GettingFileInfo(NODE * node, BOOK * book);
