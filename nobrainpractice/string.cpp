#include <iostream>

using namespace std;

int main()
{
    int s1 = "Hello";

    cout << s1.length() << endl;

    // length() == size() : 문자열의 길이를 반환

    s1.append(" World");

    // append() : 문자열을 뒤에 추가

    cout << s1 << endl;

    cout << s1.find('W') << endl;

    // find() : 문자열에서 특정 문자의 위치를 반환

    // compare() : 문자열을 비교하여 같으면 0, 다르면 1, -1을 반환

    

    

    return 0;
}