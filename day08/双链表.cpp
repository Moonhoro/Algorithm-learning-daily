#include<iostream>

using namespace std;

const int N=100010;
//e[i]表示节点i的值
//l[i]表示节点i的左指针是多少
//r[i]表示节点i的右指针是多少
//idx表示当前用到了哪个点
int e[N],l[N],r[N],idx;

//初始化
void init()
{
    r[0]=1;
    l[1]=0;
idx=2;
}


//在节点k的右边插入一个数x
void add(int k,int x)
{
    e[idx]=x;
    r[idx]=r[k];
    l[idx]=k;
    l[r[k]]=idx;
    r[k]=idx;
    idx++;
}
//在k的左边插入可以直接调用add(l[k],x)


//删除节点k
void remove(int k)
{
    r[l[k]]=r[k];
    l[r[k]]=l[k];
}