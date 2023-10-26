#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char password[100] = "C++";
    char answer[100];

    cout << "프로그램을 종료하려면 암호를 입력하세요." << endl;
    while (true)
    {
        cout << "암호: ";
        cin >> answer;
        if (!strcmp(password, answer)) // password와 answer가 같으면 0을 반환
        {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else
            cout << "암호가 틀렸습니다." << endl;
    }
        
}