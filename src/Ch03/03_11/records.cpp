// Write your implementation code here
#include "records.h"
#include <string>

Student::Student(int the_id,std::string the_name){
    id = the_id;
    name = the_name;
}
std::string Student::get_name()const{return name;} 
int Student::get_id()const{return id;}

//enum class grades{A,B,C,D,F};

//Course definition
Course::Course(int the_id,std::string the_name, unsigned char the_credits){
        id = the_id;
        name = the_name;
        credits = int(the_credits);
        /* //With enum?
        grades gr = grades::A;
        
        switch(the_credits){
            case 'A':
                gr = grades::A;
                break
            case 'B':
                gr = grades::B;
                break
            case 'C':
                gr = grades::C;
                break
            case 'D':
                gr = grades::D;
                break
            case 'F':
                gr = grades::F;
                break            
        }
        credits = (int)gr;
        */
    }
std::string Course::get_name()const{return name;}
int Course::get_id()const{return id;}
int Course::get_credits()const{return credits;}

//Grade definition
Grade::Grade(int sid, int cid, char grd){
    student_id = sid;
    course_id = cid;
    grade = grd;
}
int Grade::get_student_id()const{return student_id;}
int Grade::get_course_id()const{return course_id;}
char Grade::get_grade()const{return grade;}