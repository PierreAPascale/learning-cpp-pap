// Write your implementation code here
#include "records.h"
#include <string>

Student::Student(int the_id,std::string the_name){
    id = the_id;
    name = the_name;
}
std::string Student::get_name()const{return name;} 
int Student::get_id()const{return id;}

enum class grades{A,B,C,D,F};

Course::Course(int the_id,std::string the_name, unsigned char the_credits){
        id = the_id;
        name = the_name;
        grades gr = grades::(the_credits);
        credits = static_cast<int>(credited_grade);
    }
    public:
    std::string get_name(){return name;}
    int get_id()const{return id;}
    int get_credits()const{return credits;}
    
    private:
    int id;
    std::string name;
    int credits;
};

class Grade{
    Grade(int student_id_i, int course_id_i, unsigned char grade_i){
        student_id = student_id_i;
        course_id = course_id_i;
        grade = grade_i;
    }
    public:
    //int get_student_id(){return student_id;}
    //int get_course_id(){return course_id;}
    unsigned char get_grade()const{return grade;}
    
    private:
    int student_id;
    int course_id;
    unsigned char grade;
};