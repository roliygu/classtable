#include<iostream>
using namespace std;
#ifndef SUBJECT
#define SUBJECT

class Subject
{
	public:
	void makeSubject(string name,int startweek,int endweek,int firweed,int firNo,int secweed,int secNo,string classroom,string teacher,string specialty,int year);
	Subject();
	void showClass() const;
	string myname;
	int mystartweek;
	int myendweek;
	int myfirweed;
	int myfirNo;
	int mysecweed;
	int mysecNo;
	string myclassroom;
	string myteacher;
	string myspecialty;
	int myyear;
};
#endif