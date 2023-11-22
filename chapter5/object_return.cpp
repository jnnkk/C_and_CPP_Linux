#include <iostream>

using namespace std;

class Circle {
public:
    int radius;

    // 생성자
    Circle() {
        radius = 1;
        cout<< "+r=" << radius << endl;
    }
    Circle(int radius) {
        this->radius = radius;
        cout<< "+r=" << radius << endl;
    }

    // 복사 생성자
    Circle(Circle &c) {
        this->radius = c.radius+ 1;
        cout<< "#r=" << radius << endl;
    }

    // 소멸자
    ~Circle() {
        cout<< "-r=" << radius << endl;
    }

    // 멤버 함수
    void setRadius(int radius) { this->radius = radius; }
    int getRadius () { return radius; }
};


// 함수
Circle getCircle1() {
    Circle c(2);
    return c;
} // 복사 생성자 호출 안됨

Circle getCircle2(Circle c) {
    return c;
} // 복사 생성자 호출 됨

// main 함수
int main() {
    Circle c; 
    cout<< c.getRadius() << endl;
    c = getCircle1(); 
    cout<< c.getRadius() << endl;
    c = getCircle2(c); 
    cout<< c.getRadius() << endl;
}

/*
+r=1
1
+r=2
-r=2
2
#r=3
#r=4
-r=4
-r=3
4
-r=4
*/