#include <iostream>
#include <string>

using namespace std;

class Date{
    int year;
    int month;
    int day;
public:
    // 생성자
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    Date(string yyyymmdd) {
        year = stoi(yyyymmdd.substr(0, 4));
        month = stoi(yyyymmdd.substr(4, 2));
        day = stoi(yyyymmdd.substr(6, 2));
    }

    // 멤버 함수
    void show() {
        cout << year << "년 " << month << "월 " << day << "일" << endl;
    }
    bool olderThan(Date& other) {
        if (year < other.year)
            return true;
        else if (year == other.year) {
            if (month < other.month)
                return true;
            else if (month == other.month) {
                if (day < other.day)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
    }
};

int main() {
    Date A(2014, 3, 20); // 2014년 3월 20일
    Date B("19990815"); // yyyymmdd
    Date C("20140320"); // yyyymmdd
    Date D(2015, 11, 05); // 2015년 11월 5일
    A.show();
    B.show();
    C.show();
    D.show();
    cout<< "A is older than B: " << A.olderThan(B) << endl;
    cout<< "A is older than C: " << A.olderThan(C) << endl;
    cout<< "A is older than D: " << A.olderThan(D) << endl;
}