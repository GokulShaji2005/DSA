#include <stdio.h>

int f = -1, r = -1;
int arr[20];

void insert_front(int max) {
    int x;
    if (f == 0) {
        printf("Cannot insert at front\n");
    }
    else if (f == -1) {  // empty
        printf("Enter element: ");
        scanf("%d", &x);
        f = r = 0;
        arr[f] = x;
    }
    else {
        printf("Enter element: ");
        scanf("%d", &x);
        f--;
        arr[f] = x;
    }
}

void insert_rear(int max) {
    int x;
    if (r == max - 1) {
        printf("Cannot insert at rear (Overflow)\n");
    }
    else if (r == -1) { // empty
        printf("Enter element: ");
        scanf("%d", &x);
        f = r = 0;
        arr[r] = x;
    }
    else {
        printf("Enter element: ");
        scanf("%d", &x);
        r++;
        arr[r] = x;
    }
}

void delete_front() {
    if (f == -1) {
        printf("Underflow\n");
    }
    else {
        printf("Deleted: %d\n", arr[f]);
        f++;
        if (f > r) f = r = -1; // queue becomes empty
    }
}

void delete_rear() {
    if (r == -1) {
        printf("Underflow\n");
    }
    else {
        printf("Deleted: %d\n", arr[r]);
        r--;
        if (r < f) f = r = -1;
    }
}

void display() {
    if (f == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Deque elements: ");
    for (int i = f; i <= r; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int max, choice;

    printf("Enter max size: ");
    scanf("%d", &max);

    while (1) {
        printf("\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_front(max); display(); break;
            case 2: insert_rear(max); display(); break;
            case 3: delete_front(); display(); break;
            case 4: delete_rear(); display(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
