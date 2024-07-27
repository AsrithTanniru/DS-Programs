#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* top=NULL,*newnode;

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


void push() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(top==NULL){
        printf("stack is empty..\n");
        return 0;
    }else{

    printf("Enter data to push: ");
    scanf("%d", &newnode->data);
    newnode->next = top; // Link new node to the current top

    top = newnode; // Update top to point to the new node
    printf("Element successfully inserted.\n");
    }
}


int pop(){
    struct node* ptr=top;
    int data;
    if(top==NULL){
        printf("stack is empty..\n");
        return 0;
    }else{
        data=top->data;
        top=top->next;
        free(ptr);
    }
printf("popped element is: %d \n", data);
    
}

void peek(){
    printf("the lastly entered element is %d:\n",top->data);
}

void display(){
    struct node*ptr;
    printf("The elements in the stack are: ");
    for(ptr=top;ptr!=NULL;ptr=ptr->next){
        printf("%d ",ptr->data);
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
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
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

    // Declare choice as integer
    // Loop until choice is 5:
    //     Print menu options (1: Push, 2: Pop, 3: Peek, 4: Display, 5: Exit)
    //     Input choice
    //     Switch choice:
    //         Case 1: Call push()
    //         Case 2: Call pop() and assign result to variable popped
    //                  If popped is not 0, print "Popped element is: popped"
    //         Case 3: Call peek()
    //         Case 4: Call display()
    //         Case 5: Print "Exit."
    //                 Exit loop
    //         Default: Print "Enter a value between 1 to 5."
}