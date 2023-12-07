#include <iostream>
#include <string>

using namespace std;

double calculateArea(double a, double b, double c) {
    if (c == 0) {
        return a * b / 2.0;
    } else {
        return (a + b) * c / 2.0;
    }
}

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    cout << calculateArea(a, b, c) << endl;

	return 0;
}