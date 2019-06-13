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
	cout<<"    ***************读入文件数据成功***************"<<endl;
	cout << endl;
	//ans.CStudentshow(sn);  格式控制测试 
	//ans.meet(sn,tn,pn,dn);  测试用  记得删除 
	menu UI;
	for(;;)
	{	
		int number=0;
		for(;;)//输入不正确重新来 ,如果想直接结束  这里还需要重新处理 
		{
			UI.first();
			int kp=UI.get();
			if(kp==0)
			{
				system("cls"); 
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~输入格式不符合要求~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<"    	*********************请重新输入！！*********************"<<endl; 
				continue;	
			}
			else 
			{
				system("cls");
				number=kp;//输入的指示号码 
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
			if(hop==0)// 0 表示退出 1表示 想继续输入  2表示输入格式错误
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
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~输入格式不符合要求~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<"    	*********************请重新输入！！*********************"<<endl; 
				//这里有点缺陷 
			}
		}
		if(flag==0)
		{
			system("cls");
			cout<<"已退出员工管理系统！"<<endl;
			break;
		} 
	}
	return 0;
}
