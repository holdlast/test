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
void department::meet(int sn,int tn,int pn,int dn)//��������һ����������������ļ����Ѿ�����ȡ�������� ��ӡ�����е����� 
{
	
	
	
	//������д����    2019 6 13
	CPerson *p; 
	p=&CStudent;
	p=shead->snext;
	for(int i=0;i<sn;i++)
	{
		p->meet();
		p=p->snext;
		cout<<"\t";
		if(i%10==0)//ÿʮ����һ�� 
		cout<<endl;
	}
	cout<<endl;
	
	p=&CTeacher;
	p=thead->tnext;
	for(int i=0;i<tn;i++)
	{
		p->meet();
		p=p->tnext;
		cout<<"\t";
		if(i%10==0)//ÿʮ����һ�� 
		cout<<endl;
	}
	cout<<endl;
	
	
	p=&CProfessor;
	p=phead->pnext;
	for(int i=0;i<pn;i++)
	{
		p->meet();
		p=p->pnext;
		cout<<"\t";
		if(i%10==0)//ÿʮ����һ�� 
		cout<<endl;
	}
	cout<<endl;

	p=&CDean;
	p=dhead->dnext;
	for(int i=0;i<dn;i++)
	{
		p->meet();
		p=p->dnext;
		cout<<"\t";
		if(i%10==0)//ÿʮ����һ�� 
		cout<<endl;
	}
	cout<<endl;
	/*CStudent::meet();
	cout<<"\t";
	CTeacher::meet();
	cout<<"\t";
	CProfessor::meet();
	cout<<"\t";
	CDean::meet();
	cout<<"\t";*/
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
	CTeacher *teacher= new CTeacher();//�����Լ��Ĺ��캯�� 
	CProfessor *professor= new CProfessor();//ͬ��
	CStudent *student= new CStudent();
	CDean *dean= new CDean();
	//֮�������������ټ�����������д 
	shead=student;
	dhead=dean;
	thead=teacher;
	phead=professor; 
}


//������һ�β��� 
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
	thead->tnext=NULL;//thead������û�д������ݵ�  ��ָ�����һ����λ�������ݴ洢�� 
	string name,tel,address,wage,coursename;//���� 
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
	//��ô�����  ����p->nextû��ָ�� ��
	 
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
	//��ô�����  ����p->nextû��ָ�� ��
	sout.close();
	return sum;
};
//�˴���������   ��Ҫ����ɾ�� 
void department::CStudentshow(int n)
{
	CStudent *p;
	p=shead->snext;
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
	for(int i=0;i<n;i++)
	{
		p->show();
		p=p->pnext;
		cout<<endl;
	}
}
void menu::first()
{
	

	
	cout<<"    ==========��ӭʹ��ѧУԱ������ϵͳ============"<<endl;
    cout<<"         	  ��Ա������������[1]                 "<<endl;  
    cout<<"                ��ʾ��Уѧ��[2]                   "<<endl;
    cout<<"                ��ʾ��ְ��ʦ[3]                   "<<endl; 
    cout<<"                ��ʾ��ְ����[4]                   "<<endl;
    cout<<"               ��ʾ��ְϵ����(��~~)[5]           "<<endl;
    //cout<<"               ����:   ";
}
int menu::get()
{
	cout<<"               ����:   ";
	cin>>op;
	if(op>=1&&op<=5)
	return op;//������ȷ 
	else return 0;//����ȷ 
}

