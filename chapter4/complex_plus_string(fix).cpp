#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    int index = 0;
    int sum = 0;

    cout << "7+23+5+100+25와 같이 덧셈 문자열을 입력하세요. " << endl;
    getline(cin, a); // 공백입력을 위해 getline 사용

    while (index != -1) {
        index = a.find('+', index);
        sum += stoi(a.substr(0, index));
        a = a.substr(index + 1);
    }
    cout << sum + stoi(a) << endl;
}