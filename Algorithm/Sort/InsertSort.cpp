#include <stdio.h>
#define MAX 15
void InsertSort(int A[MAX],int n){
    int i,j;
    for (int i=0;i<n;i++) printf("%d,",A[i]);
    printf("\n");
    for(i=2;i<=n;i++){
        if(A[i]<A[i-1]){
            A[0]=A[i];
            for (j=i-1;A[0]<A[j];--j) { //for循环从后往前找到待插入的位置，并将元素整体后移
                A[j+1]=A[j];   //后移操作
                printf("j=%d,",j);
                //循环执行完之后j的值会--
            }    
            A[j+1]=A[0]; //复制哨兵到插入位置
        }
        for (int i=0;i<n;i++) printf("%d,",A[i]);
        printf("\n");
    }
}

void BinarySort(int A[MAX],int n){
    int i,j,low,high,mid;
    for (int i=0;i<n;i++) printf("%d,",A[i]);
    printf("\n");
    for(i=2;i<=n;i++){
        A[0]=A[i];
        low=1;high=i-1;
        while(low<=high){
            mid=(low+high)/2;
            if(A[mid]>A[0]) high=mid-1;
            else low=mid+1;
        }
        for (int i=0;i<n;i++) printf("%d,",A[i]);
        printf("\n");
        for (j=i-1;j>=high+1;--j) A[j+1]=A[j]; //后移操作
        for (int i=0;i<n;i++) printf("%d,",A[i]);
        printf("\n");
        A[high+1]=A[0];
    }
}

void ShellSort(int A[MAX],int n){
    int j;
    for(int dk=n/2;dk>=1;dk=dk/2){
        for(int i=dk+1;i<=n;++i){
            if(A[i]<A[i-dk]){
                A[0]= A[i];
                for( j=i-dk;j>0&&A[0]<A[j];j-=dk){
                    A[j+dk]=A[j];
                }
                //for (int i=0;i<n;i++) printf("%d,",A[i]);
                //printf("\n");
                A[j+dk]=A[0];
            }
    for (int i=0;i<n;i++) printf("%d,",A[i]);
    printf("\n");
        }
    }
    for (int i=0;i<n;i++) printf("%d,",A[i]);
    printf("\n");
}
int main(){
    int A[11]={0,49,38,65,97,76,13,27,49,55,4};
    int n=11;
    //InsertSort(A,n);
    //BinarySort(A,n);
    ShellSort(A,n);
    return 0;
}