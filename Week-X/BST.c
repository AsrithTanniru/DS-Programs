#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* Lchild;
    int data;
    struct node* Rchild;
};
struct node* root;
int count=0;

struct node* new_node_creation(int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->Lchild=NULL;
    newnode->Rchild=NULL;
    return newnode;
}

void insertion(int y){
    struct node* new_node=new_node_creation(y);
    struct node* curr=root,*parent;
    if(root==NULL){  
        root=new_node;
    }else{
        while(1){
            parent = curr;
            if (y < parent->data){
                curr = curr->Lchild;
                if (curr == NULL){
                    parent->Lchild = new_node;
                    break;
                }
            }else{
                curr = curr->Rchild;
                if (curr == NULL){
                    parent->Rchild = new_node;
                    break;
                }
            }
        }
    }   
}

void create(int n) {
    int i, val;
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &val);
        insertion(val);
    }
}

void display_inorder(struct node* root){
    if(root!=NULL){
        display_inorder(root->Lchild);
        printf("%d ",root->data);
        count++;
        display_inorder(root->Rchild);

    }
}
void display_preorder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        count++;
        display_preorder(root->Lchild);
        display_preorder(root->Rchild);
    }
}
void display_postorder(struct node* root){
    if(root!=NULL){
        display_postorder(root->Lchild);
        display_postorder(root->Rchild);
        printf("%d ",root->data);
        count++;
    }
}


int searchBST(struct node* root, int key){
    if(root==NULL){
        return 0;
    }
    else if(root->data==key){
        return 1;
    }else if(key<root->data){
        return searchBST(root->Lchild, key);
    }else{
        return searchBST(root->Rchild, key);
    }
}

int minBST(struct node* root){
    if(root==NULL){
        printf("Empty tree\n");
        return -1;
    }else if(root->Lchild==NULL){
        return root->data;
    }else{
        return minBST(root->Lchild);
    }
}

int maxBST(struct node* root){
    if(root==NULL){
        printf("Empty tree\n");
        return -1;
    }else if(root->Rchild==NULL){
        return root->data;
    }else{
        return maxBST(root->Rchild);
    }
}
int height(struct node* root){
    if(root==NULL)
        return 0;
    
    int leftH=height(root->Lchild);
    int rightH=height(root->Rchild);
    if(leftH>rightH){
        return leftH+1;
    }else{
        return rightH+1;
    }

}
int depth(struct node* root){
    if(root==NULL)
        return -1;
    
    int depthleft=depth(root->Lchild);
    int depthright=depth(root->Rchild);
    if(depthleft>depthright){
        return depthleft+1;
    }else{
        return depthright+1;
    }

}

int NumberofNodes(struct node *root){
    if(root==NULL){
        return 0;
    }else{
        return (1+NumberofNodes(root->Lchild)+NumberofNodes(root->Rchild));
    }
}
int main(){
    int item;
    int choice, val;
    // printf("Enter the number of nodes: ");
    // scanf("%d",&item);
    while(1){
        printf("\n1. Create\n2. Insert\n3. Display INORDER\n4. Display PREORDER\n5. Display POSTORDER\n6. Search\n7. Maximum\n8. Minimum\n9. Height\n10. Depth\n11. No.of Nodes\n12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("Enter the size: ");
                scanf("%d",&item);
                create(item);
                break;
            case 2:
                printf("Enter the element: ");
                scanf("%d", &val);
                insertion(val);
                break;
            case 3:
                count=0;
                display_inorder(root);
                printf("\n");
                printf("No. of Nodes:%d \n",count);
                break;
            case 4:
                count=0;
                display_preorder(root);
                printf("\n");
                printf("No. of Nodes:%d \n",count);
                break;
            case 5:
                count=0;
                display_postorder(root);
                printf("\n");
                printf("No. of Nodes:%d \n",count);
                break;
            case 6:
                printf("Enter the key value you want to search: ");
                scanf("%d", &val);
                if(searchBST(root, val)){
                    printf("Found\n");
                }else{
                    printf("Not found\n");
                }
                break;
            case 7:
                printf("Maximum value in BST: %d\n", maxBST(root));
                break;
            case 8:
                printf("Minimum value in BST: %d\n", minBST(root));
                break;
            case 9:
                printf("Height of the BST is: %d\n", height(root));
                break;
            case 10:
                printf("Depth of the BST is: %d\n", depth(root));
                break;
            case 11:
                printf("No.of Nodes are:%d",NumberofNodes(root));
                break;
            
            case 12:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("In valid Choice!...Enter the choice between 1 to 12...\n");
                break;
        }
    }
    return 0;
} 






