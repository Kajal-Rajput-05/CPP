

#include "Student.h"
using namespace std;

Student::Student(const std::string& name, int grade) : name(name), grade(grade) {}

string Student::getName() const {
    return name;
}

int Student::getGrade() const {
    return grade;
}

void Student::setName(const string& name) {
    this->name = name;
}

void Student::setGrade(int grade) {
    this->grade = grade;
}



