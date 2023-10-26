#include <iostream>
using namespace std;

/** 매개변수: int a, int b 리턴: int*/
int sum(int a, int b) {
    int result = 0;
    for (int i = a; i <= b; i++) {
        result += i;
    }
    return result;
}

/** 매개변수: int a 리턴: int*/
int sum(int a) {
    return sum(1, a);
}

int main() {
    cout << sum(3, 5) << endl;
    cout << sum(3) << endl;
    cout << sum(100) << endl;
}