#include <iostream>

using namespace std;

class Rectangle {
public:
    int width, height;
    int getArea() {
        return width * height;
    }
};

int main() {
    Rectangle rect;
    rect.width = 3;
    rect.height = 5;
    cout << "Area = " << rect.getArea() << endl;
}