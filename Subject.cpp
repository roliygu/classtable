#include<cassert>
#include<new>
using namespace std;
#include "Subject.h"
void Subject::makeSubject(string name,int startweek,int endweek,int firweed,int firNo,int secweed,int secNo,string classroom,string teacher,string specialty,int year)
{
	myname=name;
	mystartweek=startweek;
	myendweek=endweek;
	myfirweed=firweed;
	myfirNo=firNo;
	mysecweed=secweed;
	mysecNo=secNo;
	myclassroom=classroom;
	myteacher=teacher;
	myspecialty=specialty;
	myyear=year;
}
Subject::Subject()
{}
 void Subject::showClass() const
{
	cout<<myname<<endl;
	cout<<"��ʼ�ڵ�"<<mystartweek<<"�ܽ����ڵ�"<<myendweek<<"�ܣ�������"<<myfirweed<<"������"<<mysecweed<<"�ĵ�"<<myfirNo<<"�ڿκ͵�"<<mysecNo<<"�ڿε�"<<myclassroom<<"����"<<endl;
	cout<<"�˿γ�����"<<myyear<<'-'<<myspecialty<<" ��ʦ��"<<myteacher<<endl;
	cout<<endl;
}