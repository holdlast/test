//一直卡在这里，一开始转向数组写了8个 一直输出3，就这样过了3天  最后在第12次试验后。。。。。。。（感动），终于好了，如果按照8个方向来算的话，确实是8步，我写的没错！
//哦 正确答案是7
//走迷宫问题，第一行输入n，m表示一个n行m列的数组；
//第二行输入n 行m列个数字 0代表可通过,1代表障碍
//第三行 输入起点的横纵坐标和终点的横纵坐标
//输出到达终点的最短路径
#include<iostream>
#include<cstdio>
#include<queue>
#define maxn 10000
int book[maxn][maxn]={0};
int p[maxn][maxn]={0};
using namespace std;
struct node
{
	int x;
	int y;
	int s;
};
int H[4][2]=//转向数组 
{
	{-1,0},{0,-1},{0,1},{1,0},//枚举四个方向 
};
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>p[i][j];
		}
	}
	struct node start,end,temp,ans;
	cin>>start.x>>start.y>>end.x>>end.y;
	queue<struct node> q;
	while(!q.empty())
		q.pop();//清空队列 
	start.s=0;
	q.push(start);
	book[start.x][start.y]=1;//标记
	int flag=0;
	while(!q.empty())
	{
		ans=q.front();//取首元素作为初始元素 
		for(int j=0;j<4;j++)
		{
			temp.x=ans.x+H[j][0];
			temp.y=ans.y+H[j][1];
			if(temp.x>=0&&temp.y>=0&&temp.x<=n&&temp.y<=m&&p[temp.x][temp.y]!=1&&book[temp.x][temp.y]!=1)//判定是否符合条件
			{
				book[temp.x][temp.y]=1;//标记已经走过
				temp.s=ans.s+1;
				q.push(temp);//入队： 
			}
			//判断是否到达终点
			if(temp.x==end.x&&temp.y==end.y)
			{
				flag=1;
				break;
			} 
		}
		if(flag==1)
		{
			cout<<"输出最短路径："<<temp.s<<endl;
			break;
		}
		else
		{
			q.pop();	
		}
	} 
	return 0;				 
} 
