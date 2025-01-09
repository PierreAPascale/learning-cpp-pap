// Learning C++ 
// Exercise 05_01
// Creating Functions, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include "records.h"

void initialize(StudentRecords&);


int main(){

    int id;
    StudentRecords *records;
    records = new StudentRecords();
    initialize(*records);

    std::cout << "Enter a student ID: " << std::flush;
    std::cin >> id;
    std::cout << "The GPA for " << records->get_student_name(id) << " is " << records->get_GPA(id) << std::endl;
    
    std::cout << std::endl << std::endl;
    return (0);
}

void initialize(StudentRecords& records){
    records.add_student(1, "George P. Burdell");
    records.add_student(2, "Nancy Rhodes");

    records.add_course(1, "Algebra", 5);
    records.add_course(2, "Physics", 4);
    records.add_course(3, "English", 3);
    records.add_course(4, "Economics", 4);

    records.add_grade(1, 1, 'B');
    records.add_grade(1, 2, 'A');
    records.add_grade(1, 3, 'C');
    records.add_grade(2, 1, 'A');
    records.add_grade(2, 2, 'A');
    records.add_grade(2, 4, 'B');
};
