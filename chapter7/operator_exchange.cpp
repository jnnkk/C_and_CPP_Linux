#include <iostream>
using namespace std;

// ☆연산자 교환 법칙이 성립 하려면 멤버 함수가 아닌 전역함수로 구현 해야 적용됨

class Power {
    int kick; 
    int punch; 
public:
    Power(int kick=0, int punch=0) {
        this->kick = kick; this->punch = punch;
    }
    void show();
    friend Power operator + (Power p, int n);
    friend Power operator + (int n, Power p);
    friend Power operator + (Power a, Power b);
};

void Power::show() {
    cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power operator + (Power p, int n) {
    Power tmp;
    tmp.kick = p.kick + n;
    tmp.punch = p.punch + n;
    return tmp;
}

Power operator + (int n, Power p) {
    Power tmp;
    tmp = p + n;
    return tmp;
}

Power operator + (Power a, Power b) {
    Power tmp;
    tmp.kick = a.kick + b.kick;
    tmp.punch = a.punch + b.punch;
    return tmp;
}

int main() {
    Power a(3,5), b, c;
    a.show();
    b.show();
    c.show(); 
    b = a + 2;
    c = 2 + a;
    a = b + c;
    a.show();
    b.show();
    c.show();
}