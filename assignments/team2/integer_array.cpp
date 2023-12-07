#include <iostream>

using namespace std;

void calculateSumAndAverage(int* arr, int size, int& sum, double& average) {
    // 배열의 합과 평균을 계산하는 함수 구현

    for (int i = 0 ; i < size ; i++) {
        sum += arr[i];
    }
    average = (double)sum / size;
}

int main() {
    // 사용자로부터 배열의 크기를 입력 받음
    // 동적으로 할당한 배열에 사용자로부터 입력 받은 정수를 저장
    // calculateSumAndAverage 함수를 호출하여 합과 평균을 계산하고 출력
    // 할당한 메모리를 반드시 해제

    int size;
    int sum = 0;
    double average = 0;
    
    cin >> size;
    if (size <= 0) {
        cout << "0" << endl;
        cout << "0.00" << endl;
        return 0;
    }

    int* arr = new int[size];

    for (int i = 0 ; i < size ; i++) {
        cin >> arr[i];
    }

    calculateSumAndAverage(arr, size, sum, average);

    cout << sum << endl;
    // 소수점 두 자리까지 무조건 출력, 세자리에서 반올림
    cout << fixed;
    cout.precision(2);
    cout << average << endl;

    return 0;
}