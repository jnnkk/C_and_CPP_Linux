#include <iostream>
#include <string>

using namespace std;

namespace LeapYear {
    bool isLeapYear(int year) {
        if (year % 400 == 0) {
            return true;
        }
        else if (year % 100 == 0) {
            return false;
        }
        else if (year % 4 == 0) {
            return true;
        }
        else {
            return false;
        }
    }
}

int main() {
    int year;
    cin >> year;

    if (LeapYear::isLeapYear(year)) {
        cout << "입력한 연도는 윤년입니다." << endl;
    }
    else {
        cout << "입력한 연도는 윤년이 아닙니다." << endl;
    }

	return 0;
}