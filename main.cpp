#include <iostream>
#include "Subject.h" 
#include "Classtab.h"
#include<fstream>
using namespace std;

int main(int argc, char *argv[])
{
	cout<<"欢迎使用本课程管理程序，正在导入课程信息，请确保 '课程.txt'在'd:\\课程.txt'路径下" <<endl; 
	ifstream f("d:\\课程.txt",ios::in);
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
	cout<<"导入成功，请选择操作："<<endl;
	int ch;
	cout<<"1.查询总课程库"<<endl; 
	cout<<"2.按课程编码将课程从总库添加到个人课表"<<endl;
	cout<<"3.导出个人课表"<<endl; 
	cout<<"4.结束退出"<<endl;
	cout<<endl;
	ofstream outFile("d:\\我的课表.txt",ios::out);
	while(cin>>ch)
	{
		if(ch==1)
		{
			cout<<"1.按专业，入学年份查询；2.按课程名查询；请输入："<<endl;
			int ch2;
			cin>>ch2;
			if(ch2==1)
			{
				string sname;
				int year1;
				cout<<"请输入专业名与入学年份，以空格间隔"<<endl; 
				cin>>sname>>year1;
				roliy.searchclass(year1,sname);
			}
			if(ch2==2)
			{
				string sname1;
				cout<<"请输入课程名称"<<endl; 
				cin>>sname1;
				roliy.searchclass(sname1);
			}
		}
		if(ch==2)
		{
			int p;
			cout<<"要添加多少门课程呢？请输入"<<endl;
			cin>>p;
			cout<<"请依次输入课程代码"<<endl; 
			int code;
			for(int i=1;i<=p;++i)
			{
				cin>>code;
				roliy.addclass(code);
			} 
			cout<<"添加完成"<<endl; 
		}
		if(ch==3)
		{
			for(int x=1;x<=20;x++)
			{
				outFile<<"第"<<x<<"周"<<endl; 
				for(int y=1;y<=5;++y)
				for(int z=1;z<=7;++z)
				outFile<<roliy.table[y][z][x]<<'\t';
				outFile<<endl; 
			}
		}
		if(ch==4)break;
	cout<<endl; 
	cout<<"1.查询总课程库"<<endl; 
	cout<<"2.按课程编码将课程从总库添加到个人课表"<<endl;
	cout<<"3.导出个人课表"<<endl; 
	cout<<"4.结束退出"<<endl;
	}
	outFile.close();
	return 0;
}
