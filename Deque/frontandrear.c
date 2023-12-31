#include <stdio.h>
#define n 10

int deque[n], front = -1, rear = -1;

void insert_rear() {
    int element;
    printf("Enter Element : ");
    scanf("%d", &element);
    if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
        printf("Overflow");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        deque[rear] = element;
    } else if (rear == n - 1) {
        rear = 0;
        deque[rear] = element;
    } else {
        rear = rear + 1;
        deque[rear] = element;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("\nDeque is empty\n");
    }
    printf("\nElements in a deque are:\n");
    int i = front;
    do {
        printf("Element: %d\n", deque[i]);
        i = (i + 1) % n;
    } while (i != (rear + 1) % n);
}

void getFront() {
    if (front == -1 && rear == -1) {
        printf("\nDeque is empty\n");
    } else {
        printf("Front Element : %d\n", deque[front]);
    }
}

void getRear() {
    if (front == -1 && rear == -1) {
        printf("\nDeque is empty\n");
    } else {
        printf("Rear Element : %d\n", deque[rear]);
    }
}

int main() {
    int num;
    printf("Enter Number of Elements : ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        insert_rear();
    }
    display();
    getFront();
    getRear();
    return 0;
}
