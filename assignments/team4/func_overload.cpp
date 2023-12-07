#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int studentID;
    double grade;
public:
	Student(string name = "Unknown", int studentID = 0, double grade = 0.0) {
        this->name = name;
        this->studentID = studentID;
        this->grade = grade;
    }
// TODO: 성적 입력 함수 중복 정의
    void inputGrade(int grade) {
        this->grade = double(grade);
    }
    void inputGrade(double grade) {
        this->grade = grade;
    }
// TODO: 성적 출력 함수 중복 정의
    void displayGrade(bool isLetter) {
        if (isLetter) {
            if (grade >= 90) {
                cout << "A" << endl;
            }
            else if (grade >= 80) {
                cout << "B" << endl;
            }
            else if (grade >= 70) {
                cout << "C" << endl;
            }
            else if (grade >= 60) {
                cout << "D" << endl;
            }
            else {
                cout << "F" << endl;
            }
        }
        else {
            cout << grade << endl;
        }
    }
    void displayGrade() {
        cout << grade << endl;
    }

	void displayStudentInfo() const {
		cout << "Student Information:" << endl;
		cout << "Name: " << name << endl;
		cout << "Student ID: " << studentID << endl;
		cout << endl;
    }
};

int main() {
	Student student1("Alice", 101, 0.0);
	Student student2("Bob", 102, 0);
	
	//To-do: 성적 입력 함수 호출
	
	student1.displayStudentInfo();
	student2.displayStudentInfo();
	
	return 0;
}