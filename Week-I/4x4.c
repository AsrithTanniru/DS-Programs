#include<stdio.h>
int main(){
    int a[4][4];
    int i,j,sum=0;
    printf("Enter the elements of the matrix:\n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("The elements in the matrix are:\n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");    
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(i==j){
            sum= sum+a[i][j];
            }
        }
    }
    printf("Sum of diagonal elements is: %d",sum);

}
