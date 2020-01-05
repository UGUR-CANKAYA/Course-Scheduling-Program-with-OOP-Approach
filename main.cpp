/** *****************************************************************************
 * Bu programla ders kaydi yapabilirsiniz
 * Once dersler ekleniyor sonra ogrenci ekle seceneginden ogrenci ekleniyor
 * Ogrenciye kaç ders istedigi soruluyor.
 * Kayitli ders girmediginde uyariliyor.
 * Devam seceneginde n ye basilinca ders programý oluþturuluyor.
 * Ders listesi(Course List) secenegiden kayitli derslere bakilabiliyor.
 * Öðrenci listesi(Student List) seçeneðinden kayitli öðrencilere bakilabiliyor.
 ***************************************************************************** */
 /** ***********************************************************
 * Project name	:	Scheduling courses in a semester	
 * Author		:	UGUR CANKAYA		
 * Date			:	02.01.2020
 * Description	:	You can register courses with this program
 * ********************************************************** */
#include "course.h"
#include "student.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

typedef map< int,int > map1;
typedef map< string,vector<int> > map2;
typedef multimap< int,multimap<string,int> > schedule;
typedef vector<int> vector1;
void printCourse(map1 &l);
void printStudent(map2& m);


main()
{
	map1 courses;
	map2 students;
	map1::iterator it1=courses.begin();
	vector1 course1;
	int choice,i;
	char c;
	a:
		
	cout<<"------MENU------\n";
	cout<<"- 1.Add Student\n";
	cout<<"- 2.Add Course\n";
	cout<<"- 3.Student List\n";
	cout<<"- 4.Course List\n";
	cout<<"- 5.Exit\n";
	cout<<"Select from menu: ";
	
	
	cin>>choice;
	switch(choice)
	{
		
		case 1: /**Add Student*/
			system("cls");
			if(courses.size()!=0)
			{
				while(1)
				{
				int j;
				course c1;
				cout<<"Number of courses: "<<courses.size()<<endl;
				cout<<"how many lessons do you want:";
				cin>>i;
				student s1;
    			for(j=0;j<i;j++)
				{
					s1.setData(courses);
					course1.push_back(s1.getcourse());
				}
				students.insert(map2::value_type(s1.getstudentID(),course1));
				cout<<"\nContinue(y/n): ";
				cin>>c;
				if(c=='n')
				{
					c1.checkSchedule(courses);
					break;
				}	
				}
				cout<<"Press 0 to return to the main menu: ";
				cin>>c;
				if(c=='0')
				{
					system("cls");
					goto a;	
				}	
			}
			else
			{
				cout<<"No courses registered.\n";
				cout<<"Add the course first and then try again.\n";
				cout<<"Press 0 to return to the main menu: ";
				cin>>c;
				if(c=='0')
				{
					system("cls");
					goto a;	
				}
			}
		break;
		
		case 2: /**Add Course*/
			system("cls");
			while(1)
			{
				course c1;
				c1.setData(it1);
				courses.insert(map1::value_type(c1.getcourseID(),c1.getcourse_hours()));
				
				cout<<"\nContinue(y/n): ";
				cin>>c;
				if(c =='n')
				{
					break;
				}	
					
			}
			cout<<"Press 0 to return to the main menu: ";
			cin>>c;
			if(c=='0')
			{
				system("cls");
				goto a;	
			}
			
		case 3: /**Student List*/
			system("cls");
			printStudent(students);
			
			cout<<"Press 0 to return to the main menu: ";
			cin>>c;
			if(c=='0')
			{
				system("cls");
				goto a;	
			}
		case 4: /**Course List*/
			system("cls");
			printCourse(courses);
			
			cout<<"Press 0 to return to the main menu: ";
			cin>>c;
			if(c=='0')
			{
				system("cls");
				goto a;	
			}
			
		case 5:	
			break;
				
		default:
			cout<<"You choice is invalid!!\n";
			break;
			
	}
}
void printCourse(map1 &m)
{
	
	cout<<"Course ID \t Course Hours\n";
	for(map1::iterator it=m.begin();it!=m.end();++it) /** Dersler yaziliyor */
	{
		cout<<it->first<<" \t "<<it->second<<endl;
	}
}
void printStudent(map2 &m)
{
	
	cout<<"Student ID\n";
	for(map2::iterator it=m.begin();it!=m.end();++it) /** Ogrenciler yaziliyor */
	{
		cout<<it->first<<endl;	
	}
}

