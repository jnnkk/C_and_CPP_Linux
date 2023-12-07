# include <iostream>
# include <string>

using namespace std;

class DigitSum { // 클래스 이름은 아무렇게나 작성해도 된다.
private:
    int num;     // 자릿수 합 연산을 하려고 하는 숫자
    int sum;     // 각 자릿수를 합하여 나온 숫자
    int count;   // 자릿수 합을 한 횟수
    int result;  // 자릿수 합을 여러 번 거쳐 나온 최종 결과 숫자

public:
    DigitSum(int n);    // 멤버 변수 초기화 및 makeResult 메소드를 한번 실행하여 result 변수에 최종 결과가 대입되도록 한다.
    void doStep();      // 자릿수끼리 합하는 연산을 한번 실행하여 그 결과를 sum 변수에 대입한다.
    void makeResult();  // doStep을 여러 번 반복하여 나온 최종 결과 값을 result 변수에 대입한다.
    int getResult() { return result; }
    int getCount() { return count; }
};

DigitSum::DigitSum(int n) {
    num = n;
    sum = 0;
    count = 0;
    result = 0;
}

void DigitSum::doStep() {
    int temp = num;
    while (temp > 0)
    {
        sum += temp % 10;
        temp /= 10;
    }
    count++;
    num = sum;
    sum = 0;
}

void DigitSum::makeResult() {
    do
    {
        doStep();
    } while (num >= 10);
    result = num;
}

int main() {
    int n;
    cin >> n;
    DigitSum ds(n);
    ds.makeResult();
    cout << ds.getResult() << " " << ds.getCount() << endl;
    return 0;
}