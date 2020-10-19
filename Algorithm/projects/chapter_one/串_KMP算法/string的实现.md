---
abbrlink: '0'
---
##### 串的顺序存储
- 方案一 最传统 限制最小
- 方案二 字符的位和数组下标一一对应（最多存储255个字符因为ch是1B length的最大值是255）
- 方案三 无length变量，以字符‘\0’结尾
- 方案四 综合方案一二的优点
![20201001204531](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201001204531.png)

#### KMP Algorithm
> 通过next数组，主串指针不回溯，只有模式串指针回溯
复杂度是O(m+n) 求next数组O(n) ,KMP O(m) 总O=m+n 最坏情况也是O(mn)
![20201001212507](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201001212507.png)
```C++
int Index_KMP(SString S,SString T, int next[]){
    int i=1,j=1;
    while(i<=S.length&&j<=T.length){
        if(j==0||S.ch[i]==T.ch[j]){
            ++i;
            ++j;
        }
        else
            j=next[j];   //模式串右移
    }
    if (j>T.length)
        return i-T.length;    //匹配成功
    else
        return 0;
}
```
##### next数组的求法
![20201001211626](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201001211626.png)

```C++
void get_next(SString T,int next[]){
    int i=1,j=o;
    next[1]=0;
    while(i<T.length){
        if (j==0||T.ch[i]==T.ch[j]){
            ++i;++j;
            // 若pi=pj ,则next[j+1]=next[j]+1
            next[i]=j;
        }
        else
            //否则令j=next[j]
            j=next[j];
    }
}
```


##### 改进KMP算法 nextval数组
```C++
nextval[1]=0;
for(int j=2;j<=T.length;j++){
    if(T.ch[next[j]]==T.ch[j])
        nextval[j]=nextval[next[j]];
    else
        nextval[j]=next[j];
}
```

![20201001213501](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201001213501.png)


```C++
#include <stdio.h>
void InsertSort(int A[],int n){
    int i,j;
    for(i=2;i<=n;i++){
        if(A[i]<A[i-1]){
            A[0]=A[i];
            for (j=i-1;A[0]<A[j];--j) A[j+1]=A[j];
            A[j+1]=A[0];
        }
        for (int i=0;i<n;i++) printf("%d,",i);
    }
}
int A=[10,9,8,7,6,5,4,3,2,1];
n=10;
InsertSort(A,n)
```