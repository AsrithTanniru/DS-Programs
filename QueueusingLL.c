#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;

};

struct node*newnode,*front=NULL,*rear=NULL;

// void push(){
//     if(top==NULL){
//         top=(struct node*)malloc(sizeof(struct node));
//         scanf("%d",&top->data);
//         newnode->next=NULL;
//         top=newnode;
//     }else{
//         newnode=(struct node*)malloc(sizeof(struct node));
//         scanf("%d",&newnode->data);
//         newnode->next=top;
//         top=newnode;

//     }
//     printf("element successfully inserted..");
// }


void enqueue() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    // if (newnode == NULL) {
    //     printf("Memory allocation failed\n");
    // }

    printf("Enter data to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL; 

    if ((front==NULL)&&(rear==NULL))
    {
        front=rear=newnode;
    }else{
        rear->next=newnode;
        rear=newnode;
    }
    
    printf("Element successfully inserted.\n");
}


int dequeue(){
    struct node* ptr;
    int data;
    if(front==NULL){
        printf("Queue is empty..\n");
        return 0;
    }else{
        struct node* ptr;
        ptr=front;
        int deleted= front->data;
        front=front->next;
        free (ptr);
        printf("Deleted Element is %d:",deleted);

    }

    
}

void frontandrear(){
    printf("the front element is %d:\n",front->data);
    printf("the rear element is %d:\n",rear->data);
}

void display(){
    struct node*ptr;
    printf("The elements in the queue are: ");
    for(ptr=front;ptr!=rear;ptr=ptr->next){
        printf("%d \n",ptr->data);
    }
    printf("\n");
}

int main(){
    int choice;

    while(choice!=6){
        printf("1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT.\nEnter the choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            enqueue();
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
            printf("enter the value between 1 to 5.....");
            break;
        }
    }
}