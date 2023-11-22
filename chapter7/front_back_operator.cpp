#include <iostream>
using namespace std;

class Power {
    int kick; 
    int punch; 
public:
    // 생성자
    Power(int kick=0, int punch=0) {
        this->kick = kick; this->punch = punch;
    }
    // 멤버 함수
    void show();
    // 연산자 함수, 프렌드
    friend Power& operator -=(Power& a, int n);
    friend Power& operator --(Power& a);
    friend Power operator --(Power& a, int n);
};
void Power::show() {
    cout << "kick=" << kick << ',' 
        << "punch=" << punch << endl;
}

// 연산자 함수, 프렌드
Power& operator -=(Power& a, int n) {
    a.kick -= n;
    a.punch -= n;
    return a;
}
Power& operator --(Power& a) {
    a.kick--;
    a.punch--;
    return a;
}
Power operator --(Power& a, int n) {
    Power tmp=a;
    a.kick--;
    a.punch--;
    return tmp;
}

int main() {
    Power a(6,5), b, c;
    a.show();
    a -= 2;
    b = --a; 
    c = a--;
    b.show(); 
    c.show();
    a.show();
}
