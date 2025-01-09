// Learning C++ 
// Challenge 06_03
// Upgrade to work with files, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include <fstream>
#include "records.h"


void initialize(StudentRecords&);
void initialize2(StudentRecords&);
void initialize_students(StudentRecords&);
void initialize_courses(StudentRecords&);
void initialize_grades(StudentRecords&);

int main(){
    int id;
    StudentRecords SR;
    
    initialize(SR);

    std::cout << "Enter a student ID: " << std::flush;
    std::cin >> id;

    SR.report_card(id);
    
    std::cout << std::endl << std::endl;
    return (0);
}
void initialize(StudentRecords& srec){
    initialize_students(srec);
    initialize_courses(srec);
    initialize_grades(srec);
}

void initialize2(StudentRecords& srec){
    srec.add_student(1, "George P. Burdell");
    srec.add_student(2, "Nancy Rhodes");

    srec.add_course(1, "Algebra", 5);
    srec.add_course(2, "Physics", 4);
    srec.add_course(3, "English", 3);
    srec.add_course(4, "Economics", 4);

    srec.add_grade(1, 1, 'B');
    srec.add_grade(1, 2, 'A');
    srec.add_grade(1, 3, 'C');
    srec.add_grade(2, 1, 'A'); 
    srec.add_grade(2, 2, 'A');
    srec.add_grade(2, 4, 'B');
}

void initialize_students(StudentRecords& srec){
    std::ifstream inFile;
    std::string temp;
    int sid;
    std::string sname;
    inFile.open("students.txt");
    if (inFile.fail()) 
        std::cout << "Students repository failed to initialize." << std::endl;
    else
        while (!inFile.eof()){
            getline(inFile,temp);
            sid = stoi(temp);
            getline(inFile,sname);
            srec.add_student(sid, sname);
        }
        inFile.close();
}

void initialize_courses(StudentRecords& srec){
    std::ifstream inFile;
    int cid;
    std::string temp;
    unsigned char ccredits;
    std::string cname;
    inFile.open("courses.txt");
    if (inFile.fail()) 
        std::cout << "Courses repository failed to initialize." << std::endl;
    else
        while (!inFile.eof()){
            getline(inFile,temp);
            cid = stoi(temp);
            getline(inFile,cname);
            getline(inFile,temp);
            ccredits = temp[0];
            srec.add_course(cid, cname, ccredits);
        }
        inFile.close();
}
void initialize_grades(StudentRecords& srec){
    std::ifstream inFile;
    std::string temp;
    int sid;
    int cid;
    char grd;
    inFile.open("grades.txt");
    if (inFile.fail())
        std::cout << "Grades repository failed to initialize." << std::endl;
    else
        while (!inFile.eof()){
            getline(inFile,temp);
            sid = stoi(temp);
            getline(inFile,temp);
            cid = stoi(temp);            
            getline(inFile,temp);
            grd = temp[0];
            srec.add_grade(sid, cid,grd);
        }
        inFile.close();
}