#include<iostream>
#include<cstdio> 
using namespace std;
class tiji
{
    public:
        void display();
        void show();
    private:
        int length;
        int width;
        int height;
};
void tiji::display()
{
    cin>>length>>width>>height;
};
void tiji::show()
{
    cout<<length*height*width<<endl;
}
tiji t;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        t.display();
        t.show();
    }
    return 0;
}
