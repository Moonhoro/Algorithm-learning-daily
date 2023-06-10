#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int N = 100010;

int h[N], size;
// ph[k]是第k个插入的点在堆中的位置 hp[k]是堆中位置k的点是第几个插入的
int ph[N], hp[N];
// 为了维护ph和hp的关系，交换两个点的时候，需要交换ph和hp
void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}
void down(int u)
{
    int t = u;
    if (u * 2 <= size && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= size && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u / 2] > h[u])
    {
        heap_swap(u / 2, u);
        u /= 2;
    }
}
int main()
{
    int n, m = 0;
    cin >> n;
    while (n--)
    {
        char op[10];
        int k, x;
        cin >> op;
        // 插入操作
        if (!strcmp(op, "I"))
        {
            cin >> x;
            size++;
            m++;
            ph[m] = size;
            hp[size] = m;
            h[size] = x;
            up(size);
        }
        // 查询操作
        else if (!strcmp(op, "PM"))
        {
            cout << h[1] << endl;
        }
        // 删除操作
        else if (!strcmp(op, "DM"))
        {
            heap_swap(1, size);
            size--;
            down(1);
        }
        // 删除第k个插入的点
        else if (!strcmp(op, "D"))
        {
            cin >> k;
            k = ph[k];
            heap_swap(k, size);
            size--;
            down(k), up(k);
        }
        // 修改第k个插入的点的值
        else
        {
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }
}