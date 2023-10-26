#include <iostream>

using namespace std;

class Circle {
    int radius; 
    public:
    Circle(); 
    Circle(int r);
    ~Circle();
    void setRadius(int r) { radius = r; }
    double getArea() { return 3.14*radius*radius; }
}; 

Circle::Circle() : Circle(1) {}

Circle::Circle(int r) {
    radius = r;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle() {
    cout << "소멸자 실행 radius = " << radius << endl;
}

int main() {
    int rad;
    while (true) {
        cout << "정수 반지름 입력(음수이면 종료)>> ";
        cin >> rad;
        if (rad < 0) break;
        Circle *cir = new Circle(rad); // 동적 생성
        cout << "원의 면적은 " << cir->getArea() << endl;
        delete cir; // 객체 반환 !꼭 해야함!
    }
}