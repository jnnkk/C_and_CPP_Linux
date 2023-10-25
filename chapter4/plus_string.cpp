#include <iostream>
#include <string>

using namespace std;

int main() {
    while (true)
    {
        string a;
        int index;
        cout << "수식을 입력하세요: ";
        getline(cin, a); // 공백입력을 위해 getline 사용

        if (a == "0") { break; } // 0 입력시 종료

        /* 혹시 몰라 남겨둔 것, 없어도 작동함
        while(a.find(' ') != -1) {
            a.erase(a.find(' '), 1);
        }
        */

        index = a.find('+'); // '+' 인덱스 찾기

        if (index == -1) {} // '+'가 없으면 아무것도 하지 않음
        else { cout << stoi(a.substr(0, index)) + stoi(a.substr(index + 1)) << endl; }
    }
}