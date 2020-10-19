#include <stdio.h>
#define MAX 15

void Merge(int A[],int low,int mid,int high){ //mid 指向分隔数组
    int B[MAX],i,j,k; //二路归并 i,j 指向两个归并段，k指向辅助数组
    for(k=low;k<=high;k++) B[k]=A[k]; //将A中所有元素复制到B
    for(i=low, j=mid+1,k=i;i<=mid&&j<=high;k++){
        if(B[i]<=B[j]) A[k]=B[i++];
        else A[k]=B[j++];
    }
    while (i<=mid) A[k++]=B[i++]; //剩余的直接加入
    while(j<=high) A[k++]=B[j++];  
}

void MergeSort(int A[MAX],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
    for(int i=0;i<high;i++) printf("%d,",A[i]);
    printf("\n");
}

int main(){
    int A[10]={49,38,65,97,76,13,27};
    int low=0,high=6;
    MergeSort(A,low,high);
    return 0;
}