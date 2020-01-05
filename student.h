#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <map>

using namespace std;
typedef map< int,int > map1;
class student
{
	
	public:
		student();
		
		int getcourse(void) const;
		void setcourse(const int);
		string getstudentID(void) const;
		void setstudentID(const string);
		void getData(void);
		void setData(map1);
		
		
	private:
		string studentID;
		int course;
		
		
};

#endif
