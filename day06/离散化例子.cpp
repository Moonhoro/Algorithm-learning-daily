#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int N=300010;
int n,m;
int ax[N],s[N];
vector<int> a;
typedef pair<int,int> PII;
vector<PII> add,query;
int find(int x)
{
    int l=0,r=a.size()-1;
    while(l<r)
    {
        int mid=l+r>>1;
        if(a[mid]>=x) r=mid;
        else l=mid+1;
    }
    return l+1;
}

int main()
{
cin>>n>>m;
for(int i=0;i<n;i++)
{
    int x,c;
    cin>>x>>c;
    add.push_back({x,c});
    a.push_back(x);
}
for(int i=0;i<m;i++)
{
    int l,r;
    cin>>l>>r;
    query.push_back({l,r});
    a.push_back(l);
    a.push_back(r);
}
sort(a.begin(),a.end());
a.erase(unique(a.begin(),a.end()),a.end());
for(auto item:add)
{
    int x=find(item.first);
    ax[x]+=item.second;
}
//完成映射
for(int i=1;i<=a.size();i++)
{
    s[i]=s[i-1]+ax[i];
}
//前缀和
for(auto item:query)
{
    int l=find(item.first),r=find(item.second);
    cout<<s[r]-s[l-1]<<endl;
}
}