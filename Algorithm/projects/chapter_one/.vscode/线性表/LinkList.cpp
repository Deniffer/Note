                //C++形式的链表的插入,遍历输出，链表倒序等操作
#include<iostream>
using namespace std;
//节点类
class Node{
public:
    int data;       //数据域
    Node *next;     //指向下一个节点的指针
    Node(int _data){  //显式构造函数,每次对新声明的节点类的对象进行初始化
        data = _data;
        next = NULL;
    }
};
//链表类
class LinkList{
public:
    LinkList (){
        head = NULL;    //显式构造函数,每次对新声明的链表类进行初始化,即表示
                        //创建一个新的"空"链表,链表中只有头指针,并且头指针的值为NULL,表示头指针
                        //指向的部分也无任何数据元素
    }
    void Insert(Node *node,int position);
    void Output();
private:
    Node *head;    //设置为类的私有成员,只有通过类的成员函数才能访问
};
void LinkList::Insert(Node *node,int position){     //position表示要插入的位置
            if(head==NULL){              //在头指针为空指针的情况下,链表是空的,无任何数据元素
                                        //包括头结点在内.因此呢,我们在插入节点的时候,如果发现头结点为空指针
                head = node;             //的情况,那么这就意味着我们插入的这个节点要将其设置为头结点,
                return;                 //而后一一插入的节点则接在该节点的后方,并且通过这个节点从头开始遍历
                                        //能够遍历到链表中所有的数据元素
 
 
            }
            if(position==0){      //插入的是第0个位置,为了方便，我们暂且规定头结点为第0个节点
                                  //那么如果插入的是第0个位置的话,说明插入的节点要成为新的头结点
                                  //而不管之前有没有头结点
            node -> next = head;
            head = node;          //完成头结点的更新,表示头结点现在是node节点
            return;
 
            }
            Node *current_node = head;     //从头结点开始遍历插入的位置
            int i = 0;                    //表示已经遍历过的节点数目
            while(current_node -> next != NULL && i < position-1){
                                                                //不断寻找要插入的位置的前一个位置,然后插入在这个位置的节点与下一个位置的节点之间
                current_node = current_node -> next;            //不断更新current_node的值
                i++;
            }
            if(i == position-1){            //找到了插入的位置，先更新插入节点的指针域,记录当前遍历到的位置的下一个节点
                                            //然后再接上前面的节点
 
                node -> next = current_node -> next;
                current_node -> next = node;
            }
}
void LinkList::Output(){
            if(head==NULL){
                return;       //链表为空链表,无任何数据元素可输出
            }
            Node *current_node = head;     //从头结点开始遍历
            while(current_node!=NULL){
                cout << current_node -> data << " ";
                current_node = current_node -> next;
            }
            cout << endl;
}
int main(){
    LinkList linkList;
    for(int i = 1;i <= 10;i++){
        Node *node = new Node(i);      //用new给链表的每一个节点开辟空间
        linkList.Insert(node,i-1);     //调用成员函数
    }
    linkList.Output();
    return 0;
}


