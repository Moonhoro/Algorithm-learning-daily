//给定一个整数n，将数组1~n按照字典序排列，输出排列后的数组
#include <iostream>

using namespace std;

const int N = 10;
bool st[N];

int n;
int path[N];

void dfs(int u)
{
if(u == n)
{
for(int i = 0; i < n; i++) cout << path[i] << ' ';
cout << endl;
return;
}
for(int i = 1; i <= n; i++)
{
if(!st[i])
{
path[u] = i;
st[i] = true;
dfs(u + 1);
st[i] = false;
}

}
}
int main()
{
    cin >> n;
    dfs(0);
}