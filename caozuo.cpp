#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
struct node{
    double date;
    node *next;
};



struct node *Creatlist(int num){//指定数目节点的创建
    node *p,*head;
    p=new node();
    head=p;
    if(num==0){
        head=NULL;
        return head;
    }
    else{
        double count=0.0;
        for(int i=1;i<=num;i++){
            cout<<"请输入第"<<i<<"个date:"<<endl;
            cin>>count;
            node *newnode = new node();
            newnode->date=count;
            p->next=newnode;
            p=newnode;
        }
        head=head->next;//这里传出的第一个头指针是有数据存储的
        p->next=NULL;
        return head;
    }
    
};




int list_length(node *head){
    int sum=0;
    node *p=head;
    for(;p;p=p->next){
        ++sum;
    }
    return sum;
}





//这里做两个  一个是指定序号的位置插入  另一个是直接尾部插入
void addvalue_2(node *head, double count){//在结尾处 插入元素
    struct node *p=new node();
    p->date=count;
    p->next=NULL;
    node *op=head;
    //考虑到空的链表处理方式
    if(op==NULL){
        op=p;
    }
    else{
        while(op->next!=NULL){
            op=op->next;
        }
        op->next=p;
    }
};



void addvalue_1(node *head,int num,double count){//在指定的位置插入元素
    node *p=head;
    int sum=0;
    sum=list_length(head);
    if(num>sum){
        cout<<"太大了 链表没达到这一范围"<<endl;
    }else if(num==0){
        cout<<"神经病! 插入第0个位置!"<<endl;
    }else if(num==1){//插在链表的最前面 接在原来的head的前面 之后让他当head
        node *op=new node();
        op->date=count;
        op->next=head;
        head=op;
    }else if(num==sum){
        addvalue_2(head,count);
    }else{
        for(int i=1;i<=num-1;i++){
            p=p->next;
        }//结束后的for循环到达的位置是 num-1位置
        node *op=new node();
        op->date=count;
        op->next=p->next;
        p->next=op;
    }
}



void show(node *head){
    node *p=head;
    int i=1;
    //对于节点没有值的情况  也就是在经过增添删减之后 链表的情况出现了变化后
    if(p==NULL){
        cout<<"NULL!"<<endl;
    }
    else{
        for(;p;p=p->next){
            cout<<"第"<<i<<"个节点的date是:"<<p->date<<endl;
            ++i;
        }
    }
};
int main(){
    //show(Creatlist(5));
    node *p=Creatlist(0);
    show(p);
    addvalue_2(p,6);
    cout<<"\n"<<endl; 
    show(p);
    
    cout<<"链表的长度为"<<list_length(p)<<endl;
    return 0;
}
