#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;


long long t,res=0;
long long n,b;

int main()
{
    scanf("%lld %lld",&n,&t);
long long t1,t2,b2;//t1为前一天的时间，t2为当天的时间，b2为当天补充的干草
scanf("%lld %lld",&t1,&b);//先读入第一天
for(int i=1;i<n;i++)
{
scanf("%lld",&t2);
if(t2-t1>=b)//如果天数间隔大于干草，那么干草被吃完
{
res+=b;//所以此处直接加上干草
scanf("%lld",&b);//所以此处直接读入下一天的干草
}
else//如果天数间隔小于干草，那么干草有剩下
{
res+=t2-t1;
b-=t2-t1;//算出剩下的干草
scanf("%lld",&b2);//读入下一天的干草
b+=b2;//加上下一天的干草
}
t1=t2;//更新前一天的时间
}
res+=min(t-t1+1,b);//处理最后一天
cout<<res;
}