#include<stdio.h>

int main() {
    int a[12];
    printf("Enter the monthly rainfall: ");
    for (int i = 0; i < 12; i++) {
        scanf("%d", &a[i]);
        if(a[i]<0){
            printf("enter a positive one....");
            return 0;
        }
    }
    int sum = 0;
    for (int i = 0; i < 12; i++) {
        sum=sum+a[i];
    }
    int avg=sum/12;
    int high=a[0],highindex=0;
    int low=a[0],lowindex=0;
    //indices need to be 0 as initialized the first element..
    for (int i=0;i<12;i++){
        if(a[i]>high){
            high=a[i];
            highindex=i;
        }if(a[i]<low){
            low=a[i];
            lowindex=i;
        }
    }

    printf("Total%d\n avg %d\n high%d\n low%d\n ",sum,avg,highindex+1,lowindex+1); 
    // printf("Total rainfall: %d\n",sum);
    // printf("Average rainfall: %d\n",avg);
    // printf("highest rainfall: %d\n",highindex+1);
    // printf("lowest rainfall: %d\n",lowindex+1);

    return 0;
}
