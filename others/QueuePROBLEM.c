#include<stdio.h>
#define max 100

struct Student {
    int rollNo;
    char name[100];
};

struct Student queue[max];
int rear = -1;
int front = -1;

void enqueue(struct Student student) {
    if (rear == max - 1) {
        printf("QUEUE is FULL..");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = student;
    }
}

void dequeue() {
    if (front == -1) {
        printf("QUEUE is empty....");
    } else {
        printf("Deleted element is: Roll No. %d, Name: %s\n", queue[front].rollNo, queue[front].name);
        front++;
    }
}

void frontAndRear() {
    if (front == -1) {
        printf("QUEUE is empty....");
    } else {
        printf("The front element is %d.\n", queue[front].rollNo);
        printf("The rear element is %d.\n", queue[rear].rollNo);
    }
}

void display() {
    if (front == -1) {
        printf("QUEUE is empty....");
    } else {
        printf("the elements in the queue are: ");
        for (int i = front; i <= rear; i++) {
            printf("Roll No. %d, Name: %s\n", queue[i].rollNo, queue[i].name);
        }
    }
}

int main() {
    int size;
    printf("Enter the size of QUEUE[MAX=100]: ");
    scanf("%d", &size);

    struct Student student;
    printf("QUEUE OPERATIONS USING ARRAY\n 1.ENQUEUE\n 2.DEQUEUE\n 3.FRONT AND REAR \n 4.DISPLAY\n 5.EXIT\n");

    int choice;
    while (1) {
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the Roll No.: ");
            scanf("%d", &student.rollNo);
            printf("Enter the Student Name: ");
            scanf("%s", student.name);
            enqueue(student);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            frontAndRear();
            break;
        case 4:
            display();
            break;

        case 5:
            printf("EXIT.");
            return 0;
        default:
            printf("Enter the choice b/w 1 and 5....");
            break;
        }
    }
    return 0;
}
