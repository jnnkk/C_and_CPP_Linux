#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string decompressString(string s);


int main() {
    string compressed;
    cout << "압축된 문자열을 입력하세요: ";
    cin >> compressed;

    string decompressed = decompressString(compressed);
    cout << "복원된 문자열: " << decompressed << endl;

    return 0;
}

string decompressString(string s) {

    string result = "";
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ']') {
            string temp = "";
            while (st.top() != '[') {
                temp += st.top();
                st.pop();
            }
            st.pop();
            string repeat = "";
            while (st.top() >= '0' && st.top() <= '9') {
                repeat += st.top();
                st.pop();
                if (st.empty()) break;
            }
            reverse(repeat.begin(), repeat.end());
            int int_repeat = stoi(repeat);
            for (int j = 0; j < int_repeat; j++) {
                for (int k = temp.length() - 1; k >= 0; k--) {
                    st.push(temp[k]);
                }
            }
        } else {
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}