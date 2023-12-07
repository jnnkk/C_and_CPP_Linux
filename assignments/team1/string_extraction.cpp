#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int op[4] = { -1, -1, -1, -1 };

// 주어진 문자열에서 숫자를 제외하고 문자만 추출해내는 함수
string string_extraction(string s) {
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            result += s[i];
        }
    }
    return result;
}

// 주어진 문자열에서 숫자를 찾아내는 함수
// 찾은 숫자는 순서대로 리스트에 저장
vector<int> number_extraction(string s) {
    vector<int> result;
    int num = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
        }
        else {
            if (num != 0) {
                result.push_back(num);
                num = 0;
            }
        }
    }
    if (num != 0) {
        result.push_back(num);
    }
    return result;
}

void find_op(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s.find("add") != string::npos) {
            op[0] = s.find("add");
        }
        if (s.find("subtract") != string::npos) {
            op[1] = s.find("subtract");
        }
        if (s.find("multiply") != string::npos) {
            op[2] = s.find("multiply");
        }
        if (s.find("divide") != string::npos) {
            op[3] = s.find("divide");
        }
    }
}

void print_result(int op[], vector<int> numlist) {
    vector<int> op_list;

    for (int i = 0; i < 4; i++) {
        if (op[i] == -1) {
            continue;
        }
        else {
            op_list.push_back(op[i]);
        }
    }
    sort(op_list.begin(), op_list.end());

    int op_size = op_list.size();
    int present_op = 0;
    for (int i = 0; i < 4 ; i++) {
        if (op_list[0] == op[i]) {
            present_op = i;
        }
    }
    if (op_size > 1) {
        op_list.erase(op_list.begin());
    }
    

    int result = numlist[0];
    numlist.erase(numlist.begin());


    for (auto i : numlist) {
        if (present_op == 0) {
            result += i;
        }
        else if (present_op == 1) {
            result -= i;
        }
        else if (present_op == 2) {
            result *= i;
        }
        else if (present_op == 3) {
            result /= i;
        }
        op_size = op_list.size();
        for (int i = 0; i < 4 ; i++) {
            if (op_list[0] == op[i]) {
                present_op = i;
            }
        }
        if (op_size > 1) {
            op_list.erase(op_list.begin());
        }
    }

    cout << result << endl;
}


int main() {

    string s1, s2;
    cin >> s1;

    s2 = string_extraction(s1);
    auto numlist = number_extraction(s1);
    find_op(s2);
    print_result(op, numlist);
	return 0;
}