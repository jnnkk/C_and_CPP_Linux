#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
class Person { // Person 클래스 선언
    char* name;
    int id;
public:
    Person(int id, const char* name); // 생성자
    Person(const Person& person); // 복사 생성자
    ~Person(); // 소멸자
    void changeName(const char *name);
    void show() { cout << id << ',' << name << endl; }
};

Person::Person(int id, const char* name) { // 생성자
    this->id = id;
    int len = strlen(name); // name의 문자 개수
    this->name = new char [len+1]; // name 문자열 공간 핟당
    strcpy(this->name, name); // name에 문자열 복사
}

Person::Person(const Person& person){
    this->id = person.id;
    int len = strlen(person.name);
    this->name = new char [len+1];
    strcpy(this->name, person.name);
    cout << "복사 생성자 실행, 원본 객체의 이름: " << this->name << endl;
}

Person::~Person() {
    if(name) delete[] name;
}

void Person::changeName(const char *name) {
    if(strlen(name) > strlen(this->name)) return;
    strcpy(this->name, name);
}

void f(Person person) { // Person 객체를 인자로 받는 함수
    person.changeName("dummy");
}

Person g() {
    Person mother(2, "Jane");
    return mother;
}

int main() {
    Person father(1, "Kitae");
    Person son = father;
    f(father);
    g();
}