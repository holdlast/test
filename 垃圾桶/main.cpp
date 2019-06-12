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
	/*menu UI;
	while(1)
	{
		int number=0;
		UI.first();
		while(1)//输入不正确重新来 ,如果想直接结束  这里还需要重新处理 
		{
			int kp=UI.get();
			if(kp==0)
			{
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~输入格式不符合要求~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<"    	*********************请重新输入！！*********************"<<endl; 
				continue;	
			}
			else
			{
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
		//之后就是可以直接读取打印
		//在这之后  要增强可选择性和鲁棒性 
	}
	//ans.CStudentshow(sum);
	//cout<<endl;
	*/
	return 0;
}

//文件行数判断 
/*int filenumber(int op)
{
	if(op==2)//学生 
	{
		ifstream infile("xuesheng.txt");
		char str[100];
		int n=0;
		while(!infile.eof())
		{
			infile.getline(str, sizeof(str));//此处默认的终止标识符为‘\n’
			n++;
		}
		return n;	
	}
	else if(op==2)//老师 
	{
		ifstream infile("laoshi.txt");
		char str[100];
		int n=0;
		while(!infile.eof())
		{
			infile.getline(str, sizeof(str));//此处默认的终止标识符为‘\n’
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
			infile.getline(str, sizeof(str));//此处默认的终止标识符为‘\n’
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
			infile.getline(str, sizeof(str));//此处默认的终止标识符为‘\n’
			n++;
		}
		return n;	
	}
} */
