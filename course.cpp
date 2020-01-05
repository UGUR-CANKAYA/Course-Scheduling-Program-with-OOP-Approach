#include "course.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <vector>
using namespace std;
typedef map< int,int > map1;
typedef multimap< int,multimap<string,int> > schedule;
typedef multimap<string,int> days;
course::course()
{
}

int course::getcourseID(void) const
{
	return courseID;
}
void course::setcourseID(const int ID)
{
	courseID=ID;
}
int course::getcourse_hours(void) const
{
	return course_hours;
}
void course::setcourse_hours(int chour)
{
	course_hours;
}
void course::getData(void)
{
	cout<<"Course ID:"<<courseID<<"\t"<<"Course hour: "<<course_hours<<endl;
}
void course::setData(it it1)
{
	static int sum=0,temp;
	cout<<"Enter Course Id : ";
    cin>>temp;
    if(temp>=100000000 &&temp<=999999999)
    {
		setcourseID(temp);
    	sum=sum+it1->second;
		if((sum)<=30) /** Toplam Ders Saatinin 30'u gecip gecmedigi kontrol ediliyor */
		
	
		{
    		cout<<"Enter Course Hours : ";
    		cin>>temp;
    		if(sum+temp<30) 
    		{
				course_hours=temp;
    			++it1;
    		
			}
			else	
				cout<<"You've passed your weekly class hour.\n";
			
    	
    	
		}
		else
		{
			
			cout<<"You've passed your weekly class hour.\n";
			
		}	
	}
	else
	{
		cout<<"Course code has to be 9 digits\n"; /** Ders kodlari 9 haneden olusuyor */
		throw invalid_argument("Course code has to be 9 digits\n");
	}
    
	
		
    	
}
void course::checkSchedule(map1& m)
{
	schedule s1;
	days day1;
	
	map1::iterator it=m.begin();
	schedule::iterator mmpit=s1.begin();
	days::iterator dayit=day1.begin();
	static int i=0,j=0;
	int sum=0;
	string Weekdays[5]={"Monday","Tuesday","Wednesday","Thursday","Friday"};
	for(it;it!=m.end();++it)
	{
		sum=sum+it->second;
	}
	it=m.begin();
	
	while(sum<=30) /**Maksimum Ders saati 30 olabilir.Toplam Ders saati 30 dan buyukse ders programi yapilamaz.Ders silmesi gerekir.**/
	{
		if(it->second >= 6) /** Ders saati 6 dan buyuk esitse */
		{
			for(i;i<6;i++) 
			{
				
				day1.insert(days::value_type(Weekdays[j],++i));  /** Haftanin hangi gunu ve hangi Saatlerde ders oldugunu tutuyor */
				s1.insert(schedule::value_type(it->first,day1)); /**Her dersin ders programini tutuyor. */
				++dayit;
				for(i=0;i<(it->second)-6;i++) /** 6 saatten buyuk dersler bir sonraki gunden devam eder. */
				{
					day1.insert(days::value_type(Weekdays[j],++i));
					s1.insert(schedule::value_type(it->first,day1));
				}
			}
			if(it->second == 6) /** Ders saati 6'ya esitse */
				day1.insert(days::value_type(Weekdays[j],++i));
				s1.insert(schedule::value_type(it->first,day1));
				++j;
				
		}
		else{ /** Ders saati 6 dan kucukse */
			
			for(i=0;i<(it->second);i++)
			{
				day1.insert(days::value_type(Weekdays[j],++i));
				s1.insert(schedule::value_type(it->first,day1));
			}
			}
		if(it==m.end())
			break;	
	}
	if(sum>30)
		throw invalid_argument("You cannot create a schedule because you have passed the weekly course hours.");
		
	dayit=day1.begin();
	mmpit=s1.begin();
	
	while(mmpit!=s1.end())
	{
		cout<<mmpit->first<<" "<<dayit->first<<" "<<dayit->second<<endl;
		++mmpit;
		++dayit;
	}
	
}
