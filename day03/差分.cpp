#include <iostream>
#include <vector>

using namespace std;

// 插入函数
void insert(vector<int> &v, int l, int r, int c)
{
    v[l] += c;
    v[r + 1] -= c;
}

int main()
{
    int n, m, t;
    cout << "输入整数的个数:" << endl;
    cin >> n;
    cout << "输入插入次数" << endl;
    cin >> m;

    vector<int> v;
    cout << "输入整数" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        v.push_back(t);
    }

    vector<int> S(n);

    for (int i = 0; i <= n; i++)
    {
        insert(S, i, i, v[i]); // 利用插入对差分赋值
    }

    while (m--)
    {
        int l, r, c;
        cout << "输入插入的范围" << endl;
        cin >> l >> r;
        cout << "输入插入的值" << endl;
        cin >> c;
        insert(S, l - 1, r - 1, c);
    }

    for (int i = 1; i < n; i++)
    {
        S[i] += S[i - 1]; // 利用差分求前缀和
    }

    cout << "插入后的数组为：" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << S[i] << " ";
    }

    return 0;
}
