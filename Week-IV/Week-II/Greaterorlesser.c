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
        if(a[i]<element){
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