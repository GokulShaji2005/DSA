#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for each webpage
struct Node {
    char url[100];
    struct Node* prev;
    struct Node* next;
};

struct Node* current = NULL; // Points to the current webpage

// Create a new node
struct Node* createNode(char url[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Visit a new page
void visit(char url[]) {
    struct Node* newNode = createNode(url);

    if (current != NULL) {
        current->next = newNode;
        newNode->prev = current;
    }

    current = newNode; // Move to the new page
    printf("Visited: %s\n", url);
}

// Go back to previous page
void back() {
    if (current == NULL || current->prev == NULL) {
        printf("No previous page.\n");
    } else {
        current = current->prev;
        printf("Moved back to: %s\n", current->url);
    }
}

// Go forward to next page
void forward() {
    if (current == NULL || current->next == NULL) {
        printf("No forward page.\n");
    } else {
        current = current->next;
        printf("Moved forward to: %s\n", current->url);
    }
}

// Show current page
void show() {
    if (current == NULL)
        printf("No pages visited.\n");
    else
        printf("Current page: %s\n", current->url);
}

int main() {
    int choice;
    char url[100];

    while (1) {
        printf("\n--- Browser Menu ---\n");
        printf("1. Visit new page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Show current page\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // Clear input buffer

        if (choice == 1) {
            printf("Enter URL: ");
            fgets(url, 100, stdin);
            url[strcspn(url, "\n")] = '\0';
            visit(url);
        }
        else if (choice == 2) {
            back();
        }
        else if (choice == 3) {
            forward();
        }
        else if (choice == 4) {
            show();
        }
        else if (choice == 5) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
