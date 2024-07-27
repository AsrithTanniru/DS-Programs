////1st program
#include<stdio.h>
int main(){
    int n;
    printf("Enter the value of N:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements: ");
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int element;
    printf("enter the element you want to check: ");
    scanf("%d",&element);
    int greater=0,lesser=0,divisible=0;
    for(int i=0;i<n;i++){
        if(a[i]>element){
            greater++;  
        }
        else if(a[i]<element){
            lesser++;  
        }
        if(a[i]%element==0){
            divisible++;
        }
        
    }
    printf("Greater: %d\n",greater);
    printf("Lesser:  %d\n",lesser);
    printf("Exactly Divisible: %d",divisible);
    
}
//2nd program
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

 
    printf("Total rainfall: %d\n",sum);
    printf("Average rainfall: %d\n",avg);
    printf("highest rainfall: %d\n",highindex+1);
    printf("lowest rainfall: %d\n",lowindex+1);

    return 0;
}
///3rd program
#include<stdio.h>
int fact(int n){
    if(n==0||n==1){
        return 1;
    }else
        return n*fact(n-1);
}
int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    int res=fact(n);
    printf("The factorial of %d is: %d",n,res);
    return 0;
}

