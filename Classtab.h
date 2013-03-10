#include<iostream>
#include "Subject.h" 
using namespace std;
#ifndef CLASSTAB
#define CLASSTAB

class Classtab
{
	public:
	Classtab();
	void addclass(const int n);
	void deleteclass(string name);
	void searchclass(int year,string specialty) const;
	void searchclass(string name) const;
	void addtotTable(Subject name);
	string table[10][10][25];
	private:
	Subject totTable[150];
	int classSize;
};
#endif