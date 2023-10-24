#include <iostream>

using namespace std;

class Circle {
    int radius; 
    public:
    Circle(); 
    ~Circle() { }
    void setRadius(int r) { radius = r; }
    double getArea() { return 3.14*radius*radius; }
}; 
Circle::Circle() {
    radius = 1;
}

int main() {
    int num;
    int count = 0;
    cout << "생성하고자 하는 원의 개수? ";
    cin >> num;
    Circle *pArrayCircle = new Circle[num];
    for (int i = 0; i < num; i++) {
        cout << "원 " << i + 1 << ": ";
        int rad;
        cin >> rad;
        pArrayCircle[i].setRadius(rad);
    }
    for (int i = 0; i < num; i++) {
        double area = pArrayCircle[i].getArea();
        if (area >= 100 && area <= 200) count++;
        cout << area << " ";
    }
    cout << endl << "면적이 100에서 200사이인 원의 개수는 " << count << endl;
    delete[] pArrayCircle;
}