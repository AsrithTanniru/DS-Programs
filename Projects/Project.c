#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee{
    struct Employee* Lchild;
    int employee_id; 
    char name[50];
    char position[30];
    float salary;
    struct Employee* Rchild;
};

struct Employee* root;
int count = 0;

struct Employee* new_employee_creation(int e_id, char name[], char position[], float salary){
    struct Employee* new_employee = (struct Employee*)malloc(sizeof(struct Employee));
    new_employee->employee_id = e_id;
    new_employee->salary = salary;
    strcpy(new_employee->name, name);
    strcpy(new_employee->position, position);
    new_employee->Lchild = NULL;
    new_employee->Rchild = NULL;
    return new_employee;
}

void insertion(int e_id, char name[], char position[], float salary){
    struct Employee* new_employee = new_employee_creation(e_id, name, position, salary);
    struct Employee* curr = root, *parent;
    if(root == NULL){  
        root = new_employee;
    }else{
        while(1){
            parent = curr;
            if (e_id < parent->employee_id){
                curr = curr->Lchild;
                if (curr == NULL){
                    parent->Lchild = new_employee;
                    break;
                }
            }else{
                curr = curr->Rchild;
                if (curr == NULL){
                    parent->Rchild = new_employee;
                    break;
                }
            }
        }
    }
}

void create(int n) {
    int i, e_id;
    char name[50], position[30];
    float salary;
    for (i = 0; i < n; i++) {
        printf("Enter the Employee ID for employee %d: ", i+1);
        scanf("%d", &e_id);
        printf("Enter the name of the Employee: ");
        scanf("%s", name);
        printf("Enter the position of the Employee: ");
        scanf("%s", position); 
        printf("Enter the salary of the Employee per DAY: ");
        scanf("%f", &salary);
        insertion(e_id, name, position, salary);
    }
}

void display_inorder(struct Employee* root){
    if(root != NULL){
        display_inorder(root->Lchild);
        printf("ID: %d\nName: %s\nPosition: %s\nSalary per day: %.2f\n", root->employee_id, root->name, root->position, root->salary);
        printf("--------------\n");
        count++;
        display_inorder(root->Rchild);
    }
}

struct Employee* searchEmployee(struct Employee* root, int empID){
    if(root == NULL || root->employee_id == empID){
        return root;
    }
    if(empID < root->employee_id){
        return searchEmployee(root->Lchild, empID);
    }else{
        return searchEmployee(root->Rchild, empID);
    }
}

float computeSalary(struct Employee *root, int empID){
    struct Employee *employee = searchEmployee(root, empID);
    if (employee != NULL) {
        return employee->salary * 30;
    } else {
        return 1.0;
    }
}

struct Employee *deleteEmployee(struct Employee *root, int empID)
{
    if (root == NULL) {
        printf("Employee with ID %d not found.\n", empID);
        return NULL;
    }

    if (empID < root->employee_id)
    {
        root->Lchild = deleteEmployee(root->Lchild, empID);
    }
    else if (empID > root->employee_id)
    {
        root->Rchild = deleteEmployee(root->Rchild, empID);
    }
    else
    {
        // Case 1
        if (root->Lchild == NULL && root->Rchild == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: 
        else if (root->Lchild == NULL) {
            struct Employee *temp = root->Rchild;
            free(root);
            return temp; 
        }
        else if (root->Rchild == NULL) {
            struct Employee *temp = root->Lchild;
            free(root);
            return temp; 
        }
        // Case 3
        else {
            
            struct Employee *minRight = root->Rchild;
            while (minRight->Lchild != NULL) {
                minRight = minRight->Lchild;
            }
           
            root->employee_id = minRight->employee_id;
            root->Rchild = deleteEmployee(root->Rchild, minRight->employee_id); 
        }
    }

    return root;
}



int NumberofEmployees(struct Employee *root){
    if(root == NULL){
        return 0;
    }else{
        return (1 + NumberofEmployees(root->Lchild) + NumberofEmployees(root->Rchild));
    }
}

int main(){
    int choice, empID,item;
    float salary;
    char name[50], position[30];
    struct Employee *foundEmployee = NULL; 

    while(1){
        printf("Employee Management System Using Binary Search Tree.");
        printf("\n1. Create\n2. Add an Employee\n3. Search an  Employee\n4. Display the Employees\n5. Compute Salary\n6. Delete Employee\n7. No. of Employees\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Enter the size: ");
                scanf("%d", &item);
                create(item);
                break;
            case 2:
                printf("Enter employee ID: ");
                scanf("%d", &empID);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter position: ");
                scanf("%s", position);
                printf("Enter salary per day: ");
                scanf("%f", &salary);
                insertion(empID, name, position, salary);
                break;
            case 3:
                printf("Enter the employee ID to search: ");
                scanf("%d", &empID);
                foundEmployee = searchEmployee(root, empID);
                if (foundEmployee != NULL) {
                    printf("Employee found!\n");
                    printf("ID: %d\nName: %s\nPosition: %s\nSalary per day : %.2f\n",foundEmployee->employee_id, foundEmployee->name,foundEmployee->position, foundEmployee->salary);
                } else {
                    printf("Employee not found.\n");
                }
                break;
            case 4:
                count = 0;
                display_inorder(root);
                printf("No. of Employees: %d\n", count);
                break;
            case 5:
                printf("Enter the employee ID to compute salary: ");
                scanf("%d", &empID);
                printf("Computed  monthly salary of employee %d is: %.2f\n",empID, computeSalary(root, empID));
                break;
            case 6:
                printf("Enter the employee ID to delete: ");
                scanf("%d", &empID);
                root = deleteEmployee(root, empID);
                printf("Employee deleted.\n");
                break;
            case 7:
                printf("No. of employees: %d\n", NumberofEmployees(root));
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid Choice! Enter a choice between 1 to 8\n");
                break;
        }
    }
    return 0;
}
