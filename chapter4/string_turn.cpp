#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    char temp_char;
    string temp_string;

    cout << "Enter string: ";
    getline(cin, s); // 공백입력을 위해 getline 사용

    int len = s.length(); // 문자열 길이

    for (int i = 0; i < len; i++)
    {
        temp_char = s[0];
        temp_string = s.substr(1, len);
        s = temp_string + temp_char;
        cout << s << endl;
    } // 문자열 길이만큼 반복
}