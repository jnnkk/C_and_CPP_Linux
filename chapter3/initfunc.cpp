#include <iostream>

using namespace std;

class Student {
    int Year, ID, Grade;
public:
    Student();
    Student(int y, int i, int g);
    void setData(int y, int i, int g){
        Year = y;
        ID = i;
        Grade = g;
    }
    void showData() {
        cout << "Year: " << Year << ", ID: " << ID << ", Grade: " << Grade << endl;
    }
};
Student::Student(): Student(0, 0, 0){
}
Student::Student(int y, int i, int g) {
    setData(y, i, g);
}

int main() {
    Student s(2018, 100, 3);
    s.showData();
    return 0;
}