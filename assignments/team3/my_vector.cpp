#include <iostream>

using namespace std;

class MyVector {
private:
    int* mem;
    int size;
public:
    // 생성자와 복사생성자 활용하여 구성
    MyVector(int n, int val[]) {
        mem = val;
        size = n;
    }
    MyVector(const MyVector& v) {
        mem = new int[v.size];
        size = v.size;
        for (int i = 0; i < size; i++) {
            mem[i] = v.mem[i];
        }
    }
    void print() {
        for (int i = 0; i < size; i++) {
            cout << " " << mem[i];
        }
    }
    ~MyVector() {
        delete[] mem;
    }
};

int main() {

    int len;
    cin >> len;
    int* val = new int[len];
    for (int i = 0; i < len; i++) {
        cin >> val[i];
    }

    MyVector vector1(len, val); // main 함수 구성
    MyVector vector2(vector1);

    // main 함수 구성

    cout << "Original Vector:";
    vector1.print();
    cout << endl;
    cout << "Copied Vector:";
    vector2.print();

    return 0;
}
