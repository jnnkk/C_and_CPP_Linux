#include <iostream>

using namespace std;

class Circle {
public:
    int radius;
    Circle() {
        radius = 1;
        cout<< "+r=" << radius << endl;
    }
    Circle(int radius) {
        this->radius = radius;
        cout<< "+r=" << radius << endl;
    }
    Circle(Circle &c) {
        this->radius = c.radius+ 1;
        cout<< "#r=" << radius << endl;
    }
    ~Circle() {
        cout<< "-r=" << radius << endl;
    }
    void setRadius(int radius) { this->radius = radius; }
    int getRadius () { return radius; }
};

Circle getCircle1() {
    Circle c(2);
    return c;
}
Circle getCircle2(Circle c) {
    return c;
}
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