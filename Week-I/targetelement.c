#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements of the array:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int e;
    printf("enter the element you want to check: ");
    scanf("%d",&e);
    int i,found=0;
    int index=0;
    for(int i=0;i<n;i++){
    if(a[i]==e){
        found=1;
        index=i;
        break;
    }
    }
    if(found==1){
        printf("\"Yes\".Element is present in the array at the index %d.",index+1);
        //need to add 1 to the index to print at the correct place that's visible....
    }else{
        printf("\"No\"The element does not exist\"");   
    }
}