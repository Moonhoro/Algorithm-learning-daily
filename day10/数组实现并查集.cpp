#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int p[N];

int find(int x) // 返回x的父节点且压缩路径
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        p[i] = i;

    while (m--)
    {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (op[0] == 'M')
            p[find(a)] = find(b);
        else
        {
            if (find(a) == find(b))
                puts("Yes");
            else
                puts("No");
        }
    }
}