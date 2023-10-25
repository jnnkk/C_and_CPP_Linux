#include <iostream>
#include <string>

using namespace std;

class MemCalc {
public:
    static int memory(int a) {
        static int mem = 0;
        mem += a;
        return mem;
    }
    static int add(int a, int b) {
        return a + b;
    }
    static int addMemory(int a) {
        return memory(a);
    }
};

int main() {
    int a, b, c;
    a = MemCalc::add(1, 2);
    MemCalc::memory(a);

    b = MemCalc::add(10, 5);
    c = MemCalc::addMemory(10);
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
}