#include <iostream>
#include <string>

using namespace std;

string removeDuplicates(string s);

int main() {
    string inputStr;
    cout << "문자열을 입력하세요: ";
    cin >> inputStr;

    string result = removeDuplicates(inputStr);
    cout << result << endl;

    return 0;
}


string removeDuplicates(string s) {

    string result = "";
    int len = s.length();

    for (int i = 0; i < len; i++) {
        if (result.find(s[i]) == string::npos) {
            result += s[i];
        }
    }

    return result;
    
}