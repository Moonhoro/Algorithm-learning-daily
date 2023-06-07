// 找到每个数左端最小的数
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int stk[N], tt;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        while (tt && stk[tt] >= x)
            tt--;
        if (tt)
            cout << stk[tt] << endl;
        else
            cout << "-1 " << endl;
        stk[++tt] = x;
    }
}