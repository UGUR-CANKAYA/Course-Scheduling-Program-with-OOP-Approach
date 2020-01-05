#include "student.h"
#include <iostream>
#include <cstdio>
#include <stdexcept>
#include <iomanip>
#include <map>
#include <vector>
using namespace std;

student::student()
{
	
}
string student::getstudentID(void) const
{
	return studentID;
}
void student::setstudentID(const string ID)
{
	studentID=ID;
}
void student::getData(void)
{
	cout<<"Student ID:"<<getstudentID()<<"\t"<<endl;
}
void student::setData(map1 m)
{
	static int i=0,j;
	if(i<=0)
	{
		cout<<"Enter Student Id : ";
		cin>>studentID;
	}
	b:
	cout<<"Enter Course of Student: ";
	cin>>j;
	if(m.count(j)>0)
	{
		setcourse(j);
	}
	else
	{
		cout<<"The course you entered is invalid\n";
		goto b;	
	}
	++i;
}

int student::getcourse(void) const
{
	return course;
}
void student::setcourse(const int c)
{
	course=c;
}
