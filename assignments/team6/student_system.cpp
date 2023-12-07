#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
	int ID;
    string name;
    double grade;
public:
    Student(int ID, string name, double grade) {
        this->ID = ID;
        this->name = name;
        this->grade = grade;
    }
    int getID() {
        return ID;
    }
    string getName() {
        return name;
    }
    double getGrade() {
        return grade;
    }
};

int main() {
    int N;
    vector<Student> students;
    cin >> N;
    

    for (int i = 0; i < N; i++) {
        int ID;
        string name;
        double grade;
        
        cin >> ID >> name >> grade;
        students.push_back(Student(ID, name, grade));
    }

    double avg = 0;
    double mid = 0;

    for (auto student : students) {
        avg += student.getGrade();
    }
    avg /= N;

    sort(students.begin(), students.end(), [](Student a, Student b) {
        return a.getGrade() > b.getGrade();
    });

    if (N % 2 == 0) {
        mid = (students[N / 2].getGrade() + students[N / 2 - 1].getGrade()) / 2;
    }
    else {
        mid = students[N / 2].getGrade();
    }

    for (auto student : students) {
        cout << student.getID() << " " << student.getName() << " " << student.getGrade() << endl;
    }

    cout << avg << endl;
    cout << mid << endl;

	return 0;
}