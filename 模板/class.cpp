//欢迎从四面八方爬过来的朋友
//通过这段代码的阅读注释能帮你更好的理解本项目好了二话不说相位猛冲我们开始！
#include <iostream>
#include <cstdlib>//system("cls")  清屏函数在这里面 
#include <iomanip>//格式控制函数setw()在这里面  要引入 
#include <cstdio>
#include <fstream>//文件写入  ifstream myout("xoxo.txt")其实有第二个参数  没写默认打开  !  用myout读 
using namespace std;
//类文件开始！ 
class CPerson
{
private:
	string name;
	string tel;
	string address;

public:
	CPerson(string a, string b, string c) : name(a), tel(b), address(c) {}
	CPerson() : name("NULL"), tel("NULL"), address("NULL") {}
	void get_CPerson(string names, string tels, string addresss);
	virtual void show();
	virtual void meet();
	~CPerson() {}
};
class CStudent : public CPerson
{
private:
	string score;

public:
	CStudent(string a, string b, string c, string d) : CPerson(a, b, c), score(d) {}
	CStudent() : CPerson("NULL", "NULL", "NULL"), score("NULL") {}
	void get_CStudent(string names, string tels, string addresss, string scores);
	void show();
	void meet();
	~CStudent() {}
};
class CTeacher : public CPerson
{
private:
	string coursename;
	string wage;

public:
	CTeacher(string a, string b, string c, string d, string e) : CPerson(a, b, c), coursename(d), wage(e) {}
	CTeacher() : CPerson("NULL", "NULL", "NULL"), coursename("NULL"), wage("NULL") {}
	void get_CTeacher(string names, string tels, string addresss, string coursenames, string wages);
	void show();
	void meet();
	~CTeacher() {}
};
class CProfessor : public CTeacher
{
private:
	string book;
	string graduate;

public:
	CProfessor(string a, string b, string c, string d, string e, string f, string g) : CTeacher(a, b, c, d, e), book(f), graduate(g) {}
	CProfessor() : CTeacher("NULL", "NULL", "NULL", "NULL", "NULL"), book("NULL"), graduate("NULL") {}
	void get_CProfessor(string names, string tels, string addresss, string coursenames, string wages, string books, string graduates);
	void show();
	void meet();
	~CProfessor() {}
};
class CDean : public CProfessor
{
private:
	string title;

public:
	CDean(string a, string b, string c, string d, string e, string f, string g, string h) : CProfessor(a, b, c, d, e, f, g), title(h) {}
	CDean() : CProfessor("NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"), title("NULL") {}
	void get_CDean(string names, string tels, string addresss, string coursenames, string wages, string books, string graduates, string titles);
	void show();
	void meet();
	~CDean() {}
};
class department
{
private:
	CStudent S[110];
	CTeacher T[110];
	CProfessor P[110];
	CDean D[110];
	//p=(CStudent*)calloc(n,sizeof(CStudent))
public:
	department();
	int read_s();
	int read_t();
	int read_p();
	int read_d();
	void CStudentshow(int n);
	void CTeachershow(int n);
	void CProfessorshow(int n);
	void CDeanshow(int n);
	void meeting(int sn, int tn, int pn, int dn);
	~department() {}
};

//类文件结束 

//函数定义的文件  开始写   自己改改   我的个人痕迹太明显 
void department::meeting(int sn, int tn, int pn, int dn)
{
	cout<<"学生："<<endl;
	for (int i = 0; i < sn; i++)
	{
		S[i].meet();
		cout << '\t';
		if (i % 10 == 0)
			cout << endl;
	}
	cout << endl;
	cout<<"老师："<<endl;
	for (int i = 0; i < tn; i++)
	{
		T[i].meet();
		cout << '\t';
		if (i % 10 == 0)
			cout << endl;
	}
	cout << endl;
	cout<<"教授："<<endl; 
	for (int i = 0; i < pn; i++)
	{
		P[i].meet();
		cout << '\t';
		if (i % 10 == 0)
			cout << endl;
	}
	cout << endl;
	cout<<"系主任："<<endl; 
	for (int i = 0; i < dn; i++)
	{
		D[i].meet();
		cout << "\t";
		if (i % 10 == 0)
			cout << endl;
	}
	cout << endl;
}
void department::CDeanshow(int n)
{
	for (int i = 0; i < n; i++)
	{
		D[i].show();
		cout << endl;
	}
}
void department::CProfessorshow(int n)
{
	for (int i = 0; i < n; i++)
	{
		P[i].show();
		cout << endl;
	}
}
void department::CTeachershow(int n)
{
	for (int i = 0; i < n; i++)
	{
		T[i].show();
		cout << endl;
	}
}
void department::CStudentshow(int n)
{
	for (int i = 0; i < n; i++)
	{
		S[i].show();
		cout << endl;
	}
}

int department::read_d()
{
	ifstream dout("xizhuren.txt");
	int i = 0;
	string name, tel, address, coursename, wage, book, graduate, title;
	while (!dout.eof())
	{
		dout >> name >> tel >> address >> coursename >> wage >> book >> graduate >> title;
		D[i].get_CDean(name, tel, address, coursename, wage, book, graduate, title);
		i++;
	}
	return i; // 返回行数 
}
int department::read_p()
{
	ifstream pout("jiaoshou.txt");
	string name, tel, address, coursename, wage, book, graduate;
	int i = 0;
	while (!pout.eof())
	{
		pout >> name >> tel >> address >> coursename >> wage >> book >> graduate;
		P[i].get_CProfessor(name, tel, address, coursename, wage, book, graduate);
		i++;
	}
	return i;
}

int department::read_s()
{
	ifstream sout("xuesheng.txt");
	string name, address, tel, score;
	//for(int i=0;i<100;i++)
	int i = 0;
	while (!sout.eof())
	{
		sout >> name >> tel >> address >> score;
		S[i].get_CStudent(name, tel, address, score);
		i++;
	}
	return i;
}
int department::read_t()
{
	ifstream tout("laoshi.txt");
	string name, address, tel, coursename, wage;
	int i = 0;
	while (!tout.eof())
	{

		tout >> name >> tel >> address >> coursename >> wage;
		T[i].get_CTeacher(name, tel, address, coursename, wage);
		i++;
	}
	return i;
}

department::department()
{
	//CStudent *p=new CStudent();
	for (int i = 0; i < 110; i++)
		S[i].get_CStudent("NULL", "NULL", "NULL", "NULL");
	for(int i=0;i<110;i++)
		T[i].get_CTeacher("NULL","NULL","NULL","NULL","NULL");
	for(int i=0;i<110;i++)
		P[i].get_CProfessor("NULL","NULL","NULL","NULL","NULL","NULL","NULL");
	for(int i=0;i<110;i++)
		D[i].get_CDean("NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL");
}
void CDean::show()
{
	CProfessor::show();
	cout << setw(15) << title;
}
void CProfessor::show()
{
	CTeacher::show();
	cout << setw(20) << book << setw(15) << graduate;
}
void CTeacher::show()
{
	CPerson::show();
	cout << setw(15) << coursename << setw(15) << wage;
}
void CStudent::show()
{
	CPerson::show();
	cout << setw(15) << score;
}
void CPerson::show()
{
	cout << setw(15) << name << setw(15) << tel << setw(15) << address;
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
void CTeacher::get_CTeacher(string names, string tels, string addresss, string coursenames, string wages)
{
	CPerson::get_CPerson(names, tels, addresss);
	coursename = coursenames;
	wage = wages;
}
void CProfessor::get_CProfessor(string names, string tels, string addresss, string coursenames, string wages, string books, string graduates)
{
	CTeacher::get_CTeacher(names, tels, addresss, coursenames, wages);
	book = books;
	graduate = graduates;
}
void CDean::get_CDean(string names, string tels, string addresss, string coursenames, string wages, string books, string graduates, string titles)
{
	CProfessor::get_CProfessor(names, tels, addresss, coursenames, wages, books, graduates);
	title = titles;
}
void CPerson::meet()
{
	cout <<setw(15)<< name; //按照老师要求  meet函数 只是输出人名！ 
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

//到这里  函数定义的文件结束 

//  这里以下是主函数文件 
int main()
{
	department ans;
	int sn,tn,pn,dn;
	//  上面定义的几个变量是为了  储存每一个文件的行数   ans里面所含有的函数  read_xxx()函数返回文件的行数 并将文件里的数据读入数组中 
	sn=ans.read_s();
	tn=ans.read_t();
	pn=ans.read_p();
	dn=ans.read_d();
	//这里就是已经读入完毕
	//这里还差一个界面  自己写吧  我写的的话  个人风格太明显
	//我先写一个建议的界面  为了测试~~
	while(1)
	{
		char op;
		int flag=0;
		//这个显示的界面你可以封装成一个类   或者写一个函数  这样能让main函数看起来而更加精简点 
		cout<<"输入:"<<endl;
		cout<<"[1]开会"<<endl;//开会只显示  在校教师 和员工的名字 
		cout<<"[2]显示学生的数据"<<endl;
		cout<<"[3]显示老师的数据"<<endl;
		cout<<"[4]显示教授的数据"<<endl;
		cout<<"[5]显示系主任的数据"<<endl;
		cout<<"注意:输入其他字符（一个啊 ！  别输入多了）会退出"<<endl;
		cout<<"命令:"<<endl;
		cin>>op;
		system("cls");//这个看不懂可以删除！  就是为了好看清一下屏
		if(op-'0'>=1&&op-'0'<=5)
		{
			int count=op-'0';//转化为数字 
			switch(count)
			{
				case 1:
					{
						ans.meeting(sn,tn,pn,dn);
						break; 
					}
				case 2:
					{
						ans.CStudentshow(sn);
						break;	
					}
				case 3:
					{
						ans.CTeachershow(tn);
						break; 
					}
				case 4:
					{
						ans.CProfessorshow(pn);
						break;
					}
				case 5:
					{
						ans.CDeanshow(dn);
						break;
					}	
			}
		}
		else
		{
			system("cls");
			break;
		}
		
	}
	cout<<"已退出管理系统"<<endl; 
	return 0;
}


//最后   文件分成三个   1.功能文件（包含  类里面的函数）  2.类文件   3.主函数文件    自己分吧！ 
