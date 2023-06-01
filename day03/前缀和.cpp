#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cout << "输入整数的个数:" << endl;
    cin >> n;
    cout << "输入求和次数" << endl;
    cin >> m;
    vector<int> v;
    int t;
    cout << "输入整数" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        v.push_back(t);
    }
    vector<int> S;
    t = 0;
    for (int i = 0; i <= n; i++)
    {
        S.push_back(t);
        t += v[i];
    }
    while (m--)
    {
        cout << "输入求和的范围" << endl;
        int l, r;
        cin >> l >> r;
        cout << S[r] - S[l - 1] << endl;
    }
}