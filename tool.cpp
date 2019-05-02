#include<iostream>
using namespace std;
class Student
{
	private:
		string number;
		int score;
	public:
		Student():number("NULL"),score(-1){}
		void get()
		{
			cin>>number>>score;
		};
		void show()
		{
			cout<<number<<" "<<score;	
		};	
};
int main()
{
	Student t[6];
	Student *p=t;
	for(int i=1;i<6;i++)
	p[i].get();
	cout<<"1--3--5ºÅ"<<endl;
	p[1].show();
	cout<<endl;
	p[3].show();
	cout<<endl;
	p[5].show();
	cout<<endl;
	return 0;
}
