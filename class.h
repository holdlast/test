#include<iostream> 
using namespace std;
class CPerson
{
private:
	string name;
	string tel;
	string address;

public:
	void get_CPerson(string names, string tels, string addresss);
	virtual void show();
	CPerson(string a, string b, string c)
	{
		name = a;
		tel = b;
		address = c;
	}
	CPerson() : name("NULL"), tel("NULL"), address("NULL") {}
	~CPerson() {}
};
class CStudent : public CPerson
{
private:
	string score;

public:
	void show();
	void get_CStudent(string names, string tels, string addresss, string scores);
	CStudent(string a, string b, string c, string d) : CPerson(a, b, c),score(d){}
	CStudent() : CPerson("NULL", "NULL", "NULL"), score("NULL") {}
	~CStudent() {}
};

class CTeacther : public CPerson
{
private:
	string coursename;
	string wage;

public:
	void get_CTeacther(string names, string tels, string addresss, string coursenames, string wages);
	void show();
	~CTeacther() {}
	CTeacther(string a, string b, string c, string d, string e) : CPerson(a, b, c)
	{
		coursename = d;
		wage = e;
	}
	CTeacther() : CPerson("NULL", "NULL", "NULL"), coursename("NULL"), wage("NULL") {}
};

class CProfessor : public CTeacther
{
private:
	string book;
	string graduate;

public:
	void get_CProfessor(string names, string tels, string addresss, string coursenames, string wages, string books, string graduates);
	void show();
	~CProfessor() {}
	CProfessor(string a, string b, string c, string d, string e, string f, string g) : CTeacther(a, b, c, d, e), book(f), graduate(g) {}
	CProfessor() : CTeacther("NULL", "NULL", "NULL", "NULL", "NULL"), book("NULL"), graduate("NULL") {}
};

class CDean : public CProfessor
{
private:
	string title;

public:
	void get_CDean(string names, string tels, string addresss, string coursenames, string wages, string books, string graduates, string titles);
	~CDean() {}
	void show();
	CDean(string a, string b, string c, string d, string e, string f, string g, string h) : CProfessor(a, b, c, d, e, f, g), title(h) {}
	CDean() : CProfessor("NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"), title("NULL") {}
};
 
class department
{
	private:
		int op;
		int judge;
	public:
		department():op(0),judge(0){} 
		void first();//执行某一段完成后显示（不包含退出） 
		int get(); 
		void display(CStudent *S,CTeacther *T,CProfessor *P,CDean *D);//传入的参数 包含所对应的对象数组 
		int end();
		void sets();//有待开发 
};

