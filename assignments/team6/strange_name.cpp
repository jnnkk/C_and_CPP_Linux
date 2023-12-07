#include <iostream>
#include <cstring>
// <string> 라이브러리 사용 금지

using namespace std;

// 아래의 클래스를 작성한 후 활용
// 복사생성자 활용
class Person {
	char* name;
public:
    Person(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        cout << "+" << endl;
    }
    Person(const Person& p) {
        this->name = new char[strlen(p.name) + 1];
        for (int i = 0; i < strlen(p.name); i++) {
            if (i == 1) {
                this->name[i] = p.name[i + 1];
            } else if (i == 2) {
                this->name[i] = p.name[i - 1];
            } else {
                this->name[i] = p.name[i];
            }
        }
        cout << "#" << endl;
    }
    char* getName() {
        return name;
    }
    ~Person() {
        delete[] name;
    }
};

int main() {
    char name[100];
    cin >> name;
    if (strlen(name) < 3 || strlen(name) > 50) {
        cout << "invalid" << endl;
        return 0;
    }
    Person p1(name);
    Person p2(p1);
    cout << p2.getName() << endl;
    cout << p1.getName() << endl;
    

	return 0;
}