// Gabriel Cotua HW14

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_SIZE 100
#define AUTHOR_SIZE 100
#define FILENAME "HW14Data.txt"
#define BINARY_FILENAME "books.bin"
#define FLUSH while(getchar() != '\n')

typedef struct Book {
    char title[TITLE_SIZE];
    char author[AUTHOR_SIZE];
    int year;
    struct Book * next;
} Book;

void AppendNodeFromFile(Book ** head);
void Display(Book ** root);
void InitializeList(Book ** root);
void FreeList(Book ** root);

int main(void) {
	
    Book* root = NULL;
	AppendNodeFromFile(&root);
	for (int i = 1; root != NULL; root = root->next, i++) {
		printf("index: %d\n", i);
		printf("Title: %s\nAuthor: %s\nYear: %d\n\n", root->title, root->author, root->year);
	}

    return 0;
}

void InitializeList(Book ** Root){
    FreeList(Root);
    Root = NULL;
}

void AppendNodeFromFile(Book ** head) {
    
    char title[TITLE_SIZE];
    char author[AUTHOR_SIZE];
    char yearStr[10];
	int year = 0;

    // Opening file
    FILE * fp = fopen(FILENAME, "r");
    if (!fp) {
        printf("Error opening file %s\n", FILENAME);
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

    	//https://www.geeksforgeeks.org/convert-string-to-int-in-c/#
    	year = atoi(yearStr);

    	// Cleaning new instance
    	Book* newBook = (Book*) malloc(sizeof(Book));
    	if (!newBook) {
    		printf("Memory allocation failed!\n");
    		fclose(fp);
    		return;
    	}

    	// transferring information to Book
    	strcpy(newBook->title, title);
    	strcpy(newBook->author, author);

    	newBook->year = year;
    	newBook->next = NULL;

    	if (*head == NULL) {
    		*head = newBook;
    	} else {
    		Book * temp = *head;
    		while ( temp->next != NULL ) {
    			temp = temp->next;
    		}
    		temp->next = newBook;
    	}
    }
    fclose(fp);
    printf("Books loaded from file: %s\n", FILENAME);
}

void FreeList(Book ** root) {
	Book * temp = *root;
	while (temp != NULL) {
		Book * temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
}
