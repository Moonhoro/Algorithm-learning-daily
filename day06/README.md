1. 离散化
	1. 当值域远大于数组长度，同时又需要以值域为下标时，将其值域映射
	2. 问题：
		1. 可能有重复元素，需要去重
		2. 如何算出离散化后的值（二分）
		
```
vector<int> a;//储存所有待离散化的值
sort(a.begin(),a.end());//将所有值排序
a.erase(unique(a.begin(),a.end()),a.end());//去重
//二分法求出x对应的离散化的值
int find(int x)//找到第一个大于等于x的位置
{
int l=0,r=a.size()-1;
while(l<r)
{
int mid=l+r>>1;
if(a[mid]>=x)r=mid;
else l=mid+1;
}
return r;
//return r+1;
//这个是映射到1，2，...到n
}
```

忙 继续摸鱼
