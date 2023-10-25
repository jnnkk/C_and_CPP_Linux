#include <iostream>

using namespace std;

void f(char c = '*', int n = 1) {
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < 10; i++) {
            cout << c;
        }
        cout << endl;
    }
}

int main() {
    f(); // 한줄에 '*'를 10개 출력한다.
    f('%'); // 한 줄에 '%'를 10개 출력한다.
    f('@', 5); // 5 줄에 '@' 문자를 10개 출력한다.
}