#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    int year;
    int id;
    int grade;
    Student();
    Student(int year, int id, int grade);
    void setData(int year, int id, int grade);
    void showData();
};

Student::Student() {
    year = 0;
    id = 0;
    grade = 0;
}

void Student::setData(int year, int id, int grade) {
    this->year = year;
    this->id = id;
    this->grade = grade;
} // 멤버함수

Student::Student(int year, int id, int grade) {
    setData(year, id, grade);
} // 생성자를 함수로 구현

void Student::showData() {
    cout << "Year: " << year << " ID: " << id << " Grade: " << grade << endl;
}

int main () {
    Student s;
    s.setData(2019, 123456, 3);
    s.showData();
}