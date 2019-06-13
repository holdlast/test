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
	cout<<"\n"<<"ѧ��"<<endl;
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
	
	cout<<"\n"<<"��ʦ"<<endl;
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
	cout<<"\n"<<"����"<<endl; 
	p_p=phead;
	for(int i=0;i<pn;i++)
	{
		p_p=p_p->pnext;
		cout<<setw(15);
		p_p->meet();
		if(i%10==0)
		cout<<endl;
	}
	cout<<"\n"<<"ϵ����"<<endl;
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
	cout << "==================================ѧ��==================================" << endl;
	cout << "           ����:          �绰:          ��ַ:          ����:"<<endl; 
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
	cout << "==============================================================ϵ����==============================================================" << endl;
	cout << "           ����:          �绰:          ��ַ:          רҵ:          ����:             ������:        �о���:         ͷ��:"<<endl; 
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
	cout << "=========================================��ʦ========================================" << endl;
	cout << "           ����:          �绰:          ��ַ:          ����:          רҵ:"<<endl; 
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
	cout << "========================================================����========================================================" << endl;
	cout << "           ����:          �绰:          ��ַ:          רҵ:          ����:             ������:        �о���:"<<endl; 
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
	cout<<"    ==========��ӭʹ��ѧУԱ������ϵͳ============"<<endl;
    cout<<"         	  ��Ա������������[1]                 "<<endl;  
    cout<<"                ��ʾ��Уѧ��[2]                   "<<endl;
    cout<<"                ��ʾ��ְ��ʦ[3]                   "<<endl; 
    cout<<"                ��ʾ��ְ����[4]                   "<<endl;
    cout<<"               ��ʾ��ְϵ����[5]           "<<endl;
    //cout<<"               ����:   ";
}
int menu::get()
{
	cout<<"               ����:   ";
	cin>>kp;
	if(kp>=1&&kp<=5)
	return kp;//������ȷ 
	else 
	return 0;//����ȷ 
}
int menu::end()
{
	cout<<"            �Ƿ���Ҫ�������룿"<<endl;//��ʱ����������
	cout<<"            [1]��~~~~~"<<endl;
	cout<<"            [2]���룡��������"<<endl;
	//cout<<"			   ����:";
	cin>>op;
	//���� 0 ��ʾ�˳� 1��ʾ ���������  2��ʾ�����ʽ����
	if(op==1)
	return 1;
	else if(op==2)
	return 0;
	else if(op!=1&&op!=2)
	return 2;
}
