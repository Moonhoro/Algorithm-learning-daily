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

    // 创建原始二维容器 v，并读取输入整数
    vector<vector<int>> v(n, vector<int>(n));
    cout << "输入整数" << endl;
    int t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> t;
            v[i][j] = t;
        }
    }

    // 创建前缀和容器 S，大小为 (n+1) x (n+1)
    vector<vector<int>> S(n + 1, vector<int>(n + 1));

    // 计算前缀和
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // 根据公式计算前缀和
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + v[i - 1][j - 1];
        }
    }

    // 计算求和范围
    while (m--)
    {
        cout << "输入求和的范围" << endl;
        int x_1, y_1, x_2, y_2;
        cin >> x_1 >> y_1 >> x_2 >> y_2;

        // 根据前缀和计算矩形区域的和
        int sum = S[x_2][y_2] - S[x_1 - 1][y_2] - S[x_2][y_1 - 1] + S[x_1 - 1][y_1 - 1];
        cout << sum << endl;
    }

    return 0;
}
