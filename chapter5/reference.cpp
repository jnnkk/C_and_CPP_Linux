#include <iostream>

using namespace std;
class Figure{
public:
    int type;
    int v;
    Figure() { type=-1; v=0;}
    double getAreaCircle() { return 3.14*v *v; }
    double getAreaSquare() { return v * v; }
};

int setFigure(Figure &f){
    int type;
    cout << "Enter type: ";
    cin >> type;
    if(type == 0){
        f.type = 0;
        cout << "Enter v: ";
        cin >> f.v;
    }
    else if(type == 1){
        f.type = 1;
        cout << "Enter v: ";
        cin >> f.v;
    }

    return type;
} // type과 v를 입력받아 Figure 객체 초기화

int main() {
    double area;
    Figure f;
    if(setFigure(f) == 0) area = f.getAreaCircle();
    else area = f.getAreaSquare();   
    cout<< "Area: " << area << endl;
 }