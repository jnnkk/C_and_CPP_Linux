#include <iostream>

using namespace std;

class Student {
    string name;
    int age;
public:
    Student() { name = ""; age = 0; }
    Student(string _name, int _age) {
        name = _name;
        age = _age;
    }
    string getName() { return name; }
    int getAge() { return age; }
};

class Team {
    Student* p;
    int size;
public:
    Team(int _size); //_size 크기의 Student 배열 생성
    ~Team(); //동적 할당 메모리 반환
    void setStudent(); //size 만큼 Student 객체 초기화
    void searchName(string _name); //이름 기반 검색 및 결과 출력
    void searchYoung(); //가장 적은 나이 출력
    void searchOld(); //가장 많은 나이 출력
};

Team::Team(int _size) {
    size = _size;
    p = new Student[_size];
}

Team::~Team() {
    delete[] p;
}


void Team::setStudent() {
    for (int i = 0; i < size; i++) {
        string name;
        int age;
        cout << "Student " << i + 1 << ": ";
        cin >> name >> age;
        p[i] = Student(name, age);
    }
}

void Team::searchName(string _name) {
    for (int i = 0; i < size; i++) {
        if (p[i].getName() == _name) {
            cout << p[i].getName() << " " << p[i].getAge() << endl;
        }
    }
}

void Team::searchYoung() {
    int min = 100000;
    for (int i = 0; i < size; i++) {
        if (p[i].getAge() < min) {
            min = p[i].getAge();
        }
    }
    cout << "Youngest: " << min << endl;
}

void Team::searchOld() {
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (p[i].getAge() > max) {
            max = p[i].getAge();
        }
    }
    cout << "Oldest: " << max << endl;
}

int main() {
    int n;
    cout << "Enter the number of Students: ";
    cin >> n;

    Team team(n);
    team.setStudent();

    string targetName;
    cout << "Enter the target name: ";
    cin >> targetName;

    team.searchName(targetName);
    team.searchYoung();
    team.searchOld();
}