#include <iostream>

using namespace std;

const int N = 100010;
int q[N], hh, tt = -1;

// 输入
void push(int x)
{
    q[++tt] = x;
}

// 输出
void pop()
{
    hh++;
}

// 判断队列是否为空
bool empty()
{
    if (hh <= tt)
        return false;
    else
        return true;
}
// 输出队头元素
int query()
{
    return q[hh];
}