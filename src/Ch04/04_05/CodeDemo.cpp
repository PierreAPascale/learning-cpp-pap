// Learning C++ 
// Challenge 04_05
// Calculate a GPA, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include "records.h"

int main(){
    float GPA = 0.0f;
    int id;
    
    std::vector<Student> students = {Student(1, "George P. Burdell"),
                                    Student(2, "Nancy Rhodes")};

    std::vector<Course> courses = {Course(1, "Algebra", 5),
                                Course(2, "Physics", 4),
                                Course(3, "English", 3),
                                Course(4, "Economics", 4)};

    std::vector<Grade> grades = {Grade(1, 1, 'B'), Grade(1, 2, 'A'), Grade(1, 3, 'C'),
                                Grade(2, 1, 'A'), Grade(2, 2, 'A'), Grade(2, 4, 'B')};

    std::cout << "Enter a student ID: " << std::flush;
    std::cin >> id;

    // Calculate the GPA for the selected student.
    // Write your code here

    int sid = 0;
    bool sfound = false;
    while (sid < students.size() && !sfound){
        if (students[sid].get_id() == id) sfound=true;
        else sid++;
    }
    if (sfound){
    std::vector<float> points_by_grade = {4.0f, 3.0f, 2.0f, 1.0f,0.0f};

    float total_pts = 0.0f;
    int total_credits = 0;
    auto grade = grades.begin();
    while ( grade != grades.end()){
    //for (Grade& grade : grades){ //REFERENCE!
        if (grade->get_student_id() == id){ //For that student
            int course_cred = 0;
            float course_pts = 0.0f;

            //int course_id = 0;            
            //course_id = (grade->get_course_id())-1; //only works if ordered cleanly.
            int course_id = 0; //Instead, simplest loop ever: increment "index" until matching course index is found.
            bool cfound = false; //course found
            while (course_id < courses.size() && !cfound){
                 if (courses[course_id].get_id() == grade->get_course_id()) cfound = true;
                 else course_id++; //This loop exits if it looped through all courses, or if it found a course with a matching ID, at index 'course_id')
            }
            if (cfound){
                total_credits += courses[course_id].get_credits();//Get Course's Credits and add to total_credits

                switch(grade->get_grade()){
                    case 'A':
                    course_pts = points_by_grade[0];
                        break;
                    case 'B':
                        course_pts = points_by_grade[1];
                        break;
                    case 'C':
                        course_pts = points_by_grade[2];
                        break;   
                    case 'D':
                        course_pts = points_by_grade[3];
                        break;
                    case 'F':
                        course_pts = points_by_grade[4];
                        break;
                }
                total_pts += courses[course_id].get_credits() * course_pts;// Get Student's Grade in that course and add corresponding points to total
            }       
        }
        grade = next(grade,1);
    }

    GPA = total_pts/total_credits;

    std::string student_str;
    student_str = students[sid].get_name(); 
    std::cout << "The GPA for " << student_str << " is " << GPA << std::endl;
    }
    else std::cout << "Student with ID " << id << " was not found." << std::endl;


    std::cout << std::endl << std::endl;
    return (0);
}
