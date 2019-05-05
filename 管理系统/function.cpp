#include<iostream>
#include<iomanip>
using namespace std;
#include"class.h"
void CDean::show()
{
	CProfessor::show();
	cout <<setw(15)<< title;
}
void CProfessor::show()
{
	CTeacther::show();
	cout <<setw(20)<< book <<setw(15)<< graduate;
}
void CTeacther::show()
{
	CPerson::show();
	cout <<setw(15)<< coursename <<setw(15)<< wage;
}
void CStudent::show()
{
	CPerson::show();
	cout <<setw(15)<< score;
}
void CPerson::show()
{
	cout<<setw(15)<<name<<setw(15)<<tel<<setw(15)<<address;
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
	cout<<"               ����:   ";
	cin>>op;
	if(op>=1&&op<=5)
	return 0;
	else return 1; 
}
int department::end()
{
	cout<<"            ";
	cin>>judge;
	if(judge==2)
	return 1;
	else return 0; 
}
void department::display(CStudent *S,CTeacther *T,CProfessor *P,CDean *D)//Ҫ�д���Ĳ��� 
{
	if(op==1)//ȫ��Ա������ 
	{
		//cout<<"�ȴ�����........."<<endl;
		cout << "==================================ѧ��==================================" << endl;
		cout << "           ����:          �绰:          ��ַ:          ����:"<<endl; 
		cout<<endl;
		for (int i = 0; i < 100; i++)
		{
			S[i].show();
			cout << endl;
		}
		
		cout << "=========================================��ʦ========================================" << endl;
		cout << "           ����:          �绰:          ��ַ:          ����:          רҵ:"<<endl; 
		cout<<endl;
		for (int i = 0; i < 20; i++)
		{
			T[i].show();
			cout << endl;
		}
		
		
		cout << "========================================================����========================================================" << endl;
		cout << "           ����:          �绰:          ��ַ:          רҵ:          ����:             ������:        �о���:"<<endl; 
		cout<<endl;
		for (int i = 0; i < 4; i++)
		{
			P[i].show();
			cout << endl;
		}
		
		cout << "==============================================================ϵ����==============================================================" << endl;
		cout << "           ����:          �绰:          ��ַ:          רҵ:          ����:             ������:        �о���:         ͷ��:"<<endl; 
		cout<<endl;
		D->show();
		cout<<endl; 
		
		
	}
	else if(op==2)
	{
		cout << "==================================ѧ��==================================" << endl;
		cout << "           ����:          �绰:          ��ַ:          ����:"<<endl; 
		cout<<endl;
		for (int i = 0; i < 100; i++)
		{
			S[i].show();
			cout << endl;
		}
	}
	else if(op==3)
	{
		cout << "=========================================��ʦ========================================" << endl;
		cout << "           ����:          �绰:          ��ַ:          ����:          רҵ:"<<endl; 
		cout<<endl;
		for (int i = 0; i < 20; i++)
		{
			T[i].show();
			cout << endl;
		}
	}
	else if(op==4)
	{
		cout << "========================================================����========================================================" << endl;
		cout << "           ����:          �绰:          ��ַ:          רҵ:          ����:             ������:        �о���:"<<endl; 
		cout<<endl;
		for (int i = 0; i < 4; i++)
		{
			P[i].show();
			cout << endl;
		}
	}
	else if(op==5)
	{
		cout << "==============================================================ϵ����==============================================================" << endl;
		cout << "           ����:          �绰:          ��ַ:          רҵ:          ����:             ������:        �о���:         ͷ��:"<<endl; 
		cout<<endl;
		D->show();
		cout<<endl; 
	}
}
void department::first()
{ 
    cout<<"    ==========��ӭʹ��ѧУԱ������ϵͳ============"<<endl;
    cout<<"         	  ��Ա������������[1]                 "<<endl;  
    cout<<"                ��ʾ��Уѧ��[2]                   "<<endl;
    cout<<"                ��ʾ��ְ��ʦ[3]                   "<<endl; 
    cout<<"                ��ʾ��ְ����[4]                   "<<endl;
    cout<<"               ��ʾ��ְϵ����(��~~)[5]           "<<endl;
    //cout<<"               ����:   ";
}
