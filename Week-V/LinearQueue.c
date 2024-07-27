//linear QUEUE
#include<stdio.h>
#define max 100
int queue[max],rear=-1,front=-1,i;

void enqueue(int size){
    if(rear==size-1){
        printf("QUEUE is FULL..\n");
    }else{
        if(front==-1){
            front=0;
            rear++;
        }else{  
        int ele;
        printf("Enter the value to  be inserted: ");
        scanf("%d",&ele);
        rear++;
        queue[rear]=ele;
        }
    }
}
void dequeue(){
    int popped;
    if(front==-1){
        printf("QUEUE is empty....");
    }else{
        popped=queue[front];
        front++;
        printf("Deleted element is: %d\n",popped);
    }
}
void frontandrear(){
    printf("The front element is %d.\n",queue[front]);
    printf("The rear element is %d.\n",queue[rear]);
}

void display(){
    printf("the elements in the queue are: ");
    for (int i=front;i<=rear;i++){
        printf("%d ",queue[i]);

    }
    printf("\n");
}

int main(){
    int size;
    printf("Enter the size of QUQUE[MAX=100]: ");
    scanf("%d",&size);
    printf("QUEUE OPERATIONS USING ARRAY\n 1.ENQUEUE\n 2.DEQUEUE\n 3.FRONT AND REAR \n 4.DISPLAY\n 5.EXIT\n");

    int choice;
    while(choice!=5){
    printf("Enter the choice: ");
    scanf("%d",&choice);
    
    switch (choice)
    {
    case 1:
        enqueue(size);
        break;
    case 2:
        dequeue();
        break;
    case 3:
        frontandrear();
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
}