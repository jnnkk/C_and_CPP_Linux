#include <iostream>
using namespace std;


class Point {
    int x, y;
public:
    Point(int _x, int _y) {
        setXY(_x, _y);
    }
    void setXY(int _x, int _y) { x = _x; y = _y; }
    void showXY() { cout << x << ", " << y << endl; }
    void getXY(int& _x, int& _y) { _x = x; _y = y; }
};

class ColorPoint : public Point {
    string color;
public:
// ☆명시적 기본 클래스 생성자 선택
    ColorPoint(int _x = 0, int _y = 0, string _color = "r") : Point(_x, _y) {
        color = _color;
    }
    void showXYC() {
        cout << color << ":";
        showXY();
    }
    void setXYC(int _x, int _y, string _color) {
        setXY(_x, _y);
        color = _color;
    }
    void getXYC(int& _x, int& _y, string& _color) {
        int x, y;
        getXY(x, y);
        _x = x;
        _y = y;
        _color = color;
    }
};

int main() {
    ColorPoint a;
    a.showXYC();

    a.setXY(5, 5);
    a.showXYC();

    ColorPoint b(10, 10, "g");
    b.showXYC();

    int x, y;
    string color;
    b.getXYC(x, y, color);
    
    ColorPoint c;
    c.setXYC(x, y, color);
    c.showXYC();
}