// 예제 코드

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string input) {
    // 팰린드롬인지 확인
    // 팰린드롬이면 true, 아니면 false 반환
    for (int i = 0; i < input.length() / 2; i++) {
        if (input[i] != input[input.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

string findLongestPalindrome(string input) {
    // 함수 구성
    // 가장긴 팰린드롬 문자열 구하기
    // 팰린드롬이 여러 개일 경우, 가장 긴 팰린드롬 반환

    for (int i = input.length(); i > 0; i--) {
        for (int j = 0; j <= input.length() - i; j++) {
            string sub = input.substr(j, i);
            if (isPalindrome(sub)) {
                return sub;
            }
        }
    }
    return "";
}

int main() {
    string input;
    cin >> input;

    string longestPalindrome = findLongestPalindrome(input);

    cout << longestPalindrome << endl;

    return 0;
}
