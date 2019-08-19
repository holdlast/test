#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main()
{
    vector<char> tp;
    char ans='0';
    ifstream read("test.txt");
    while(!read.eof())
    {
        read>>ans;
        tp.push_back(ans);
    }
    int op[91]={0};
    double sum=0.0;
    vector<char>::iterator iter;
    for(iter=tp.begin();iter!=tp.end();iter++)
    {
        if((*iter)>=65&&(*iter)<=90)//small
        {
            op[(int)*iter]++;
            sum++;
        }
        else if((*iter)>=97&&(*iter)<=122)// big -32
        {
            op[((int)*iter)-32]++;
            sum++;
        }
        else if((*iter)==32)// 32 空格
        {
            op[(int)(*iter)]++;
        }
        else if((*iter)==46)//46 .
        {
            op[(int)(*iter)]++;
        }
        else if((*iter)==44)// ,
        {
        	op[(int)(*iter)]++;
        }
        //sum++;
    }
    printf("空格的个数为:%d\n",op[32]);
    printf("'.'的个数为:%d\n",op[46]);
    printf("','的个数为:%d\n",op[44]);
    for(int i=65;i<=90;i++)
    {
        cout<<(char)(i+32)<<"的个数为"<<op[i]<<'\t'<<"所占百分比为"<<((double)op[i])/((double)sum)<<'%'<<endl;
    }
    system("pause");
    return 0;
}