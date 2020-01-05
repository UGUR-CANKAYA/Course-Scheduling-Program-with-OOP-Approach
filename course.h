#ifndef COURSE_H
#define COURSE_H
#include <map>
#include <vector>
using namespace std;
typedef map< int,int > map1;
typedef map< int,int >::iterator it;
typedef vector<int> vector1;
class course
{
	public:
		course();
		
		int getcourseID(void) const;
		void setcourseID(const int);
		
		int getcourse_hours(void) const;
		void setcourse_hours(const int);
		
		void getData(void);
		void setData(it);
		void checkSchedule(map1& m);
		
	private:
		int courseID;
		int course_hours;
};

#endif
