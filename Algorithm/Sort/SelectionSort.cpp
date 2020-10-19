#include<stdio.h>
#define MAX 15
void swap(int &a,int &b){
    int temp;
    temp=b;
    b=a;
    a=temp;
}
void SelectionSort(int A[MAX],int n){
    for (int i=0;i<n-1;i++){
        int min=i;
        int j;
        for( j=i+1;j<n;j++){
            if(A[j]<A[min]){
                min=j;
            }
        }
        if (min!=j) swap(A[i],A[min]);
    }
}

void HeadAdjust(int A[MAX],int k, int len){
    A[0]=A[k];
    for(int i=2*k;i<=len;i*=2){
        if(i<len&&A[i]<A[i+1]) i++;//指向key最大的左孩子或者 右孩子 i<len保证有右孩子
        if(A[0]>A[i]) break;   //判断孩子和根节点的大小
        else{
            A[k]=A[i];
            k=i;    //修改k值，形成小元素向下坠
        }
    }
    A[k]=A[0];
}

void BuildMaxHeap(int A[MAX],int len){
    for(int i=len/2;i>0;i--) HeadAdjust(A,i,len); //从后往前调整所有的非终端节点
}

void HeapSort(int A[MAX],int len){
    BuildMaxHeap(A,len);    //O(n)
    for(int i=len;i>1;i--){ //i=len指向堆底，
        swap(A[i],A[1]); //交换堆顶元素和堆底元素
        HeadAdjust(A,1,i-1);    //O(nlog2n) 每一趟都是O(h)=O(log2n)
    }
}