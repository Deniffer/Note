#### Q1. ASL(Average Search Length)的计算公式
#### Q2. 顺序查找和折半查找的实现
#### Q3. 折半查找判定树
#### Q4. B树的最低高度/最高高度
#### Q5. B/B+树区别




Q1.
$$ASL=\sum^{n}_{i=1}P_iC_i$$

Q2.
```C++
typedef struct{
    Elemtype *elem ;
    int TableLen;
}SSTable;
int Search_Seq(SSTable ST,ElemType key){
    ST.elem[0] = key;
    for(i=ST.TableLen;ST.elem[i]!=key;--i){
        return i;
    }
}
int Binary_Search (SeqList L,ElemType key){
    int low=0,high=L.TableLen-1,mid;
    while(low<high){
        mid=(low+high)/2;
        if(L.elem[mid]==key){
            return mid;
        }
        else if(L.elem[mid]>key){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1
}
```

Q4.
B树
- 每个节点最多有m棵子树，即至多有m-1个关键字
- 若根节点不是终端节点，则至少有两棵子树
- 除根节点外的所有非叶节点至少有$\lceil m/2\rceil $棵子树，即最少$\lceil m/2\rceil -1$个关键字    $ \qquad\textcolor{red}{(尽可能平衡)}$
- 所有的叶节点都出现在同一层次上，并且可以是为NULL，即查找失败的情况

高度情况
- 最多情况：每个节点最多有m棵子树，m-1个关键字，所以在一颗高度为h的m阶B树中关键字的个数应该满足$$n \le (m-1)(1+m+m^2+\cdots +m^{h-1} )=m^h-1$$
其中$m-1$代表了每个节点最多的关键字，$(m-1)(1+m+m^2+\cdots +m^{h-1} )$代表每层最多的结点数的求和
因此可以解得$$h\ge log_m(n+1)$$

- 最少情况：第一层至少有1个节点，第二层至少有2个节点，除根结点外的每个非终端节点至少有$\lceil m/2\rceil$个子树，则第三层至少有$2\lceil m/2\rceil$棵子树，第h层有$2(\lceil m/2\rceil)^{h-1}$个节点，注意第h+1层是不包含任何信息的叶节点，且对于关键字为n的B树，有n+1个空指针，因此有$$n+1\ge 2(\lceil m/2 \rceil )^{h-1} \Rightarrow h \le log_{\lceil m/2\rceil }(\frac{n+1}{2})+1$$ 
- 方法2
![20201016202526](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201016202526.png)
Q5.
B+树(分块查找+B树)
-   每个节点最多m棵子树
-   非根节点至少有两颗子树，其他每个分支节点至少有$\lceil m/2 \rceil 棵子树$
-   节点子树个数与关键字个数相等
-   所有叶节点包含全部关键字及指向相应记录的指针，叶节点将关键字按大小顺序排列，并且相邻叶节点按大小顺序相互链接起来
-   所有分支节点中仅包含他的各个子节点中关键字的最大值及指向其子节点的指针

主要区别
- B+树中具有n个关键字的节点只含有n棵子树，在B树中，具有n个关键字的节点含有n+1棵子树
- B+树中，每个节点的关键字个数n的范围是$\lceil m/2\rceil \le n\le m(根结点：1\le n \le m) ：在B树中，每个节点的关键字个数n范围\lceil m/2 \rceil-1 \le n \le m-1 (根节点：1\le n \le m-1)$
- B+树中，叶节点包含信息，所有非叶节点仅起索引作用，非叶节点的每个索引项只含有对应子树的最大关键字和指向该子树的指针，不含有关键字对应记录的存储地址
- B+树中，叶节点包含了全部关键字，非叶节点中出现的关键字也会在叶节点中；B树上关键字不重复。
