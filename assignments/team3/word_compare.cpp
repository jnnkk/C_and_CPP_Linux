#include <iostream>
#include <string>

using namespace std;

int main() {
    string *str1;
    string *str2;

    str1 = new string;
    str2 = new string;

    cin >> *str1 >> *str2;

    // 두 문자열이 같은지 비교
    if (*str1 == *str2) {
        cout << "같음";
    }
    else {
        cout << "다름";
    }
    
}