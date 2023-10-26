#include <iostream> 

using namespace std; 

class Test {
    char s; 
public:
    Test(char c); 
    ~Test();
    void fun() { Test a('a'); }
}; 
Test::Test(char c) {
    s = c;
    cout << "+" << s << endl;
}
Test::~Test() {
    cout << "-" << s << endl;
}

Test b('b');

void fun() {
    Test c('c');
    c.fun();
}

Test d('d'), e('e');

int main() {
    fun();
    Test f('f');
}
Test g('g');

// 일단 다 읽고 메인함수 실행, 그래서 g가 먼저 생김
