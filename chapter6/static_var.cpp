#include <iostream>
#include <string>

using namespace std;

void userPrint(string section, string sentence) {
    static int count = 0;
    count++;
    cout << section << " " << count << ": " << sentence << endl;
}

int main() {
    string sec1 = "Section 1";
    userPrint(sec1, "1st sentence");
    userPrint(sec1, "2nd sentence");
    userPrint(sec1, "3rd sentence");

    string sec2 = "Section 2";
    userPrint(sec2, "1st sentence");
    userPrint(sec2, "2nd sentence");
    userPrint(sec2, "3rd sentence");
}