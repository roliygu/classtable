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
	cout<<"开始于第"<<mystartweek<<"周结束于第"<<myendweek<<"周，在星期"<<myfirweed<<"和星期"<<mysecweed<<"的第"<<myfirNo<<"节课和第"<<mysecNo<<"节课的"<<myclassroom<<"教室"<<endl;
	cout<<"此课程属于"<<myyear<<'-'<<myspecialty<<" 教师："<<myteacher<<endl;
	cout<<endl;
}