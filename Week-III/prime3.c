#include<stdio.h>
#include<math.h>
int prime(int num){
    for(int i= 2;i<sqrt(num);i++){
            if(num % i==0){
                return 0;
            }  
    }
    return 1; 
}
int primenum(int N){
    int count=0;
    int num =2;
    for(int i=2;i<N;i++){
        if(prime(num)==1){
            printf("%d ",num);
            count++;
        }
        num++;
    }
    printf("\n");
}
int main(){
    int N;
    printf("Enter N:");
    scanf("%d",&N);
    primenum(N);

}