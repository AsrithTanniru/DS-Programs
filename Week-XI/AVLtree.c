#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
    int height;
};

struct Node* newNode(int key) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = key;
    newnode->left =NULL;
    newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}
//LL
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}
//RR
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct Node* insertAVL(struct Node* node, int data) {
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insertAVL(node->left, data);
    else if (data > node->data)
        node->right = insertAVL(node->right, data);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void traverse(struct Node* root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
    }
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteAVL(struct Node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteAVL(root->left, data);
    else if (data > root->data)
        root->right = deleteAVL(root->right, data);
    else {
        if (root->left == NULL || root->right == NULL) {
            struct Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            struct Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteAVL(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int isAVL(struct Node* root) {
    if (root == NULL)
        return 1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if ((leftHeight - rightHeight >= -1 && leftHeight - rightHeight <= 1) && isAVL(root->left) && isAVL(root->right))
        return 1;

    return 0;
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    while(1) {
        printf("\n1. Insert\n2. Display AVL\n3. Delete\n4. Check if AVL\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insertAVL(root, data);
                break;
            case 2:
                printf("AVL Tree (Inorder): ");
                traverse(root);
                printf("\n");
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteAVL(root, data);
                break;
            case 4:
                if (isAVL(root))
                    printf("The tree is AVL.\n");
                else
                    printf("The tree is not AVL.\n");
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
