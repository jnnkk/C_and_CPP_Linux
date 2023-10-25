#include <iostream>

using namespace std;

class MyVector{
    int *p;
    int size;
public:
    /* 1. 디폴트 매개변수 방식 */
    MyVector(int n = 100) { 
        p = new int [n]; 
        size = n;
    }
    /* 2. 위임 생성자 방식
    MyVector() : MyVector(100) { }
    MyVector(int n) { 
        p = new int [n]; 
        size = n;
    }
    */
    ~MyVector() { delete [] p; }
};
int main() {
    MyVector *v1, *v2;
    v1 = new MyVector(); 
    v2 = new MyVector(1024);

    delete v1;
    delete v2;
}