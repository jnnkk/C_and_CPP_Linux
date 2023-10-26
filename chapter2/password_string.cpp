#include <iostream>
#include <string> // string 클래스를 사용하기 위해 필요, 신

using namespace std;

int main() {
    string password("C++");
    string answer;

    cout << "프로그램을 종료하려면 암호를 입력하세요." << endl;
    while (true)
    {
        cout << "암호: ";
        cin >> answer;
        if (password == answer)
        {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else
            cout << "암호가 틀렸습니다." << endl;
    }
        
}