#include <iostream>

using namespace std;

int main()
{
    string s1 = "Hello";

    cout << s1.length() << endl;

    s1.append(" World");

    cout << s1 << endl;

    cout << s1.find('W') << endl;

    

    return 0;
}