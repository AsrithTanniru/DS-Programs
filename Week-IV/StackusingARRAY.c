#include<stdio.h>
#define max 100
int stack[max],top=-1,i;

void push(){
    if(top==max-1){
        printf("Stack OVERFLOW");
    }else{
        int ele;
        printf("Enter the value to  be pushed: ");
        scanf("%d",&ele);
        top=top+1;
        stack[top]=ele;
    }
}
void pop(){
    int popped;
    if(top==-1){
        printf("STACK is empty..");
    }else{//kept the popped keyword down then corrected......
        popped=stack[top];
        top=top-1;
        printf("Popped elemet is: %d\n",popped);
    }
}
void peek(){
    printf("The lastly entered element is %d.\n",stack[top]);
}

void display(){
    printf("the elements in the stack are: ");
    for (int i=0;i<=top;i++){//used i<top instead of "====""
        printf("%d ",stack[i]);

    }
    printf("\n");
}

int main(){
    int size;
    printf("Enter the size of STACK[MAX=100]: ");
    scanf("%d",&size);
    printf("STACK OPERATIONS USING ARRAY\n 1.PUSH\n 2.POP\n 3.TOP\n 4.DISPLAY\n 5.EXIT\n");

    int choice;
    //Not kept the entire switch case into the loop this ended exiting the program...
    while(1){
    printf("Enter the choice: ");
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
        printf("Enter the choice b/w 1 and 5....");
        break;
    }
    }
}

