#include <iostream>

using namespace std;

class Rectangle {
public:
    int width, height;
    Rectangle();
    Rectangle(int width);
    Rectangle(int width, int height);
    int isSquare();
    int getArea() { return width * height; }
}; // 클래스 선언

Rectangle::Rectangle():Rectangle(1, 1) {} // 위임생성자 및 생성자

Rectangle::Rectangle(int width):Rectangle(width, width) {}

Rectangle::Rectangle(int width, int height) {
    this->width = width;
    this->height = height;
} // 생성자

int Rectangle::isSquare() {
    if (width == height) {
        return 1;
    }
    else {
        return 0;
    }
} // 멤버함수

int main() {
    Rectangle rect1;
    Rectangle rect2(3, 5);
    Rectangle rect3(3);

    cout << "rect1의 면적은 " << rect1.getArea() << endl;
    cout << "rect2의 면적은 " << rect2.getArea() << endl;
    cout << "rect3의 면적은 " << rect3.getArea() << endl;
}