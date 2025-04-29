// Gabriel Cotua HW14

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_SIZE 100
#define AUTHOR_SIZE 100
#define FILENAME "HW14Data.txt"
#define BINARY_FILENAME "books.bin"
#define FLUSH while(getchar() != '\n');

typedef struct Book {
    char title[TITLE_SIZE];
    char author[AUTHOR_SIZE];
    int year;
    struct Book * next;
} Book;

void AppendNodeFromFile(Book ** root);
void DeleteNode(Book ** target);
void Display(Book ** root);
void InitializeList(Book ** root);

int main(void) { 
	
    Book* root;

    return 0;
}

void InitializeList(Book ** Root){
//    FreeList(Root);
    Root = NULL;
}

void AppendNodeFromFile(Book ** book) {
    
    char title[TITLE_SIZE];
    char author[AUTHOR_SIZE];
    char yearStr[10];

    // Opening file
    FILE * fp = fopen(FILENAME, "r");
    if (!fp) {
        printf("Error opening file %s", FILENAME);
        return;
    }
        
    // Gathering information form file
    while(fgets(title, TITLE_SIZE, fp)) {
        fgets(author, AUTHOR_SIZE, fp);
	fgets(yearStr, 10, fp);

	// Removing newLine Characters
	title[strcspn(title, "\n")] = '\0';
	author[strcspn(author, "\n")] = '\0';
	yearStr[strcspn(yearStr, "\n")] = '\0';

        // Creaing new instance
        Book* newBook = (Book*) malloc(sizeof(Book));
	if (!newBook) {
	    printf("Memory allocation failed");	
	    fclose(fp);
	    return;
	}
        // transfering information to Book
	strcpy(newBook->title, title);
	strcpy(newBook->author, author);

	//https://www.geeksforgeeks.org/convert-string-to-int-in-c/#
	newBook->year = atoi(yearStr); 
	newBook->next = NULL;

	if (head == NULL) {
	    head = newBook;
	} else {
	    Book * temp = head;
	    while ( temp->next != NULL )
                temp = temp->next;
	    temp->next = newBook;
	}
    }

    fclose(fp);
    printf("Books loaded from file: %s", FILENAME);
    return;
}
