#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
#include"class.h"
void CPerson::meet()
{
	cout<<name;//
}
void CStudent::meet()
{
	CPerson::meet();
}
void CTeacher::meet()
{
	CPerson::meet();
}
void CProfessor::meet()
{
	CPerson::meet();
}
void CDean::meet()
{
	CPerson::meet();
}
void department::meet(int sn,int tn,int pn,int dn)//给见面下一个定义就是在所有文件都已经被读取完的情况下 打印出所有的人名 
{
	cout<<"\n"<<"学生"<<endl;
	CStudent *p_s=new CStudent;
	p_s=shead; 
	for(int i=0;i<sn;i++)
	{
		p_s=p_s->snext;
		cout<<setw(15);
		p_s->meet();
		if(i%10==0)
		cout<<endl;
	}
	
	cout<<"\n"<<"老师"<<endl;
	CTeacher *p_t=new CTeacher;
	p_t=thead;
	for(int i=0;i<tn;i++)
	{
		p_t=p_t->tnext;
		cout<<setw(15);
		p_t->meet();
		if(i%10==0)
		cout<<endl;
	}
	CProfessor *p_p=new CProfessor;
	cout<<"\n"<<"教授"<<endl; 
	p_p=phead;
	for(int i=0;i<pn;i++)
	{
		p_p=p_p->pnext;
		cout<<setw(15);
		p_p->meet();
		if(i%10==0)
		cout<<endl;
	}
	cout<<"\n"<<"系主任"<<endl;
	CDean *p_d=new CDean;
	p_d=dhead;
	for(int i=0;i<dn;i++)
	{
		p_d=p_d->dnext;
		cout<<setw(15);
		p_d->meet();
		if(i%10==0)
		cout<<endl;
	} 
}
void CProfessor::show()
{
	CTeacher::show();
	cout <<setw(20)<< book <<setw(15)<< graduate;
}
void CTeacher::show()
{
	CPerson::show();
	cout <<setw(15)<< coursename <<setw(15)<< wage;
}
void CPerson::show()
{
	cout<<setw(15)<<name<<setw(15)<<tel<<setw(15)<<address;
}
void CStudent::show()
{
	CPerson::show();
	cout<<setw(15)<<score;
} 
void CDean::show()
{
	CProfessor::show();
	cout<<setw(15)<<title;
	
}
department::department()
{
	CTeacher *teacher= new CTeacher();//调用自己的构造函数 
	CProfessor *professor= new CProfessor();//同上
	CStudent *student= new CStudent();
	CDean *dean= new CDean();
	//之后再有其他类再继续接着这里写 
	shead=student;
	dhead=dean;
	thead=teacher;
	phead=professor; 
}


//这里做一次测试 
int department::read_s()
{
	shead->snext=NULL;
	string name,address,wage,score;
	ifstream sout("xuesheng.txt");
	int sum=0;
	//for(int i=0;i<n;i++)
	while(!sout.eof())
	{
		sum++;
		sout>>name>>address>>wage>>score;
		CStudent *p=new CStudent(name,address,wage,score);
		p->snext=shead->snext;
		shead->snext=p;
	}
	
	sout.close();
	return sum;
}
int department::read_d()
{
	dhead->dnext=NULL;
	string name,tel,address,wage,coursename,book,graduate,title;
	ifstream dout("xizhuren.txt");
	int sum=0;
	//for(int i=0;i<n;i++)
	while(!dout.eof())
	{
		sum++;
		dout>>name>>tel>>address>>wage>>coursename>>book>>graduate>>title;
		CDean *p= new CDean(name,tel,address,wage,coursename,book,graduate,title);
		p->dnext=dhead->dnext;
		dhead->dnext=p;
	}
	dout.close();
	return sum;
}
int department::read_t()
{
	thead->tnext=NULL;//thead本身是没有储存数据的  他指向的下一个单位是有数据存储的 
	string name,tel,address,wage,coursename;//待定 
	ifstream tout("laoshi.txt");
	int sum=0;
	//for(int i=0;i<n;i++)
	while(!tout.eof())
	{
		sum++;
		tout>>name>>tel>>address>>wage>>coursename;
		CTeacher *p = new CTeacher(name,tel,address,wage,coursename);
		p->tnext=thead->tnext;
		thead->tnext=p;
	}
	//那么到最后  还是p->next没有指向 ；
	 
	tout.close();
	return sum;
};
int department::read_p()
{
	phead->pnext=NULL;
	string name,tel,address,wage,coursename,book,graduate;
	ifstream sout("jiaoshou.txt");
	int sum=0;
	//for(int i=0;i<n;i++)
	while(!sout.eof())
	{
		sum++;
		sout>>name>>tel>>address>>wage>>coursename>>book>>graduate;
		CProfessor *p = new CProfessor(name,tel,address,wage,coursename,book,graduate);
		p->pnext=phead->pnext;
		phead->pnext=p;
	}
	//那么到最后  还是p->next没有指向 ；
	sout.close();
	return sum;
};
//此处做过测试   不要忘记删除 
void department::CStudentshow(int n)
{
	CStudent *p;
	p=shead->snext;
	cout << "==================================学生==================================" << endl;
	cout << "           姓名:          电话:          地址:          分数:"<<endl; 
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		p->show();
		p=p->snext;
		cout<<endl;
	}
};
void department::CDeanshow(int n)
{
	CDean *p;
	p=dhead->dnext;
	cout << "==============================================================系主任==============================================================" << endl;
	cout << "           姓名:          电话:          地址:          专业:          工资:             出版物:        研究生:         头衔:"<<endl; 
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		p->show();
		p=p->dnext;
		cout<<endl;
	}
}
void department::CTeachershow(int n)
{
	CTeacher *p;
	p=thead->tnext;
	cout << "=========================================老师========================================" << endl;
	cout << "           姓名:          电话:          地址:          工资:          专业:"<<endl; 
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		p->show();
		p=p->tnext;
		cout<<endl;	
	}
		
}
void department::CProfessorshow(int n)
{
	CProfessor *p;
	p=phead->pnext;
	cout << "========================================================教授========================================================" << endl;
	cout << "           姓名:          电话:          地址:          专业:          工资:             出版物:        研究生:"<<endl; 
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		p->show();
		p=p->pnext;
		cout<<endl;
	}
}
void menu::first()
{	
	cout<<"    ==========欢迎使用学校员工管理系统============"<<endl;
    cout<<"         	  喊员工开会请输入[1]                 "<<endl;  
    cout<<"                显示在校学生[2]                   "<<endl;
    cout<<"                显示在职教师[3]                   "<<endl; 
    cout<<"                显示在职教授[4]                   "<<endl;
    cout<<"               显示在职系主任[5]           "<<endl;
    //cout<<"               命令:   ";
}
int menu::get()
{
	cout<<"               命令:   ";
	cin>>kp;
	if(kp>=1&&kp<=5)
	return kp;//输入正确 
	else 
	return 0;//不正确 
}
int menu::end()
{
	cout<<"            是否想要继续输入？"<<endl;//暂时先这样安排
	cout<<"            [1]想~~~~~"<<endl;
	cout<<"            [2]不想！！！！！"<<endl;
	//cout<<"			   命令:";
	cin>>op;
	//返回 0 表示退出 1表示 想继续输入  2表示输入格式错误
	if(op==1)
	return 1;
	else if(op==2)
	return 0;
	else if(op!=1&&op!=2)
	return 2;
}
