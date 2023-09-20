#include <iostream>
#include <queue> // 큐 쓰려면 헤더파일 불러와야 함

using namespace std;

struct DATA // 구조체선언
{
    long long item, count;
};

int main() {
    long long a, b;
    queue<DATA> q; // 큐 선언

    cin >> a >> b;

    DATA i = { a, 0 };
    q.push(i);

    while (!q.empty()) {
        DATA t = q.front();
        q.pop();

        if (t.item == b) {
            cout << t.count + 1 << endl;
            return 0;
        }
        else if (t.item * 2 == b){
            cout << t.count + 2 << endl;
            return 0;
        }
        else if (t.item * 10 + 1 == b){
            cout << t.count + 2 << endl;
            return 0;
        }
        else {
            if (t.item * 2 < b){
                DATA i = { t.item * 2, t.count + 1 };
                q.push(i);
            }
            if (t.item * 10 + 1 < b){
                DATA i = { t.item * 10 + 1, t.count + 1 };
                q.push(i);
            }
        }
    }

    cout << -1 << endl;
    return 0;
}