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
  int Year;
} BOOK;

typedef struct Node {
  BOOK Item;
  struct Node * Next;
} NODE;

int AppendNode(NODE ** head, BOOK value);
int FreeList(NODE * head);
int DisplayList(NODE * head);

int GettingFileInfo(NODE ** node, BOOK * book);

int main(void) {
  
  NODE * head = NULL;
  BOOK * book;
  // MENU
  printf("***MENU***""
		  ");
  GettingFileInfo(&head, book); 
  DisplayList(head); 
  
  return 0;
}

int AppendNode(NODE ** head, BOOK  value) {

  NODE * temp = (NODE*) malloc(sizeof(NODE));
  if (!temp) {
    printf("Memory allocation failed!\n");
    return -1;
  }
  
  temp->Next = NULL;
  temp->Item = value;

  if (*head == NULL) {
    *head = temp;
  }
  else {
	  NODE * current = *head;
    while (current->Next != NULL) {
      current = current->Next;
    }
    current->Next = temp;
  }
  printf("List loaded successfully\n");

  return 0;
}

int FreeList(NODE * head) {
  NODE * temp;
  while (head != NULL) {
    temp = head;
    head = head->Next;
    free(temp);
  } 
  return 0;
}

int GettingFileInfo(NODE ** node, BOOK * book) {

  char title[STRSIZE];
  char author[STRSIZE];
  char yearStr[10];
  int year;
  FILE * fp = fopen(FILENAME, "r");
  
  if (!fp) {
    printf("Error Opening File %s\n", FILENAME);
    fclose(fp);
    return -2;
  }
  
  while(fgets(title, STRSIZE, fp)) {
    fgets(author, STRSIZE, fp);
    fgets(yearStr, 10,fp);

    title[strcspn(title,"\n")] = '\0';
    author[strcspn(author, "\n")] = '\0';
    yearStr[strcspn(yearStr, "\n")] = '\0';

    year = atoi(yearStr);

    BOOK * tempBook = (BOOK*) malloc(sizeof(BOOK));

    if(!tempBook) {
      printf("Memory allocation failed! error: -3\n");
      fclose(fp);
      return -3;
    }

    strcpy(tempBook->Title, title);
    strcpy(tempBook->Author, author);

    tempBook->Year = year;
    AppendNode(node,* tempBook);
  } 
  
  return 0;

}

int DisplayList(NODE * head) {
  NODE * tempNode = head; 
  printf("Opening DisplayListLOOP\n");
  while (tempNode != NULL) {
    printf("Title: %s\n", tempNode->Item.Title);
    printf("Author: %s\n", tempNode->Item.Author);
    printf("Year: %d\n", tempNode->Item.Year);
    tempNode = tempNode->Next; 
    putchar('\n');
  }
  return 0;
}
