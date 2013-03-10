#include<cassert>
#include<new>
using namespace std;
#include "Classtab.h"
#include "Subject.h" 
Classtab::Classtab()
:classSize(0)
{}
void Classtab::addclass(const int n)
{
	string name=totTable[n].myname,oldname;
	int numable=0,numtot;
	numtot=(totTable[n].myendweek-totTable[n].mystartweek+1)*(1+(totTable[n].mysecweed!=0));
	for(int i=totTable[n].mystartweek;i<=totTable[n].myendweek;++i)
	{
		if(table[totTable[n].myfirNo][totTable[n].myfirweed][i]=="\0")numable++;
		if(totTable[n].mysecweed&&table[totTable[n].mysecNo][totTable[n].mysecweed][i]=="\0")numable++;
	}
	cout<<name<<"课程总共有"<<numtot<<"节课，可以上"<<numable<<"节,请问是否将新课程添加进个人课程表？Y/N"<<endl;
	char is;
	cin>>is;
	if(is=='Y')
	{
		cout<<"你有两种添加方式:"<<endl; 
		cout<<"1.覆盖式添加，意思是如果新课程与旧课程有冲突，将只将冲突的时间段覆盖上新课程；"<<endl;
		cout<<"2.完全删除式添加，即添加课程之前会把冲突课程全部清空"<<endl;cout<<"选择哪种添加方式 1 or 2?"<<endl; 
		int choose;
		cin>>choose;
		if(choose==1)
		{
			for(int i=totTable[n].mystartweek;i<=totTable[n].myendweek;++i)
			{
				table[totTable[n].myfirNo][totTable[n].myfirweed][i]="\0";
				table[totTable[n].myfirNo][totTable[n].myfirweed][i]=name;
 				table[totTable[n].mysecNo][totTable[n].mysecweed][i]="\0";
	 			table[totTable[n].mysecNo][totTable[n].mysecweed][i]=name;
			}
		}
		if(choose==2)
		{
			for(int i=totTable[n].mystartweek;i<=totTable[n].myendweek;++i)
			{
				if(table[totTable[n].myfirNo][totTable[n].myfirweed][i]!="\0")
				{
					oldname=table[totTable[n].myfirNo][totTable[n].myfirweed][i];
					deleteclass(oldname);
				}
				else
				{
					table[totTable[n].myfirNo][totTable[n].myfirweed][i]=name;
					table[totTable[n].mysecNo][totTable[n].mysecweed][i]=name;
				}
			}
		}
		if(choose!=1&&choose!=2)cout<<"你的选项有误，请重新输入"<<endl; 
	}
	if(is=='N')return;
	if(is!='Y'&&is!='N'){cout<<"你的输入有误"<<endl;return;} 
	cout<<"如果添加未完成，请继续输入课程编码"<<endl; 
}
void Classtab::deleteclass(string name)
{
	for(int x=1;x<=20;++x)
	for(int y=1;y<=5;++y)
	for(int z=1;z<=7;++z)
	if(table[y][z][x]==name)table[y][z][x]="\0"; 
}
void Classtab::searchclass(int year,string specialty) const
{
	for(int i=0;i<=classSize;++i)
	if(totTable[i].myyear==year&&totTable[i].myspecialty==specialty)
	{
		cout<<"课程编号 "<<i<<" ";
		totTable[i].showClass(); 
	}
}
void Classtab::searchclass(string name) const
{
	for(int i=0;i<=classSize;++i)
	if(totTable[i].myname==name)
	{
		cout<<"课程编号 "<<i<<" ";
		totTable[i].showClass(); 
	}
}
void Classtab::addtotTable(Subject name)
{
	totTable[classSize].myname=name.myname;
	totTable[classSize].mystartweek=name.mystartweek;   
	totTable[classSize].myendweek=name.myendweek;
	totTable[classSize].myfirweed=name.myfirweed;
	totTable[classSize].myfirNo=name.myfirNo;
	totTable[classSize].mysecweed=name.mysecweed;
	totTable[classSize].mysecNo=name.mysecNo;
	totTable[classSize].myclassroom=name.myclassroom;
	totTable[classSize].myteacher=name.myteacher;
	totTable[classSize].myspecialty=name.myspecialty;
	totTable[classSize].myyear=name.myyear;
	++classSize;
}