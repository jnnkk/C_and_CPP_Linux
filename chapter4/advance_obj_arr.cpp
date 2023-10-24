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
    Team(int _size){
        size = _size;
        p = new Student[size];
    } //_size 크기의 Student 배열 생성
    ~Team(){
        delete[] p;
        cout << "제거띠" << endl;
    } //동적 할당 메모리 반환

    void setStudent(){
        string name;
        int age;
        for(int i=0; i<size; i++){
            cout<< "Student "<< i+1 << ": ";
            cin>> name >> age;
            p[i] = Student(name, age);
        }
    } //size 만큼 Student 객체 초기화
    void searchName(string _name){
        for(int i=0; i<size; i++){
            if(p[i].getName() == _name){
                cout << p[i].getName() << " " << p[i].getAge() << endl;
                return;
            }
        }
        cout<< "There is no student named "<< _name << endl;
    } //이름 기반 검색 및 결과 출력
    void searchYoung(){
        int min = p[0].getAge();
        for(int i=1; i<size; i++){
            if(p[i].getAge() < min){
                min = p[i].getAge();
            }
        }
        cout<< "Youngest: "<< min << endl;
    } //가장 적은 나이 출력
    void searchOld(){
        int max = p[0].getAge();
        for(int i=1; i<size; i++){
            if(p[i].getAge() > max){
                max = p[i].getAge();
            }
        }
        cout<< "Oldest: "<< max << endl;
    } //가장 많은 나이 출력
};

int main() {
    int n;
    
    cout<< "Enter the number of Students: ";
    cin>> n;
    
    Team team(n);
    team.setStudent();
    
    string targetName;
    cout<< "Enter the target name: ";
    cin>> targetName;
    
    team.searchName(targetName);
    team.searchYoung();
    team.searchOld();
}