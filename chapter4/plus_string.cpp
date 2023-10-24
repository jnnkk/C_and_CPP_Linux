#include <iostream>
#include <string>

using namespace std;

int main() {
    while (true)
    {
        string a;
        int index;
        cout << "수식을 입력하세요: ";
        getline(cin, a); // 공백입력을 위해 getline 사용

        if (a == "0")
            break;  
        
        while(a.find(' ') != -1) {
            a.erase(a.find(' '), 1);
        }
        
        index = a.find('+');
        if (index == -1){}
        else
            cout << stoi(a.substr(0, index)) + stoi(a.substr(index + 1)) << endl;
    }
    
}