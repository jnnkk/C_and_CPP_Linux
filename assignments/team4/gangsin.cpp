#include <iostream>
#include <string>

using namespace std;

void first (int &a, int b) {
    a += b;
}

void second (int &b, int c, int a) {
    b = a * c;
}

void third (int &c, int a, int b) {
    c = a + b;
}

void print (int a, int b, int c) {
    cout << "a: " <<  a << ", b: " << b << ", c: " << c << endl;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    first(a, b);
    second(b, c, a);
    third(c, a, b);
    print(a, b, c);


	return 0;
}