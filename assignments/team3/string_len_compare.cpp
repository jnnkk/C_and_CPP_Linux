#include <iostream>
#include <string>

using namespace std;

int main() {
	string* str1, *str2;
	str1 = new string;
    str2 = new string;

    cin >> *str1;
    cin >> *str2;

    if (str1->length() == str2->length()) {
        cout << "동일한 길이입니다." << endl;
    }
    else {
        cout << "다른 길이입니다." << endl;
    } 

    delete str1;
    delete str2;
	
	return 0;
}