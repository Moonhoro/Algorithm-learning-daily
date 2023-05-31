#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> mul(vector<int> &A, int b);
vector<int> div(vector<int> &A, int b, int &r);

int main()
{
    string a;
    vector<int> A;
    int b;
    cin >> a >> b;

    for (int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(a[i] - '0');
    }
    // 此处倒着把数字存入vector，方便后面的计算
    vector<int> result;
    result = mul(A, b);
    cout << "A*b=";
    for (int i = result.size() - 1; i >= 0; i--)
    {
        cout << result[i];
    }
    cout << endl;
    int r = 0;
    result = div(A, b, r);
    cout << "A/b=";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
    cout << endl;
    cout << "余数为" << r;
}

vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i++)
    {
        t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0)
    {
        C.pop_back();
    }

    // 消除多余的0
    return C;
}
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;

    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end()); // 倒转数组
    while (C.size() > 1 && C.back() == 0)
    {
        C.pop_back();
    }
    // 去除多余的0
    return C;
}