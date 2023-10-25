#include <iostream>

using namespace std;

class MyStack{
    int *p; //스택 메모리 주소
    int size;//스택 최대 크기
    int tos; //스택의 탑 인덱스
public:
    MyStack(int size){
        p = new int[size];
        this->size = size;
        tos = 0;
    } // 생성자
    MyStack(const MyStack &tmp){
        p = new int[tmp.size];
        size = tmp.size;
        tos = tmp.tos;
        for(int i=0; i<tos; i++){
            p[i] = tmp.p[i];
        }
    } // 복사 생성자
    ~MyStack(){
        delete[] p;
    } // 소멸자
    

    /* 멤버함수 */

    void push(int n){
        p[tos] = n;
        tos++;
    }
    void pop(int &n){
        tos--;
        n = p[tos];
    } // pop() 함수는 매개변수로 받은 변수에 값을 저장
};

int main() {
    MyStack a(10);
    a.push(10);
    a.push(20);

    MyStack b = a;
    b.push(30);

    int popA, popB;
    a.pop(popA);
    b.pop(popB);
    
    cout << "a.pop: " << popA << endl;
    cout << "b.pop: " << popB << endl;
}