#include <iostream>
#include "Subject.h" 
#include "Classtab.h"
#include<fstream>
using namespace std;

int main(int argc, char *argv[])
{
	cout<<"��ӭʹ�ñ��γ̹���������ڵ���γ���Ϣ����ȷ�� '�γ�.txt'��'d:\\�γ�.txt'·����" <<endl; 
	ifstream f("d:\\�γ�.txt",ios::in);
	string myname,myclassroom,myteacher,myspecialty;
	int mystartweek,myendweek,myfirweed,myfirNo,mysecweed,mysecNo,myyear;
	Classtab roliy;
	while(!f.eof())
	{
		f>>myname>>mystartweek>>myendweek>>myfirweed>>myfirNo>>mysecweed>>mysecNo>>myclassroom>>myteacher>>myspecialty>>myyear;
		Subject name;
		name.makeSubject(myname,mystartweek,myendweek,myfirweed,myfirNo,mysecweed,mysecNo,myclassroom,myteacher,myspecialty,myyear);
		roliy.addtotTable(name);
	}
	f.close();
	cout<<"����ɹ�����ѡ�������"<<endl;
	int ch;
	cout<<"1.��ѯ�ܿγ̿�"<<endl; 
	cout<<"2.���γ̱��뽫�γ̴��ܿ���ӵ����˿α�"<<endl;
	cout<<"3.�������˿α�"<<endl; 
	cout<<"4.�����˳�"<<endl;
	cout<<endl;
	ofstream outFile("d:\\�ҵĿα�.txt",ios::out);
	while(cin>>ch)
	{
		if(ch==1)
		{
			cout<<"1.��רҵ����ѧ��ݲ�ѯ��2.���γ�����ѯ�������룺"<<endl;
			int ch2;
			cin>>ch2;
			if(ch2==1)
			{
				string sname;
				int year1;
				cout<<"������רҵ������ѧ��ݣ��Կո���"<<endl; 
				cin>>sname>>year1;
				roliy.searchclass(year1,sname);
			}
			if(ch2==2)
			{
				string sname1;
				cout<<"������γ�����"<<endl; 
				cin>>sname1;
				roliy.searchclass(sname1);
			}
		}
		if(ch==2)
		{
			int p;
			cout<<"Ҫ��Ӷ����ſγ��أ�������"<<endl;
			cin>>p;
			cout<<"����������γ̴���"<<endl; 
			int code;
			for(int i=1;i<=p;++i)
			{
				cin>>code;
				roliy.addclass(code);
			} 
			cout<<"������"<<endl; 
		}
		if(ch==3)
		{
			for(int x=1;x<=20;x++)
			{
				outFile<<"��"<<x<<"��"<<endl; 
				for(int y=1;y<=5;++y)
				for(int z=1;z<=7;++z)
				outFile<<roliy.table[y][z][x]<<'\t';
				outFile<<endl; 
			}
		}
		if(ch==4)break;
	cout<<endl; 
	cout<<"1.��ѯ�ܿγ̿�"<<endl; 
	cout<<"2.���γ̱��뽫�γ̴��ܿ���ӵ����˿α�"<<endl;
	cout<<"3.�������˿α�"<<endl; 
	cout<<"4.�����˳�"<<endl;
	}
	outFile.close();
	return 0;
}
