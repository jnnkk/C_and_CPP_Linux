#include <iostream>
#include <string>

using namespace std;

string cap_small(string s)
{
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            result += s[i] - 'a' + 'A';
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            result += s[i] - 'A' + 'a';
        } else {
            result += s[i];
        }
    }
    return result;
}

string cap_small(string s, int end)
{
    end--;
    string result = "";
    for (int i = 0; i <= end; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            result += s[i] - 'a' + 'A';
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            result += s[i] - 'A' + 'a';
        } else {
            result += s[i];
        }
    }
    for (int i = end + 1; i < s.length(); i++) {
        result += s[i];
    }
    return result;
}

string cap_small(string s, int start, int end)
{
    start--;
    end--;
    if (start > end) {
        return "";
    }
    string result = "";
    for (int i = 0; i < start; i++) {
        result += s[i];
    }
    for (int i = start; i <= end; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            result += s[i] - 'a' + 'A';
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            result += s[i] - 'A' + 'a';
        } else {
            result += s[i];
        }
    }
    for (int i = end + 1; i < s.length(); i++) {
        result += s[i];
    }
    return result;
}

int main()
{
    string S;
    int x, y;

    getline(cin, S);
    cin >> x >> y;

    if (x == 0) {
        cout << cap_small(S) << endl;
    } else if (y == 0) {
        cout << cap_small(S, x) << endl;
    } else {
        if (x > y) {
            return 0;
        } else {
            cout << cap_small(S, x, y) << endl;
        }
    }


    
    return 0;
}
