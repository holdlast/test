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
	/*menu UI;
	while(1)
	{
		int number=0;
		UI.first();
		while(1)//���벻��ȷ������ ,�����ֱ�ӽ���  ���ﻹ��Ҫ���´��� 
		{
			int kp=UI.get();
			if(kp==0)
			{
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~�����ʽ������Ҫ��~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<"    	*********************���������룡��*********************"<<endl; 
				continue;	
			}
			else
			{
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
		//֮����ǿ���ֱ�Ӷ�ȡ��ӡ
		//����֮��  Ҫ��ǿ��ѡ���Ժ�³���� 
	}
	//ans.CStudentshow(sum);
	//cout<<endl;
	*/
	return 0;
}

//�ļ������ж� 
/*int filenumber(int op)
{
	if(op==2)//ѧ�� 
	{
		ifstream infile("xuesheng.txt");
		char str[100];
		int n=0;
		while(!infile.eof())
		{
			infile.getline(str, sizeof(str));//�˴�Ĭ�ϵ���ֹ��ʶ��Ϊ��\n��
			n++;
		}
		return n;	
	}
	else if(op==2)//��ʦ 
	{
		ifstream infile("laoshi.txt");
		char str[100];
		int n=0;
		while(!infile.eof())
		{
			infile.getline(str, sizeof(str));//�˴�Ĭ�ϵ���ֹ��ʶ��Ϊ��\n��
			n++;
		}
		return n;	
	}
	else if(op==3)
	{
		ifstream infile("jiaoshou.txt");
		char str[100];
		int n=0;
		while(!infile.eof())
		{
			infile.getline(str, sizeof(str));//�˴�Ĭ�ϵ���ֹ��ʶ��Ϊ��\n��
			n++;
		}
		return n;	
	} 
	else if(op==4)
	{
		ifstream infile("xizhuren.txt");
		char str[100];
		int n=0;
		while(!infile.eof())
		{
			infile.getline(str, sizeof(str));//�˴�Ĭ�ϵ���ֹ��ʶ��Ϊ��\n��
			n++;
		}
		return n;	
	}
} */
