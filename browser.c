#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    char url[256];
    struct Node* prev;
    struct Node* next;
};


struct Node* current = NULL;


struct Node* createNode(const char* url) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strncpy(newNode->url, url, sizeof(newNode->url) - 1);
    newNode->url[sizeof(newNode->url) - 1] = '\0';
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void visitNewPage(const char* url) {
    struct Node* newNode = createNode(url);
    if (current != NULL) {

        struct Node* temp = current->next;
        while (temp != NULL) {
            struct Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
        current->next = newNode;
        newNode->prev = current;
    }
    current = newNode;
    printf("Visited: %s\n", url);
}

void goBack() {
    if (current == NULL || current->prev == NULL) {
        printf("Cannot go back.\n");
    } else {
        current = current->prev;
        printf("Moved back to: %s\n", current->url);
    }
}


void goForward() {
    if (current == NULL || current->next == NULL) {
        printf("Cannot go forward.\n");
    } else {
        current = current->next;
        printf("Moved forward to: %s\n", current->url);
    }
}


void displayCurrentPage() {
    if (current == NULL) {
        printf("No page visited yet.\n");
    } else {
        printf("Current Page: %s\n", current->url);
    }
}

int main() {
    int choice;
    char url[256];

    while (1) {
        printf("\nBrowser Navigation Menu:\n");
        printf("1. Visit New Page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Display Current Page\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        while (getchar() != '\n'); 

        switch (choice) {
            case 1:
                printf("Enter URL to visit: ");
                fgets(url, sizeof(url), stdin);
                url[strcspn(url, "\n")] = 0; 
                visitNewPage(url);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                displayCurrentPage();
                break;
            case 5:
                printf("Exiting Browser Simulation.\n");
                return 0; 
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
