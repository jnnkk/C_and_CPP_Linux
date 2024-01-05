#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int BFS(vector<int> map[], int s, int e) {
    queue<int> BFS_q;
    unordered_set<int> visited; // 시간 줄이기 위해 set 사용
    int count = 0;

    BFS_q.push(s);
    visited.insert(s);

    while (!BFS_q.empty()) {
        int size = BFS_q.size();
        count++;

        for (int i = 0; i < size; i++) {
            int n = BFS_q.front();
            BFS_q.pop();

            for (auto j : map[n]) {
                if (visited.find(j) == visited.end()) {
                    if (j == e) {
                        return count;
                    }
                    BFS_q.push(j);
                    visited.insert(j);
                }
            }
        }
    }
    return 0;
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); // 시간 초과 방지 1
    cin.tie(NULL); // 시간 초과 방지 2
    cout.tie(NULL); // 시간 초과 방지 3

    int test_case;
    int T;
    vector<int> map[10001];
    int map_count = 1;

    for (int i = 1; i <= 200; i++) {
        for (int j = 1; j <= i; j++) {
            if (i != j && map_count + 1 <= 10000) {
                map[map_count].push_back(map_count + 1);
            }
            if (map_count + i <= 10000) {
                map[map_count].push_back(map_count + i);
            }
            if (map_count + i + 1 <= 10000) {
                map[map_count].push_back(map_count + i + 1);
            }
            map_count++;
            if (map_count > 10000) {
                break;
            }
        }
        if (map_count > 10000) {
            break;
        }
    }

    cin >> T;

    for(test_case = 1; test_case <= T; ++test_case) {
        int s, e;
        cin >> s >> e;

        if (s == e) {
            cout << "#" << test_case << " " << 0 << "\n";
            continue;
        }

        int count = BFS(map, min(s, e), max(s, e));
        cout << "#" << test_case << " " << count << "\n";
    }
    return 0;
}
