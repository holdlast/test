#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstdlib>
#include"class.h" 
using namespace std;
int filenumber(int op);
int main()
{
	int sn=0,tn=0,pn=0,dn=0;
	department ans;
	sn=ans.read_s();
	tn=ans.read_t();
	pn=ans.read_p();
	dn=ans.read_d();
	cout<<"    ***************�����ļ����ݳɹ�***************"<<endl;
	cout << endl;
	//ans.CStudentshow(sn);  ��ʽ���Ʋ��� 
	//ans.meet(sn,tn,pn,dn);  ������  �ǵ�ɾ�� 
	menu UI;
	for(;;)
	{	
		int number=0;
		for(;;)//���벻��ȷ������ ,�����ֱ�ӽ���  ���ﻹ��Ҫ���´��� 
		{
			UI.first();
			int kp=UI.get();
			if(kp==0)
			{
				system("cls"); 
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~�����ʽ������Ҫ��~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<"    	*********************���������룡��*********************"<<endl; 
				continue;	
			}
			else 
			{
				system("cls");
				number=kp;//�����ָʾ���� 
				break; 
			}
		}
		if(number==1)
		ans.meet(sn,tn,pn,dn);
		else if(number==2)
		ans.CStudentshow(sn);
		else if(number==3)
		ans.CTeachershow(tn);
		else if(number==4)
		ans.CProfessorshow(pn);
		else if(number==5)
		ans.CDeanshow(dn);
		cout<<endl;
		int flag=3;
		for(;;)
		{
			int hop=UI.end();
			if(hop==0)// 0 ��ʾ�˳� 1��ʾ ���������  2��ʾ�����ʽ����
			{
				system("cls");
				flag=0;
				break;
			} 
			else if(hop==1)
			{
				system("cls");
				break;
			}
			else if(hop==2) 
			{
				system("cls");
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~�����ʽ������Ҫ��~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<"    	*********************���������룡��*********************"<<endl; 
				//�����е�ȱ�� 
			}
		}
		if(flag==0)
		{
			system("cls");
			cout<<"���˳�Ա������ϵͳ��"<<endl;
			break;
		} 
	}
	return 0;
}
