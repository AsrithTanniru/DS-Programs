#include<stdio.h>

int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int mat[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &mat[i]);
    }
    int start=0,end=n-1;
    int key;
    printf("Enter the key to check: ");
    scanf("%d", &key);
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (key > mat[mid])
        {
            start = mid + 1;
        }
        else if (key < mat[mid])
        {
            end = mid - 1;
        }
        else if (key == mat[mid])
        {
            printf("Search Found");
            return 0;
        }
        printf("Value not found...\n");
        return 0;
    }
}
