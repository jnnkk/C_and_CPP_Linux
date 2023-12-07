#include <iostream>
using namespace std;

class Deque {
private:
    string *deque;
    int begin, end;

public:
    Deque(int n) {
        deque = new string[n];
        begin = -1;
        end = -1;
    }

    void push_front(string s) {
        if (begin == -1) {
            begin = 0;
            end = 0;
            deque[begin] = s;
        }
        else if (begin == 0) {
            begin = sizeof(deque) - 1;
            deque[begin] = s;
        }
        else {
            begin--;
            deque[begin] = s;
        }
    }
    void push_back(string s) {
        if (end == -1) {
            begin = 0;
            end = 0;
            deque[end] = s;
        }
        else if (end == sizeof(deque) - 1) {
            end = 0;
            deque[end] = s;
        }
        else {
            end++;
            deque[end] = s;
        }
    
    }
    void pop_front() {
        if (begin == -1) {
            cout << "-1" << endl;
        }
        else if (begin == end) {
            cout << deque[begin] << endl;
            begin = -1;
            end = -1;
        }
        else if (begin == sizeof(deque) - 1) {
            cout << deque[begin] << endl;
            begin = 0;
        }
        else {
            cout << deque[begin] << endl;
            begin++;
        }
    }
    void pop_back() {
        if (end == -1) {
            cout << "-1" << endl;
        }
        else if (begin == end) {
            cout << deque[end] << endl;
            begin = -1;
            end = -1;
        }
        else if (end == 0) {
            cout << deque[end] << endl;
            end = sizeof(deque) - 1;
        }
        else {
            cout << deque[end] << endl;
            end--;
        }
    }
    void size() {
        if (begin == -1) {
            cout << "0" << endl;
        }
        else if (begin <= end) {
            cout << end - begin + 1 << endl;
        }
        else {
            cout << sizeof(deque) - begin + end + 1 << endl;
        }
    }
    bool empty() {
        if (begin == -1) {
            return true;
        }
        else {
            return false;
        }
    }
    void front() {
        if (begin == -1) {
            cout << "-1" << endl;
        }
        else {
            cout << deque[begin] << endl;
        }
    }
    void back() {
        if (end == -1) {
            cout << "-1" << endl;
        }
        else {
            cout << deque[end] << endl;
        }
    
    }

    ~Deque() {
        delete[] deque;
    }
};

int main() {
    int n;
    cin >> n;
    Deque D(n);
    if (n == 0) {
        cout << "출력값 없음" << endl;
        return 0;
    }
    bool flag = false;
    for (int i = 0 ; i < n ; i++) {
        string s;
        cin >> s;
        if (s == "push_front") {
            string s2;
            cin >> s2;
            D.push_front(s2);
        }
        else if (s == "push_back") {
            string s2;
            cin >> s2;
            D.push_back(s2);
        }
        else if (s == "pop_front") {
            D.pop_front();
            flag = true;
        }
        else if (s == "pop_back") {
            D.pop_back();
            flag = true;
        }
        else if (s == "size") {
            D.size();
            flag = true;
        }
        else if (s == "empty") {
            cout << D.empty() << endl;
            flag = true;
        }
        else if (s == "front") {
            D.front();
            flag = true;
        }
        else if (s == "back") {
            D.back();
            flag = true;
        }
        else if (s == "q") {
            if (flag == false) {
                cout << "출력값 없음" << endl;
            }
            break;
        }
    }



	return 0;
}