
#ifndef SRC_STUDENT_H_
#define SRC_STUDENT_H_

#include <string>
using namespace std;

class Student {
private:
    string name;
    int grade;

public:
    Student(const string& name, int grade);

    string getName() const;
    int getGrade() const;

    void setName(const string& name);
    void setGrade(int grade);
};

#endif /* SRC_STUDENT_H_ */
