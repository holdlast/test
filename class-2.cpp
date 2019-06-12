#include<iostream>
#include<cstdio>
using namespace std;
class CPerson
{
    private:
        string name,tel,address;
    public:
        CPerson(string names,string tels,string addresss):name(names),tel(tels),address(addresss){}
        CPerson():name("NULL"),tel("NULL"),address("NULL"){};
        virtual void show();
        void get_CPerson(string names,string tels,string addresss);
        ~CPerson(){}
};
class CStudent:public CPerson
{
    private:
        string score;
    public:
        CStudent(string names,string tels,string addresss,string scores):CPerson(names,tels,addresss),score(scores){}
        CStudent():score("NULL"){}
        virtual void show();
        void get_CStudent(string names,string tels,string addresss,string score);
        ~CStudent(){}
};
class CTeacher:public CPerson
{
    private:
        string coursename,wage;
    public:
        CTeacher(string names,string tels,string addresss,string coursenames,string wages):CPerson(names,tels,addresss),coursename(coursenames),wage(wages){}
        CTeacher():coursename("NULL"),wage("NULL"){};
        virtual void show();
        void get_CTeacher();
        ~CTeacher(){};
};
class CProfessor:public CTeacher
{
    private:
        string book,graduate;
    public:
        CProfessor(string names,string tels,string addresss,string coursenames,string wages,string books,string graduates):CTeacher(names,tels,addresss,coursenames,wages),book(books),graduate(graduates){}
        CProfessor():CTeacher(),book("NULL"),graduate("NULL"){}
        virtual void show();
        void get_CProfessor();
        ~CProfessor(){}
};
class CDean:public CProfessor
{
    private:
        string title;
    public:
        CDean(string names,string tels,string addresss,string coursenames,string wages,string books,string graduates,string titles):CProfessor(names,tels,addresss,coursenames,wages,books,graduates),title(titles){}
        CDean():CProfessor(),title("NULL"){}
        virtual void show();
        void get_CDean();
        ~CDean(){}
};