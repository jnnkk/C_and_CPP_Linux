#include <iostream>
using namespace std;

// A 클래스
class A {
    int aa;
public:
    A(int _aa = 0) { aa = _aa; }
    void printA() { cout << "aa=" << aa << endl; }
};

// B 클래스
class B : public A {
    int bb;
public:
    B(int _aa = 0, int _bb = 0) : A(_aa) { bb = _bb; }
    void printB() { 
        printA();
        cout << "bb=" << bb << endl;
    }
};

// C 클래스
class C : public B {
    int cc;
public:
    C(int _aa = 0, int _bb = 0, int _cc = 0) : B(_aa, _bb) { cc = _cc; }
    void printC() {
        printB();
        cout << "cc=" << cc << endl; 
    }
};

int main() { 
    C y(1, 2, 3); //aa, bb, cc 초기값
    y.printC();
}
