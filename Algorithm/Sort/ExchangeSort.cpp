#include <stdio.h>
#define MAX 15
void swap(int &a,int &b){
    int temp;
    temp=b;
    b=a;
    a=temp;
}
void BubbleSort(int A[MAX],int n){
    for(int i=0;i<n-1;i++){
        bool flag=false;   //本趟冒泡是否发生交换的标志
        for(int j=n-1;j>i;j--){
            if(A[j-1]>A[j]){
                swap(A[j-1],A[j]);
                flag=true;
            }
        }
        if (flag ==false) return;
    }
}

int Partition(int A[MAX],int low,int high){
    int pivot =A[low];
    while (low<high)
    {
        while(low<high&&A[high]>=pivot) --high;
        A[low]=A[high];
        while (low<high&&A[low]<=pivot) ++low;
        A[high]=A[low];
    }
    A[low]=pivot;
    return low;
}

void QuickSort(int A[MAX],int low,int high){
    if(low<high){
        int pivotpos=Partition(A,low,high);
        QuickSort(A,low,pivotpos-1);
        QuickSort(A,pivotpos+1,high);
    }
}

int main(){
    int A[8]={49,38,65,97,76,13,27,49};
    int n=8;
    QuickSort(A,0,7);
    return 0;
}







/*
int main(){
    int A[10]={9,8,7,6,5,4,3,2,1};
    int n=9;
    BubbleSort(A,n);
}*/