#include <stdio.h>
#define MAX 100
void InsertSort(int A[MAX],int n){
    int i,j;
    for (int i=0;i<n;i++) printf("%d,",A[i]);
    printf("\n");
    for(i=2;i<=n;i++){
        if(A[i]<A[i-1]){
            A[0]=A[i];
            for (j=i-1;A[0]<A[j];--j) A[j+1]=A[j];
            A[j+1]=A[0];
        }
        for (int i=0;i<n;i++) printf("%d,",A[i]);
        printf("\n");
    }
}
int main(){
int A[10]={0,9,8,7,6,5,4,3,2,1};
int n=10;
InsertSort(A,n);
return 0;
}