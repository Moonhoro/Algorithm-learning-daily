1.  高精度计算

    1.  高精度计算一般指有大数参与的计算，但是这个问题一般只出现在c++中，因为C++中的int和long long均有位数限制，但是java和python均有大数字格式，所以没有该问题。
    2.  一般处理办法：将大整数每一位存到数组中，且一般从个位开始排（如123，在数组中应存为3 2 1，这样便于进位和退位计算），随后按照正常数学计算编程（注意进位退位等问题）。
    3.  下面是高精度加法、减法、高精度乘以低精度乘法以及高精度除以低精度除法思路及实现（注：此时假设A,B均为正数，乘法和除法时b为小数值）

-     高精度加法： 高精度加法的实现基于两个大整数相同位数的逐位相加，并考虑进位的情况。从个位开始，将对应位的数字相加，并将结果存储到一个新的数组中。如果相加的结果超过了10，就需要进位到下一位的运算。最后，需要注意处理可能出现的最高位的进位。

-     高精度减法： 高精度减法的实现通过从高位到低位，逐位进行减法运算，并考虑借位的情况。如果被减数小于减数，则需要借位。在借位的情况下，从高位借位，并将结果存储到一个新的数组中。最后，需要注意处理可能出现的多余的零。

-     高精度乘法： 高精度乘法是将一个大整数与一个小整数进行逐位相乘的运算。从个位开始，将大整数的每一位与小整数相乘，并考虑进位的情况。将相乘的结果逐位存储到一个新的数组中，并按照正常的数学计算规则进行进位。最后，需要注意处理可能出现的多余的零。

-     高精度除法： 高精度除法是将一个大整数除以一个小整数的运算。从最高位开始，逐位进行除法运算，并得到商和余数。将每一位的商逐位存储到一个新的数组中，并将余数传递到下一位的运算。最后，需要注意处理可能出现的多余的零。
    
此处为加法和减法的数据输入、输出。

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

此处为具体实现

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

此处为高精度乘以低精度，高精度除以低精度的输入、输出。

```
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

```

此处为具体实现

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
        reverse(C.begin(), C.end()); // 倒转数组，此处倒转是为了便于消除多余的0以及和乘法的输出形式统一
        while (C.size() > 1 && C.back() == 0)
        {
            C.pop_back();
        }
        // 去除多余的0
        return C;
    }

此处仍有一个问题，在CLion中当A值过大时，乘法仍会输出乱码，但是在vscode以及acwing中输出均正常，猜测是内存或者运行环境的问题，暂未查明。

这个问题应用范围比较窄，
