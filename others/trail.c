// #include<stdio.h>
// int main(){
//     int i,j,a[4][4],sum=0;
//     printf("enter the elements:\n");
//     for ( i=0;i<4;i++){
//         for(j=0;j<4;j++){
//             scanf("%d",&a[i][j]);
//         }
//     }
//     printf("The elements of the matrix are: \n");
//     for(i=0;i<4;i++){
//         for(j=0;j<4;j++){
//             printf("%d ",a[i][j]);
//         }
//         printf("\n");
//     }

//     for( i=0;i<4;i++){
//         for(j=0;j<4;j++){
//             if(i==j){
//                 sum= sum+a[i][j];
//             }
//         }
//     }
//     printf("the sum of diagonal elements is:%d ",sum);
    
// }

// #include<stdio.h>
// int main(){
//     int n;
//     printf("enter N");
//     scanf("%d",&n);
//     int a[n];
//     printf("enter the elemts:");
//     for(int i=0;i<n;i++){
//         scanf("%d",&a[i]);
//     }
//     int target,found=0,i,index;
//     printf("enter the target:");
//     scanf("%d",&target);
//     for(i=0;i<n;i++){
//         if(a[i]==target){
//             found=1;
//             index=i;
//         }
//     }
//     if(found==1){
//         printf("element found at %d",index);

//     }else
//       printf("not found");
// }

// #include<stdio.h>
// int main(){
//   int n;
//   printf("enter the size of array:");
//   scanf("%d",&n);
//   int a[n];
//   printf("enter the elements");
//   for(int i=0;i<n;i++){
//     scanf("%d",&a[i]);
//   }  
//   int max=a[0],min=a[0];
//   for(int i=0;i<n;i++){
//     if(a[i]>max){
//         max=a[i];
//     }
//     if(a[i]<min){
//         min=a[i];
//     }
//   } 
//   printf("the maximum and minimum elements in the array are: max=%d,min=%d",max,min);
// }

// #include<stdio.h>
// int main(){
//   int n;
//   printf("enter the size of array:");
//   scanf("%d",&n);
//   int a[n];
//   printf("enter the elements");
//   for(int i=0;i<n;i++){
//     scanf("%d",&a[i]);
//   }  
//   int ele;
//   printf("enter the element:");
//   scanf("%d",&ele);
//   int greater=0,lesser=0,div=0;
//   for(int i=0;i<n;i++){
//     if(a[i]>ele){
//         greater++;
//     }if(a[i]<ele){
//         lesser++;
//     }if(a[i]%ele==0){
//         div++;
//     }
//   }
//   printf("greater: %d",greater);
//   printf("lesser: %d",lesser);
//   printf("div: %d",div);

// }
// #include<stdio.h>
// int main(){
//   int a[12];
//   printf("enter the elements");
//   for(int i=0;i<12;i++){
//     scanf("%d",&a[i]);
//   }  
//   int sum=0,avg=0,highest=a[0],lowest=a[0],hi=0,hl=0;
//   for(int i=0;i<12;i++){
//     sum=sum+a[i];
//   } 
//   avg=sum/12;
//   for(int i=0;i<12;i++){
//     if(a[i]>highest){
//         highest=a[i];
//         hi=i;
//     }if(a[i]<lowest){
//         lowest=a[i];
//         hl=i;
//   }
//   }
//   printf("sum: %d",sum);
//   printf("avg: %d",avg);
//   printf("low: %d",hi+1);
//   printf("high: %d",hl+1);

// }

// #include<stdio.h>
// int fact(int );
// int main(){
//     int N;
//     printf("enter the value of N");
//     scanf("%d",&N);
//     int res = fact(N);
//     printf("the factorial is %d",res);
// }
// int fact(int N){
//     if(N==0||N==1)
//        return 1;
//     else
//        return N*fact(N-1);
// }


// #include<stdio.h>
// int prime(int);
// int primenum(int);

// int prime(int num){
//     for(int i=2;i<num;i++){
//         if(num%i==0){
//             return 0;
//         }
//     }
//    return 1;
// }

// int primenum(int N){
//     int count=0,num=2;
//     while(count<N){
//         if(prime(num)==1){
//             printf("%d ",num);
//             count++;
//         }
//         num++;
//     }

// }
// int main(){
//     int N;
//     printf("enter N");
//     scanf("%d",&N);
//     int res=primenum(N);
//     printf("%d",res);
// }


// #include<stdio.h>
// #include<math.h>
// int prime(int);
// int primenum(int);

// int prime(int num){
//     for(int i=2;i<sqrt(num);i++){
//         if(num%i==0){
//             return 0;
//         }
//     }
//    return 1;
// }

// int primenum(int N){
//     int count=0,num=2;
//     while(count<N){
//         if(prime(num)==1){
//             printf("%d ",num);
//             count++;
//         }
//         num++;
//     }
//     return num-1;

// }
// int main(){
//     int N;
//     printf("enter N");
//     scanf("%d",&N);
//     int res=primenum(N);
//     printf("%d",res);
// }
// 





// struct node* reverse(){
//     struct node* ptr,*ptr1,*ptr;
//     ptr =head;
//     while(ptr!=NULL){
//         if(ptr==head){
//             ptr1=ptr;
//             ptr1->next=NULL;
//             ptr=ptr->next;
//         }else{
//             ptr2=ptr;
//             ptr2->next=ptr1;
//             ptr1=ptr2;
//             ptr=ptr->next;
//         }
    
//     }
// }