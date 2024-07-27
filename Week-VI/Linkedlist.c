#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;
struct node *ptr,*curr,*prev;

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

    ptr->next=NULL;
    return head;
}

void display(struct node*head){
    struct node *ptr;
    int count=0;
    for(ptr=head; ptr!=NULL; ptr=ptr->next){
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
    for(ptr=head; ptr!=NULL; ptr=ptr->next){
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
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the new value at the beginning: ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    return head;
}

struct node* insertatEND(struct node*head){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the new value at the end: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;

    if(head==NULL){
        head = newnode;
        return (head);
    }
    else
    {
        ptr = head;
        while (ptr->next!= NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
   return(head);
}

struct node*  insertatPosition(struct node*head){
    int count=1,loc;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter the position: ");
    scanf("%d",&loc);
    printf("Enter the new value at the position: ");
    scanf("%d",&newnode->data);
    ptr=head;
    while (ptr!=NULL&&count!=loc)
    {
        ptr=ptr->next;
        count++;
    }
    
    if(ptr==NULL){
        printf("The location doesn't exist");
    }else{//nOT PLACED THE REMAINING STATEMENTS IN THE ELSE PART..

    newnode->next = ptr->next;
    ptr->next = newnode;
    return(head);
    }
}

struct node* deleteatSTART(struct node*head){
    struct node*ptr;
    if(head==NULL){
     printf("empty linked list");
    }else{
    ptr=head;
    head=head->next;
    free(ptr);
    printf("node deleted at the beginning...");
    }
    return head;
}

struct node* deleteatEND(struct node*head){
    struct node*current,*previous;
    current=head;
    while (current->next!=NULL)
    {
        previous=current;
        current=current->next;
    }
    previous->next=NULL;
    return(head);
}

struct node* delete_POSITION(struct node*head){
    struct node*current=head,*previous=NULL;
    int key;
    if (head == NULL) {
        printf("empty list\n");
        return head;
    }

    printf("Enter the data value to delete: ");
    scanf("%d", &key);

    // If the node to be deleted is the first node
    if (head->data == key) {
        head = head->next;
        free(current);
        printf("Node with value %d deleted\n", key);
        return head;
    }
    while (current!=NULL&&current->data!=key)
    {
        previous=current;
        current=current->next;
    }
    //for getting the key node..
    if (current != NULL) {
        previous->next = current->next;
        free(current);
        printf("Node with value %d deleted\n", key);
    } else {
        printf("Node with value %d not found\n", key);
    }
    return(head);
}

void maximum(struct node*head){
    int max;
    max=head->data;
    ptr=head;    
    while(ptr!=NULL){
        if(ptr->data > max){
            max=ptr->data;
        }
        
        ptr=ptr->next;
    }
    printf("the maximum element in the list is: %d\n",max);
}
struct node* reverse_LL(struct node*head){
    struct node*ptr,*ptr1,*ptr2;
    ptr=head;
    while(ptr!=NULL){
        if(ptr==head){
            ptr1=ptr;
            ptr=ptr->next;
            ptr1->next=NULL;
        }else{
            ptr2=ptr;
            ptr=ptr->next;
            ptr2->next=ptr1;
            ptr1=ptr2;
            head=ptr1;
        }
    }
    return  head;
}


int main(){
    int n, choice;
    printf("Enter the no of values IN LL: ");
    scanf("%d",&n);
    
    head=createList(n);

    while(1){
        printf("1.Display\n2.Insert at begin\n3.Insert at END.\n4.Insert at position\n5.Delete at start\n6.Delete at end.\n7.Delete at position\n8.reverse the list.\n 9.Search an element\n10.Maximum element\n");
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
                head= reverse_LL(head);
                break;
            case 9:
                search(head);
                break;
            case 10:
                maximum(head);
                break;
            case 11:
                return 0;
                break;
            default:
                printf("Enter the choice between 1 and 10..");
                break;
        }
    }
}
