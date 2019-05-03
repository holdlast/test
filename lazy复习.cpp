#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define M 100000
struct node
{
    int left;
    int right;
    int sum;
    int lazy;
}t[M*4+5];
void build(int left,int right,int k)
{
    t[k].left=left;
    t[k].right=right;
    if(right==left)
    {
        t[k].lazy=1;//初始化lazy标记
        t[k].sum=1;//初始化物质价值
        return;
    }
    else
    {
        int mid=(right+left);
        build(left,mid,k<<1);
        build(mid+1,right,k<<1|1);
        t[k].sum=t[k<<1].sum+t[k<<1|1].sum;
        t[k].lazy=1;
    }
}
void update(int left,int right,int op,int k)//将a到b范围内的数全部换成op
{
    if(t[k].lazy==op) return;
    if(t[k].left>=left&&t[k].right<=right)
    {
        t[k].sum=(right-left+1)*op;//更新节点值
        t[k].lazy=op;
        return;
    }
    if(t[k].lazy)
    {
        int l1=t[k<<1].right-t[k].left+1;
        int l2=t[k<<1|1].right-t[k<<1|1].left+1;
        t[k<<1].sum=l1*t[k].lazy;
        t[k<<1|1].sum=l2*t[k].lazy;
        t[k<<1].lazy=t[k].lazy;
        t[k<<1|1].lazy=t[k].lazy;
        t[k].lazy=0;
    }
   // else  又错了，要注意啊
    //{
        int mid=(t[k].left+t[k].right)>>1;
        if(right<=mid)
            update(left,right,op,k<<1);
        if(left>mid)
            update(mid+1,right,op,k<<1|1);
        if(left<=mid&&right>=mid)//经过上方的筛选之后来到这一步
        {
            update(left,mid,op,k<<1);
            update(mid+1,right,op,k<<1|1);
        }
   // }
    else return;
    t[k].sum=t[k<<1].sum+t[k<<1|1].sum;
}
int main()
{
    int T;
    int a,b,c;
    int kp=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        build(1,n,1);
        while(m--)
        {
            scanf("%d %d %d",&a,&b,&c);
            update(a,b,c,1);//将a-b范围内的数改为c;从根节点开始
        }
        printf("Case %d: The total value of the hook is %d.\n",++kp,t[1].maxn);
    }
    //懒惰标记
    return 0;    
}