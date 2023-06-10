// 拉链法实现哈希表
#include <iostream>
#include <cstring>
using namespace std;

const int N = 100003;
// h为哈希表,e为链表值，ne为链表的next值
int h[N], e[N], ne[N], idx;

void insert(int x)
{
    int k = (x % N + N) % N; // 使余数为正数
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
    {
        if (e[i] == x)
            return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    memset(h, -1, sizeof h);
    while (n--)
    {
        char op[2];
        int x;
        cin >> op >> x;

        if (op[0] == 'I')
        {
            insert(x);
        }
        else
        {
            if (find(x))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}