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
    int n;
    int count = 0;

    cout << "생성하고자 하는 원의 개수 >> ";
    cin >> n;

    Circle *p = new Circle[n];
    
    for (int i = 0; i < n; i++){
        cout << "원 " << i+1 << "의 반지름 >> " << endl;
        int r;
        cin >> r;
        p[i].setRadius(r);
        if ((p[i].getArea() > 100) && (p[i].getArea() < 200))
            count++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << p[i].getArea() << ' ';
    }
    cout << "면적이 100에서 200 사이인 원은 " << count << "개 입니다." << endl;
    delete [] p;
}