#include<iostream>
using namespace std;
class CPerson
{
	private:
		string name;
		string address;
		string tel;
	public:
		CPerson():name("NULL"),address("NULL"),tel("NULL"){}
		CPerson(string names,string tels,string addresss):name(names),tel(tels),address(addresss){}
		virtual void show();
		virtual void meet();
		~CPerson(){}
		
};
class CStudent : public CPerson 
{
	private:
		string score;
	public:
		CStudent *snext;
		CStudent(string a,string b,string c,string d):CPerson(a,b,c)
		{
			score=d;
		}
		CStudent():CPerson("NULL","NULL","NULL"),score("NULL"){};
		void show();
		void meet();
		~CStudent(){};
};
class CTeacher : public CPerson
{
private:
	string coursename;
	string wage;

public:
	CTeacher *tnext;
	//void get_CTeacther(string names, string tels, string addresss, string coursenames, string wages);
	void show();
	void meet();
	~CTeacher() {}
	CTeacher(string a, string b, string c, string d, string e) : CPerson(a, b, c)
	{
		wage = d;
		coursename = e;
	}
	CTeacher() : CPerson("NULL", "NULL", "NULL"), coursename("NULL"), wage("NULL") {}
};
class CProfessor : public CTeacher
{
private:
	string book;
	string graduate;

public:
	CProfessor *pnext;
	//void get_CProfessor(string names, string tels, string addresss, string coursenames, string wages, string books, string graduates);
	void show();
	void meet();
	~CProfessor() {}
	CProfessor(string a, string b, string c, string d, string e, string f, string g) : CTeacher(a, b, c, d, e), book(f), graduate(g) {}
	CProfessor() : CTeacher("NULL", "NULL", "NULL", "NULL", "NULL"), book("NULL"), graduate("NULL") {}
};

class CDean : public CProfessor
{
private:
	string title;

public:
	CDean *dnext;
	//void get_CDean(string names, string tels, string addresss, string coursenames, string wages, string books, string graduates, string titles);
	~CDean() {}
	void show();
	void meet();
	CDean(string a, string b, string c, string d, string e, string f, string g, string h) : CProfessor(a, b, c, d, e, f, g), title(h) {}
	CDean() : CProfessor("NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"), title("NULL") {}
};

class department
{
	private:
		CStudent *shead;
		CTeacher *thead;
		CProfessor *phead;
		CDean *dhead;
	public:
		department();
		int read_d();//read CDean file
		int read_s();
		int read_t();//read student file
		int read_p();//read professor file 
		void CTeachershow(int n);
		void CProfessorshow(int n);
		void CStudentshow(int n);
		void CDeanshow(int n);
		void meet(int sn,int tn,int pn,int dn);
		~department(){};
};
class menu
{
	private:
		int op;
		int kp;
	public:
		menu():kp(1),op(1){};
		void first();
		int end(); 
		int get();
		~menu(){}
};
