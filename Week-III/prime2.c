#include<stdio.h>
#include<time.h>
#include<math.h>
int prime(int num){
    for(int i= 2;i*i<num;i++){
            if(num % i==0){
                return 0;
            }  
    }
    return 1; 
}
int primenum(int N){
    time_t start_t,end_t;
    int count=0;
    int num =2;
    time(&start_t);
    while(count<N){
        if(prime(num)==1){
            printf("%d  ",num);
            count++;
        }
        num++;
    }
    time(&end_t);
    printf("\n");
    return difftime(end_t, start_t);
}
int main(){
    int N;
    printf("Enter N:");
    scanf("%d",&N);
    double diff_t= primenum(N);
    printf("time: %f",diff_t);

}