#include <cstdio>
#include <iostream>
#include <fstream>
#include"class.h"

int main()
{
	CStudent S[101];
	CTeacther T[21];
	CProfessor P[5];
	CDean D;
	string name, tel, addr, score, wage, coursename, book, graduate, title;
	int i = 0;
	CPerson *p=S; 
	ifstream Sout("xuesheng.txt");
	for (int j = 0; j < 100; j++)
	{
		Sout >> name >> tel >> addr >> score;
		S[j].get_CStudent(name, tel, addr, score); 
	}
	ifstream Tout("laoshi.txt");
	for (int j = 0; j < 20; j++)
	{
		Tout >> name >> tel >> addr >> wage >> coursename;
		T[j].get_CTeacther(name, tel, addr, wage, coursename);
	}
	ifstream Pout("jiaoshou.txt");
	for (int j = 0; j < 4; j++)
	{
		Pout >> name >> tel >> addr >> wage >> coursename >> book >> graduate;
		P[j].get_CProfessor(name, tel, addr, coursename, wage, book, graduate);
	} 
	ifstream Dout("xizhuren.txt");
	Dout >> name >> tel >> addr >> wage >> coursename >> book >> graduate >> title;
	D.get_CDean(name, tel, addr, coursename, wage, book, graduate, title);
	cout<<"    ***************读入文件数据成功***************"<<endl;
	cout << endl;
	department UI;
	while(1)
	{
		UI.first();
		while(UI.get())
		{
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~输入格式不符合要求~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<"    	*********************请重新输入！！*********************"<<endl; 
		}
		UI.display(&S[0],&T[0],&P[0],&D);
		cout<<"            是否想要继续输入？"<<endl;//暂时先这样安排
		cout<<"            [1]想~~~~~"<<endl;
		cout<<"            [2]不想！！！！！"<<endl;
		if(UI.end())//以外数字需要处理 
			break;	
	} 
	cout<<"            已退出学校员工管理系统！"<<endl; 
	return 0;
}

