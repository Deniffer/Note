#### Q1. 什么是树
#### Q2. 度的概念/什么是树的度
#### Q3. 为什么结点数=总度数+1 
#### Q4. 度为m/m叉树的区别
#### Q5. 度为m的树第i层最多有多少个节点
#### Q6. 高度为h的m叉树节点最多有？
#### Q7. 具有n个节点的m叉树的最小高度为$log_m(n(m-1)-1)$
#### Q8. 满二叉树的定义/性质
#### Q9. 什么是二叉排序树
#### Q10. 什么是平衡二叉树
#### Q11. 如何推出$n_0=n_2+1$
#### Q12. 完全二叉树的高度范围
#### Q13. 树的遍历
#### Q14. 树的顺序存储/链式存储








Q1.
树是n(n>=0)个节点的有限集。当n=0的时候称为空树，在任意一棵非空树应满足
- 有且仅有一个特定的称为跟的节点
- 当n>1时，其余节点可以分为m(m>0)个互不相交的有限集$T_1,T_2,T_3,\cdots,其中每个集合本身又是一棵树，并且称为根的子树$

Q2.
树中孩子的个数称为该节点的度，树中节点的最大度数称为树的度

Q3.
以归纳的思想来看，叶子节点度为0可以归纳给父节点，逐层网上递推发现只有根节点无代表(根结点的度代表其左右孩子)，因此$$结点数=总度数+1 \qquad (1代表了根节点)$$

Q4.
![20201008211643](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201008211643.png)


Q5. 
度为m的树，每层最多可以有$m^{i-1}$个节点
![20201008211910](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201008211910.png)

Q6.
利用等比数列求和的知识 最终结果是$\frac{m^h-1}{m-1}$个节点

Q7. 
思路：最小高度意味着是每一个节点尽可能有更多的孩子，也就是满m叉树，因此满足
![20201008214151](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201008214151.png)


Q8. 
满二叉树：高度为h，且含有$2^h-1$个节点的二叉树
完全二叉树： 高度为h，当且仅当每个节点都与高度为h的满二叉树编号为1~n的节点一一对应。
区别：
- 满二叉树不存在度为1的节点，完全二叉树只存在于一个度为1的节点
- 满二叉树只在最后一层有叶子节点，完全二叉树在最后两层可能有叶子节点
- 完全二叉树和满二叉树都符合编号规范
![20201009094913](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201009094913.png)

Q9.
左子树上的所有关键字都小于根节点的关键字，右子树上的所有关键都大于根节点上的关键字。(递归地，左右子树也满足上述性质
)

Q10.
树上任一结点的左子树和右子树的深度之查不超过1(平衡二叉树有更好的搜索效率)


Q11.
联立$n=n_0+n_1+n_2,
\newline n=n_1+2n_2+1 \qquad(结点数=总度数+1)$

Q12.
h为向上取整，方法参考m叉树的高度求法

![20201009101730](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201009101730.png)

Q13.
先序遍历： 根左右(NLR)
中序遍历： 左根右(LNR)
后序遍历： 左右根(LRN)

Q14.
- 双亲表示法
优点：顺序存储查找双亲简单，查找指定节点的孩子则需从根节点开始遍历
```C++
#define MAX_TREE_SIZE 100
typedef struct{
    ElemType data; //结点数据
    int parent; //双亲位置域，类似指针，实则为数组下标
}PTNode;
typedef struct{
    PTNode nodes[MAX_TREE_SIZE]; //双亲表示
    int n; //结点数
}PTree;
```

- 孩子表示法(顺序+链式存储)
 ![20201011210734](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201011210734.png)

 - 孩子兄弟表示法（链式存储）森林转换成二叉树
 ```C++
 typedef struct CSNode{
     ElemType data;
     struct CSNode *firstchild,*nextsibling;//第一个孩子和右兄弟结点
 }
 ```
 ![20201011211123](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201011211123.png)

 - 森林和二叉树的转换
 ![20201011211325](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201011211325.png)