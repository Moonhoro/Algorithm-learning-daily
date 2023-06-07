#include<iostream>

using namespace std;

const int N = 100010;
    //head表示头节点的下标
    //e[i]表示节点i的值
    //ne[i]表示节点i的next指针是多少
    //idx表示当前用到了哪个点
    int head,e[N],ne[N],idx;

    
//初始化
void init()
{
    //0号点既是头节点，又是单链表的最后一个点
    head = -1;
    idx = 0;
}

//将x插入到头节点
void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

//将x插入到下标为k的点后面
void add(int k,int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

//删除下标为k的点后面的点

void remove(int k)
{
    ne[k] = ne[ne[k]];
}