// 开放地址法实现哈希表
#include <iostream>
#include <cstring>
using namespace std;

const int N = 200003;
int h[N];
int null = 0x3f3f3f3f; // 一个极大的数 约定俗成的空值

int find(int x)
{
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x) // 如果不是空值且不是要找的值
    {
        k++;
        if (k == N)
            k = 0; // 如果到了末尾就从头开始
    }
    return k;
}

int main()
{
    int n;
    cin >> n;
    memset(h, 0x3f, sizeof h); // 将所有的值都初始化为null
    while (n--)
    {
        char op[2];
        int x;
        cin >> op >> x;
        int k = find(x);
        if (op[0] == 'I')
        {
            h[k] = x;
        }
        else
        {
            if (h[k] != null)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}