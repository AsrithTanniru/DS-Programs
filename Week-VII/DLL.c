#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* Lnext;
    int data;
    struct node* Rnext;
};

struct node *head,*newhead;
struct node *ptr,*curr,*prev;

struct node* CreateDoublyLL(int n){
    for(int i=1;i<=n;i++){
    if(i==1){
    head=(struct node*) malloc(sizeof(struct node));
    head->Lnext=NULL;
    ptr=head;
    }else{
        struct node *newnode=(struct node*) malloc(sizeof(struct node));
        ptr->Rnext=newnode;
        newnode->Lnext=ptr;
        ptr=newnode;
    }
    printf("Enter the %dth element: ",i);
    scanf("%d",&ptr->data);
    }
    ptr->Rnext=NULL;
    return head;  
}

void display(struct node*head){
    struct node *ptr;
    int count=0;
    for(ptr=head; ptr!=NULL; ptr=ptr->Rnext){
        printf("Node data is:%d\n",ptr->data);
        count++;
    }
    printf("the no.of nodes are: %d",count);
    printf("\n");

}
void search(struct node*head){
    struct node *ptr;
    int key,flag=0;
    printf("Enter the key value to check: ");
    scanf("%d",&key);
    for(ptr=head; ptr!=NULL; ptr=ptr->Rnext){
        if(ptr->data==key){
            flag=1;
        }
    }
    if(flag==1){
        printf("elemnet found");

    }else
      printf("not found");

    printf("\n");

}
struct node* maximum(struct node*head){
    int max;
    max=head->data;
    ptr=head;
    while(ptr!=NULL){
        if(ptr->data > max){
            max=ptr->data;
        }
        ptr=ptr->Rnext;
    }
    printf("The maximum element is: %d\n",max);
}

struct node* insert_BEGIN(struct node*head){
    struct node* newnode=(struct node*) malloc(sizeof(struct node));
    newnode->Lnext=NULL;
    printf("Enter the new value at the beginning: ");
    scanf("%d",&newnode->data);
    if(head==NULL){
        head=newnode;
        return head;
    }

    newnode->Rnext=head;
    head->Lnext=newnode;

    head=newnode;
    return (head);
}

struct node* insert_at_END(struct node*head){
    struct node* newnode=(struct node*) malloc(sizeof(struct node));
    newnode->Rnext=NULL;
    printf("Enter the new value at the END: ");
    scanf("%d",&newnode->data);
    if(head==NULL){
        newnode->Lnext=NULL;
        head=newnode;
        return head;
    }
    ptr=head;
    while(ptr->Rnext!=NULL){
        ptr=ptr->Rnext;
    }

    ptr->Rnext=newnode;
    newnode->Lnext=ptr;
    return (head);
}
struct node*  insertatPosition(struct node*head){
    int count=1,loc;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter the position: ");
    scanf("%d",&loc);
    printf("Enter the new value at the position: ");
    scanf("%d",&newnode->data);
    ptr=head;
    // if(head=NULL){
    //     head=newnode;
    //     newnode->Rnext=NULL;
    //     newnode->Lnext=NULL;
    // }
    while (ptr!=NULL&&count!=loc)
    {
        ptr=ptr->Rnext;
        count++;
    }
    
    if(ptr==NULL){
        printf("The location doesn't exist");
    }else{

    newnode->Rnext = ptr->Rnext;
    newnode->Lnext = ptr;
    ptr->Rnext->Lnext=newnode;
    ptr->Rnext=newnode;
    return(head);
    }
}

// struct node* deleteat_START(struct node*head){
//     struct node*ptr;
//     if(head==NULL){
//     return(head);
//     }else{
//     ptr=head;
//     ptr=ptr->Rnext;
//     ptr->Lnext=NULL;
//     head=ptr;
//     free(ptr);
//     } 
//     return head;   
// }

struct node* deleteat_START(struct node* head) {
    struct node* ptr;

    // EMPTY LIST..
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    // If there is only one node in the list
    if (head->Rnext == NULL) {
        free(head);
        return NULL;
    }

    ptr = head;
    head = head->Rnext;
    head->Lnext = NULL;

    free(ptr);
    return head;
}

struct node* deleteatEND(struct node*head){
    struct node*current,*previous;
    current=head;
    while (current->Rnext!=NULL)
    {
        previous=current;
        current=current->Rnext;
    }
    previous->Rnext=NULL;
    return(head);
}
struct node* delete_POSITION(struct node*head){
    struct node*current,*previous,*temp;
    int count=1,loc;
    printf("Enter the location at the  value to   be deleted: ");
    scanf("%d",&loc);
    current=head;
    // if(current !=NULL  &&current->data=key){
    //     head=current->Rnext;

    // }
    if(head==NULL){
        printf("empty list");
        return head;
    }
    while (current!=NULL&&count!=loc)
    {
        previous=current;
        current=current->Rnext;
        count++;
    }


    //if i've not found the key
    if (current == NULL) {
        printf("Element not found\n");
        return head;
    }

    previous->Rnext=current->Rnext;
    current->Rnext->Lnext=previous;
    // temp=current;
    // current=current->Rnext;
    // current->Lnext=prev;
    free(current);
    return head;


}
struct node *reverse_DLL(struct node *head) {
    struct node *current = head;
    struct node *prev = NULL;    
    while (current != NULL) {
        prev = current->Rnext; // changed to current->Rnext
        current->Rnext = current->Lnext;
        current->Lnext = prev;
        head = current;
        current = current->Rnext;
    }
    
    return head;
}






int main(){
    int n,choice;
    printf("Enter the no of values in DoublyLL");
    scanf("%d",&n);

    head=CreateDoublyLL(n);

    while(choice!=11){
        printf("1.Display\n2.Insert at begin\n3.Insert at END.\n4.Insert at position\n5.Delete at start\n6.Delete at end.\n7.Delete at position\n8.reverse the list.\n 9.Search an element\n10.Maximum element\n11.EXIT\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                display(head);
                break;
            case 2:
                head=insert_BEGIN(head);
                break;
            case 3:
                head=insert_at_END(head);
                break;
            case 4:
                head=insertatPosition(head);
                break;
            case 5:
                head=deleteat_START(head);
                break;
            case 6:
                head= deleteatEND(head);
                break;
            case 7:
                head=delete_POSITION(head);
                break;
            case 8:
                head=reverse_DLL(head);
                break;
            case 9:
                search(head);
                break;
            case 10:
                maximum(head);
                break;
            case 11:
                printf("exiting...");
                return 0;
                break;
            default:
                printf("Enter the choice between 1 and 11..");
                break;
    }
    
}


}
