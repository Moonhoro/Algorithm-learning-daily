#include<iostream>

using namespace std;

const int N = 100010;

int stk[N],tt;

//输入
void push(int x)
{
    stk[++tt] = x;
}


//输出
void pop()
{
    tt--;
}

//判断栈是否为空
bool empty()
{
    if(tt>0)
        return false;
    else
        return true;
}

//输出栈顶元素
int query()
{
    return stk[tt];
}