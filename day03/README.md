1.  基本前缀和
    *   前缀和数组$S_i=a_1+a_2+...+a_i$（$S_0=0$）
    *   前缀和的求法实现
    *   前缀和的作用：快速算出一段数的和
    *   基本实现：

```#include <iostream>
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
```

2.  二维前缀和
    *   相比一维前缀和仅仅多了一维具体方法类似
    *   求某一段和变成了$S_(x_2y_2)-S_(x_1y_2)-S_(x_2y_1)+S_(x_1y_1)$  这个关系可以通过画图得出
    *   基本实现：

```

\#include <iostream>
\#include <vector>

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

```

3.  基本差分
    *   前缀和的逆运算
    *   构造$b_1,b_2...b_n$使得$a_1,a_2...a_n$为其前缀和
    *   基本思路$b_1=a_1,b_2=a_2-a_1,b_3=a_3-a_2...$
    *   此处也可以看成n次插入操作，例如$b_1$为在1到2之间插入$a_1$ 此时$b_1=a_1 b_2=-a_1$之后在2到3之间插入$a_2$ 此时$b_2=a_2-a_1$以此类推即可
    *   插入操作：在l和r之间都加上c时$b_l+c$  $b_r-c$
    *   作用：用O(1)的时间对原数组某一段同时加上或减去一个数
    *   基本实现：

```

\#include <iostream>
\#include <vector>

using namespace std;

// 插入函数
void insert(vector<int> \&v, int l, int r, int c)
{
v\[l] += c;
v\[r + 1] -= c;
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

```

4.  二维差分
    *   和一维差分类似
    *   插入操作：在$x_2y_2和x_1y_1$之间加上c时 $b_(x_1y_1)+=c$  $b_(x_1y_2)-=c$   $b_(x_2y_1)-=c$   $b_(x_2y_2)+=c$ (同样可以由画图得出)
    *   构造方式和一维相同
    *   基本实现：（甚至用容器跑不起来，迫不得已用数组实现的）

```

\#include <iostream>
\#include <vector>

using namespace std;

int a\[100]\[100], b\[100]\[100];
// 此处为插入函数
void insert(int x\_1, int y\_1, int x\_2, int y\_2, int c)
{
b\[x\_1]\[y\_1] += c;
b\[x\_2 + 1]\[y\_2 + 1] += c;
b\[x\_1]\[y\_2 + 1] -= c;
b\[x\_2 + 1]\[y\_1] -= c;
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
cin >> a\[i]\[j];
}
}
for (int i = 1; i <= n; i++)
{
for (int j = 1; j <= n; j++)
{
insert(i, j, i, j, a\[i]\[j]);
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

```
