#include <iostream>
#include <string>

using namespace std;

string capitalize(string input) {
    string output = "";
    for (int i = 0; i < input.length(); i++) {
        // 소문자는 대문자로
        if (input[i] >= 'a' && input[i] <= 'z') {
            output += input[i] - 'a' + 'A';
        }
        else {
            output += input[i];
        }
    }
    return output;
}

int main() {
	string input;
	
    getline(cin, input);
    cout << capitalize(input) << endl;
	
	return 0;
}