#### Q1. 什么是线索二叉树
#### Q2. 如何构造线索/区分是左右子树还是线索
#### Q3. 先序线索化所面临的问题
#### Q4. 线索树找前驱后继问题
#### Q5. 二叉树的顺序存储/链式存储
#### Q6. 二叉排序树(BST,Binary Search Tree)
#### Q7. 如何求ASL(Average Search Length) ,成功和失败的情况
#### Q8. 平衡二叉树的概念
#### Q9. 平衡二叉树的最少结点数
Q1.
利用n+1个空指针来存放其指向前驱或后继的的指针。意义：加快查找结点前驱和后继的速度

Q2.
```C++
typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild,*rchild;//左右孩子指针
    int ltag,rtag; //指明是指针指向左右子树 还是前驱或后继,tag=1代表线索化
}ThreadNode,*ThreadTree;
```
![20201010200327](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201010200327.png)
![20201010200451](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201010200451.png)
![20201010200551](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201010200551.png)

Q3.
![20201010201022](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201010201022.png)


Q4.
- 中序线索找后继
![20201010201610](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201010201610.png)
- 中序线索找前驱
![20201010201715](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201010201715.png)
- 先序线索找前驱
找不到，除非是三叉链表
![20201010201854](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201010201854.png)
- 先序线索找后继
![20201010205926](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201010205926.png)
- 后序线索找后继
![20201010205809](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201010205809.png)
- 后序线索找后继
![20201010205718](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201010205718.png)


Q5.
```C++
#define MaxSize 100
struct TreeNode{
    Elemtype value;
    bool isEmpty;
}
TreeNode t[MaxSize];
```
![20201009140623](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201009140623.png)
![20201009140705](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201009140705.png)

```C++
struct Elemtype {
    int value;
}
typedef struct BiTNode{
    ElemType data;
    struct BiTNode  *lchild ,*rchild; //pointer to lchild && rchild
}BiTNode,*BiTree;
```
![20201009141151](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201009141151.png)

Q6.
- 查找/插入/构造
```C++
typedef struct BSTNode{
    int key;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

BSTNode *BST_Search(BSTree T,int key){
    while(T!=NULL&&key!=T->key){//树空或者等于根节点的值，结束循环
        if(key<T->key) T=T->lchild;//小于，则在左子树
        else T=T->rchild;
    }
    return T;
}
// 递归实现插入操作
int BST_Insert(BSTree &T,int k){
if (T==NULL){
    T=(BSTree)malloc(sizeof(BSTNode));
    T->key=k;
    T->lchild=T->rchild=NULL;
    return 1; //插入成功
}
else if(k==T->key) //树中不允许相同关键字的值
    return 0;
}
else if(k<T->key)
    return BST_Insert(T->lchild,k);
else
    reuturn BST_Insert(T->rchild,l);

void Creat_BST(BSTree &T,int str[],int n){
    T=NULL;
    while(i<n){
        BST_Insert(T,str[i]);//依次将每个关键字插入到二叉排序树
        i++
    }
}
```

Q7.
![20201011214654](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201011214654.png)
![20201011214806](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201011214806.png)


Q8. 
- 平衡二叉树结点
```C++
typedef struct AVLNode{
    int key; //
    int balance; // 平衡因子
    struct AVLNode  *lchild,*rchild;
}AVLNode ,*AVLTree;
```
- 找到最小不平衡子树
    - LL/RR
    ![20201014120256](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201014120256.png)
    - LR/RL 关键是找到排序关系


Q9.
![20201014124253](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20201014124253.png)