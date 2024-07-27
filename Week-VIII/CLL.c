#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;
struct node *ptr;

struct node* createList(int n){
    for(int i=1; i<=n; i++){
        if(i==1){
            head = (struct node*)malloc(sizeof(struct node));
            ptr=head;
        }else{
            ptr->next=(struct node*)malloc(sizeof(struct node));
            ptr=ptr->next;
        }
        printf("Enter the %dth element: ",i);
        scanf("%d",&ptr->data);
    }

    ptr->next=head;//modified the head instead of NULL in SLL.. 
    return head;
}

void display(struct node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }

    struct node* ptr = head; // Start from the head node
    int count = 0;

    do {
        printf("Node data is: %d\n", ptr->data);
        count++;
        ptr = ptr->next;
    } while (ptr != head);

    printf("The number of nodes are: %d\n", count);
}

void search(struct node*head){
    struct node *ptr;
    int key,flag=0;
    printf("Enter the key value to check: ");
    scanf("%d",&key);
    //for(ptr = head->next; ptr!= head; ptr = ptr->next)
    for (ptr = head->next; ptr != head; ptr = ptr->next){
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


struct node*  insertbegin(struct node*head){
    struct node *ptr,*newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the new value at the beginning: ");
    scanf("%d",&newnode->data);
    newnode->next = head;
    ptr = head;
    while (ptr->next!=head){
        ptr = ptr->next;
    }
    ptr->next = newnode;
    head = newnode;
    return (head);
}

struct node* insertatEND(struct node*head){
    struct node *ptr,*newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the new value at the end: ");
    scanf("%d",&newnode->data);
    // newnode->next = head;

    if(head==NULL){
        head = newnode;
        newnode->next=head;
        return (head);
    }
    else
    {
        ptr = head;
        while (ptr->next!= head)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = head;
    }
   return(head);
}

struct node*  insertatPosition(struct node*head){
    struct node*ptr;
    int count=1,loc;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter the position: ");
    scanf("%d",&loc);
    printf("Enter the new value at the position: ");
    scanf("%d",&newnode->data);
    ptr=head;
    while (ptr->next!=head&&count!=loc)
    {
        ptr=ptr->next;
        count++;
    }

    if (count != loc) {
        printf("The location doesn't exist.");
        free(newnode);
        return head; 
    }else{

    newnode->next = ptr->next;
    ptr->next = newnode;
    }
    return(head);
}

struct node* deleteatSTART(struct node*head){
    if(head==NULL){
     printf("empty linked list");
    }
    struct node *ptr=head;
    if (head->next == head) {//if one node in the list.....
            free(head);
            head = NULL;
            return head;
    }
    else
    {
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }

        ptr->next = head->next;
        struct node *temp=head;
        head = head->next;
        free(temp);
        printf("node deleted at the beginning...");
    }
    return head;
}  

struct node* deleteatEND(struct node*head){
    struct node*current=head,*previous=NULL;
    while (current->next!=head)
    {
        previous=current;
        current=current->next;
    }
    if(previous==NULL){
        free(head);
        head=NULL;
    }else{
    previous->next=head;
    free(current);
    }
    return(head);
}

struct node* delete_POSITION(struct node*head){
    struct node*current=head,*previous=NULL;
    int loc,count=1;
    if (head == NULL) {
        printf("empty list\n");
        return head;
    }

    printf("Enter the location to delete: ");
    scanf("%d", &loc);

    while (current->next!=head&&count!=loc){
        previous=current;
        current=current->next;
        count++;
    }
    if (count!=loc) {
        printf("location not exist");
    } else {
        previous->next = current->next;
        free(current);
    }
    return(head);
}

void maximum(struct node* head) {
    // if (head == NULL) {
    //     printf("Empty list\n");
    //     return;
    // }

    struct node* ptr = head;
    int max = head->data;

    do {
        if (ptr->data > max) {
            max = ptr->data;
        }
        ptr = ptr->next;
    } while (ptr != head);

    printf("The maximum element in the list is: %d\n", max);
}


int main(){
    int n, choice;
    printf("Enter the no of values IN LL: ");
    scanf("%d",&n);
    
    head=createList(n);

    while(1){
        printf("1.Display\n2.Insert at begin\n3.Insert at END.\n4.Insert at position\n5.Delete at start\n6.Delete at end.\n7.Delete at position\n8.Search an element\n9.Maximum element\n10.EXIT\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                display(head);
                break;
            case 2:
                head=insertbegin(head);
                break;
            case 3:
                head=insertatEND(head);
                break;
            case 4:
                head=insertatPosition(head);
                break;
            case 5:
                head=deleteatSTART(head);
                break;
            case 6:
                head= deleteatEND(head);
                break;
            case 7:
                head=delete_POSITION(head);
                break;
            case 8:
                search(head);
                break;
            case 9:
                maximum(head);
                break;
            case 10 :
                printf("EXIT");
                return 0;
                break;
            default:
                printf("Enter the choice between 1 and 10..");
                break;
        }
    }
}


// struct node* deleteend(struct node* head){
//     int count=1,loc=2;
//     struct node* prev,*curr=head;
//     while (curr!=head&&count!=loc){
//         prev=curr;
//         curr=curr->next;
//         count++;
//     }

//     prev->next=curr->next;
//     free (curr);

// }