#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B);
bool cmp(vector<int> &A, vector<int> &B);
vector<int> sub(vector<int> &A, vector<int> &B);

int main()
{
    string a, b;
    vector<int> A, B;

    cin >> a >> b;

    for (int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(a[i] - '0');
    }
    for (int i = b.size() - 1; i >= 0; i--)
    {
        B.push_back(b[i] - '0');
    }
    // 此处倒着把数字存入vector，方便后面的计算
    vector<int> result;

    result = add(A, B);

    cout << "A+B=";
    for (int i = result.size() - 1; i >= 0; i--)
    {
        cout << result[i];
    }
    cout << endl;
    // 上方为加法实现的输出
    if (!cmp(A, B))
    // 判断A,B大小来确定谁减谁，以及是否加负号
    {
        result = sub(B, A);
        cout << "A-B=";
        cout << "-";
        for (int i = result.size() - 1; i >= 0; i--)
        {
            cout << result[i];
        }
    }
    else
    {
        result = sub(A, B);
        cout << "A-B=";
        for (int i = result.size() - 1; i >= 0; i--)
        {
            cout << result[i];
        }
    }
    // 上方为减法实现的输出
}
vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++)
    {
        if (i < A.size())
            t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t)
        C.push_back(1);
    return C;
}
// 判断A是否大于B
bool cmp(vector<int> &A, vector<int> &B)
{
    if (A.size() != B.size())
        return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--)
    {
        if (A[i] != B[i])
            return A[i] > B[i];
    }
    return true;
}
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;

    for (int i = 0, t = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if (i < B.size())
            t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0)
            t = 1;
        else
            t = 0;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    // 消除多余的0
    return C;
}