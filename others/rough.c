#include <stdio.h>
#include <stdlib.h>
#include<math.h>
struct node {
    struct node *leftchild;
    int data;
    struct node *rightchild;
};
struct node *root;

struct node* newnode(int z) {
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->data = z;
    nn->leftchild = NULL;
    nn->rightchild = NULL;
    return nn;
}

void insert(int x) {
    struct node *nn = newnode(x);
    if (root == NULL) {
        root = nn;
        return;
    }
    struct node *curr = root;
    struct node *parent;
    while (1) {
        parent = curr;
        if (x < parent->data) {
            curr = curr->leftchild;
            if (curr == NULL) {
                parent->leftchild = nn;
                return;
            }
        } else {
            curr = curr->rightchild;
            if (curr == NULL) {
                parent->rightchild = nn;
                return;
            }
        }
    }
}

void create(int n) {
    int i, w;
    for (i = 0; i < n; i++) {
        printf("enter element: ");
        scanf("%d", &w);
        insert(w);
    }
}

void display(struct node* root) {
    if (root != NULL) {
        display(root->leftchild);
        printf("%d ", root->data);
        display(root->rightchild);
    }
}

int search(int key, struct node* root) {
    if (root == NULL)
        return 0;
    else if (root->data == key)
        return 1;
    else if (key < root->data)
        return search(key, root->leftchild);
    else
        return search(key, root->rightchild);
}

int max(struct node* root) {
    if (root == NULL) {
        printf("empty tree");
        return 0;
    } else if (root->rightchild == NULL)
        return root->data;
    else
        return max(root->rightchild);
}

int min(struct node* root) {
    if (root == NULL) {
        printf("empty tree");
        return 0;
    } else if (root->leftchild == NULL)
        return root->data;
    else
        return min(root->leftchild);
}
int height(struct node* root) {
    if (root == NULL) {
        return -1;
    }
    int leftheight = height(root->leftchild);
    int rightheight = height(root->rightchild);
    if(leftheight>rightheight)
    return leftheight+1;
    else
    return rightheight+1;
}
int main() {
    int choice, n, k,h;
    printf("1.create\n2.insert\n3.display\n4.search\n5.maximum\n6.minimum\n7.height\n8.exit");
    while (1) {
        printf("\n enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("enter size: ");
                scanf("%d", &n);
                create(n);
                break;
            case 2:
                printf("enter element to insert: ");
                scanf("%d", &k);
                insert(k);
                break;
            case 3:
                printf("Tree elements: ");
                display(root);
                printf("\n");
                break;
            case 4:
                printf("enter element to search: ");
                scanf("%d", &k);
                if (search(k, root))
                    printf("found.\n");
                else
                    printf(" not found .\n");
                break;
            case 5:
                printf("Maximum element: %d\n", max(root));
                break;
            case 6:
                printf("Minimum element: %d\n", min(root));
                break;
             case 7:
             	h=height(root);
             	printf("height of tree is %d",h);
				   break;   
            case 8:
                printf("Exiting program\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}