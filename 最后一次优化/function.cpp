#include<iostream>
using namespace std;
#include"class.h"
void CDean::show()
{
	CProfessor::show();
	cout << " " << title;
}
void CProfessor::show()
{
	CTeacther::show();
	cout << " " << book << " " << graduate;
}
void CTeacther::show()
{
	CPerson::show();
	cout << " " << coursename << " " << wage;
}
void CStudent::show()
{
	CPerson::show();
	cout << " " << score;
}
void CPerson::show()
{
	cout << name << " " << tel << " " << address;
}

void CPerson::get_CPerson(string names, string tels, string addresss)
{
	name = names;
	tel = tels;
	address = addresss;
}
void CStudent::get_CStudent(string names, string tels, string addresss, string scores)
{
	CPerson::get_CPerson(names, tels, addresss);
	score = scores;
}
void CTeacther::get_CTeacther(string names, string tels, string addresss, string coursenames, string wages)
{
	CPerson::get_CPerson(names, tels, addresss);
	coursename = coursenames;
	wage = wages;
}
void CProfessor::get_CProfessor(string names, string tels, string addresss, string coursenames, string wages, string books, string graduates)
{
	CTeacther::get_CTeacther(names, tels, addresss, coursenames, wages);
	book = books;
	graduate = graduates;
}
void CDean::get_CDean(string names, string tels, string addresss, string coursenames, string wages, string books, string graduates, string titles)
{
	CProfessor::get_CProfessor(names, tels, addresss, coursenames, wages, books, graduates);
	title = titles;
}
int department::get()
{
	cin>>op;
	if(op>=1&&op<=5)
	return 0;
	else return 1; 
}
int department::end()
{
	cin>>judge;
	if(judge==2)
	return 1;
	else return 0; 
}
void department::display(CStudent *S,CTeacther *T,CProfessor *P,CDean *D)//Ҫ�д���Ĳ��� 
{
	if(op==1)//ȫ��Ա������ 
	{
		cout<<"�ȴ�����........."<<endl;
		/*ans=new department;
		for(int i=2;i<=5;i++)
		{
			op=i;
			ans()
		}*/
	}
	else if(op==2)
	{
		cout << "==========ѧ��============" << endl;
		for (int i = 0; i < 100; i++)
		{
			S[i].show();
			cout << endl;
		}
	}
	else if(op==3)
	{
		cout << "===========��ʦ==============" << endl;
		for (int i = 0; i < 20; i++)
		{
			T[i].show();
			cout << endl;
		}
	}
	else if(op==4)
	{
		cout << "==========����==============" << endl;
		for (int i = 0; i < 4; i++)
		{
			P[i].show();
			cout << endl;
		}
	}
	else if(op==5)
	{
		cout << "============ϵ����==============" << endl;
		D->show();
		cout<<endl; 
	}
}
void department::first()
{
	cout<<"***************�������ļ��ݳɹ�***************"<<endl; 
    cout<<"==========��ӭʹ��ѧУԱ������ϵͳ:=========="<<endl;
    cout<<"     	  ��Ա������������[1]                 "<<endl;  
    cout<<"            ��ʾ��Уѧ��[2]                   "<<endl;
    cout<<"            ��ʾ��ְ��ʦ[3]                   "<<endl; 
    cout<<"            ��ʾ��ְ����[4]                   "<<endl;
    cout<<"           ��ʾ��ְϵ����(��~~)[5]           "<<endl;
}
