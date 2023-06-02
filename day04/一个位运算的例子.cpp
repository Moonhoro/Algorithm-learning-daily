// 给定长度为n的数列，求出每个数的二进制中1的个数
#include <iostream>

using namespace std;

int lowbit(int x)
{
    return x & (-x);
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;

        int ans = 0;
        while (x)
        {
            cout << "lowbit:" << lowbit(x) << endl;
            x -= lowbit(x);
            ans++;
            cout << "x:" << x << endl;
        }
        cout << "ans:" << ans << "" << endl;
    }
}