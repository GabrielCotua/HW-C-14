// Gabriel Cotua HW14

#include <stdio.h>
#include <stdlib.h>

typedef struct Book {
    char title[50];
    char author[50];
    int year;
} Book;

typedef struct Node {
    Book book;
    struct Node *next;
    struct Node *prev;
} Node;
// Linked Array functions
void InsertNode_End(Node ** root, Book * book);
void DeleteNode(Node ** target);
void Display(Node ** root);
void createLinkedList(Node ** root);

// Book Functions
char * getBookTitle(Book);
void setBoookTitle(Book, char[50]);
char * getBookAuthor(Book);
void setBookAuthor(Book, char[50]);
int getBookYear(Book);
void setBookYear(Book, int);

int main(void) {
    Node* root = NULL;

    FILE * pfile;
    char currChar;
    if ((pfile = fopen("HW14Data.txt", "r")) != NULL) {
        printf("File opened\n");
    } else {
        printf("File Failed to open.\n");
    }
    return 0;
}

void insertNode_end(Node ** root, Book * book) {
    Node * newNode = (Node * ) malloc(sizeof(Node)); // Creating a new node that we are going to use
    if (newNode == NULL) {
        printf("Memory Allocation for Node Failed.\n");
        exit(1);
    }

    // assigning values to it
    newNode->next = NULL;
    newNode->book = *book;

    // checking for "root" node to point to NULL
    // if it does, make it point to the "newNode"
    if (*root == NULL) {
        *root = newNode;
        return; // work done
    }

    Node * curr = *root;
    // Looking for the last item to place newNode
    // in case "root" != NULL
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode; // after found, will give the value to the last value in the list
    free(newNode);
}
void createLinkedList(Node root) {}




