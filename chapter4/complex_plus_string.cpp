#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    size_t index = 0;
    int sum = 0;

    cout << "7+23+5+100+25와 같이 덧셈 문자열을 입력하세요. " << endl;
    getline(cin, a); // 공백입력을 위해 getline 사용

    while ((index = a.find('+')) != string::npos) {
        sum += stoi(a.substr(0, index));
        a = a.substr(index + 1);
    }
    sum += stoi(a);
    cout << sum << endl;
}