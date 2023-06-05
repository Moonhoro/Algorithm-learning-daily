#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int> PII;
vector<PII> v; 

void merge(vector<PII> &v)
{
    sort(v.begin(),v.end());
    int mind=-2e9;
    int maxd=-2e9;
    vector<PII> res;
    for(auto x:v)
    {
        if(maxd<x.first)//处理情况三，不相交
        {
if(mind!=-2e9)res.push_back({mind,maxd});//保证第一次进入循环时不会将mind=-2e9,maxd=-2e9加入res
mind=x.first;
maxd=x.second;
        }
        else//即第一、二种情况 完全包含或者部分包含
        {
            maxd=max(maxd,x.second);
        }
    }
    if(maxd!=-2e9)res.push_back({mind,maxd});//处理最后一组区间，如果没有数据则无需更新
    v=res;
}

int main()
{
    int n;
    cin>>n;

for(int i=0;i<n;i++)
    {
int l,r;
cin>>l>>r;
v.push_back({l,r});
    }
    merge(v);
    cout<<v.size()<<endl;
}