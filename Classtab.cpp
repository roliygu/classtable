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
	cout<<name<<"�γ��ܹ���"<<numtot<<"�ڿΣ�������"<<numable<<"��,�����Ƿ��¿γ���ӽ����˿γ̱�Y/N"<<endl;
	char is;
	cin>>is;
	if(is=='Y')
	{
		cout<<"����������ӷ�ʽ:"<<endl; 
		cout<<"1.����ʽ��ӣ���˼������¿γ���ɿγ��г�ͻ����ֻ����ͻ��ʱ��θ������¿γ̣�"<<endl;
		cout<<"2.��ȫɾ��ʽ��ӣ�����ӿγ�֮ǰ��ѳ�ͻ�γ�ȫ�����"<<endl;cout<<"ѡ��������ӷ�ʽ 1 or 2?"<<endl; 
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
		if(choose!=1&&choose!=2)cout<<"���ѡ����������������"<<endl; 
	}
	if(is=='N')return;
	if(is!='Y'&&is!='N'){cout<<"�����������"<<endl;return;} 
	cout<<"������δ��ɣ����������γ̱���"<<endl; 
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
		cout<<"�γ̱�� "<<i<<" ";
		totTable[i].showClass(); 
	}
}
void Classtab::searchclass(string name) const
{
	for(int i=0;i<=classSize;++i)
	if(totTable[i].myname==name)
	{
		cout<<"�γ̱�� "<<i<<" ";
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