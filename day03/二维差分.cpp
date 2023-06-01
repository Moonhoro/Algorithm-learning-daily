#include <iostream>
#include <vector>

using namespace std;

int a[100][100], b[100][100];
// 此处为插入函数
void insert(int x_1, int y_1, int x_2, int y_2, int c)
{
    b[x_1][y_1] += c;
    b[x_2 + 1][y_2 + 1] += c;
    b[x_1][y_2 + 1] -= c;
    b[x_2 + 1][y_1] -= c;
}

int main()
{
    int n, m;
    cout << "输入整数的个数：" << endl;
    cin >> n;
    cout << "输入插入次数：" << endl;
    cin >> m;
    cout << "输入整数：" << endl;
    int t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            insert(i, j, i, j, a[i][j]);
        }
    }

    while (m--)
    {
        int x_1, y_1, x_2, y_2, c;
        cout << "输入插入的范围：" << endl;
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        cout << "输入插入的值：" << endl;
        cin >> c;
        insert(x_1, y_1, x_2, y_2, c);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // 根据公式计算前缀和
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
        }
    }

    cout << "插入后的数组为：" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
