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

int Pyenbup(int s, int e, int* mapmap) {

    int s_pos = mapmap[s];
    int e_pos = mapmap[e];
    int diff = abs(s_pos - e_pos);

    int L_pos = 0;
    int R_pos = 0;

    if (diff == 0) {
        return abs(s - e);
    }
    else {
        L_pos = s;
        R_pos = s;
        for (int i = s_pos; i < e_pos; i++) {
            L_pos = L_pos + i;
            R_pos = R_pos + i + 1;
        }
        if (L_pos < e && R_pos > e) {
            return diff;
        }
        else if (L_pos > e) {
            return diff + (L_pos - e);
        }
        else if (R_pos < e) {
            return diff + (e - R_pos);
        }
        else {
            return diff;
        }
    }
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); // 시간 초과 방지 1
    cin.tie(NULL); // 시간 초과 방지 2
    cout.tie(NULL); // 시간 초과 방지 3

    int test_case;
    int T;
    vector<int> map[10001];
    vector<int> map_position[142];
    int mapmap[10001];
    int map_count = 1;

    for (int i = 1; i <= 200; i++) {
        for (int j = 1; j <= i; j++) {
            // if (i != j && map_count + 1 <= 10000) {
            //     map[map_count].push_back(map_count + 1);
            //     map[map_count + 1].push_back(map_count);
            // }
            // if (map_count + i <= 10000) {
            //     map[map_count].push_back(map_count + i);
            // }
            // if (map_count + i + 1 <= 10000) {
            //     map[map_count].push_back(map_count + i + 1);
            // }
            // map_position[i].push_back(map_count);
            mapmap[map_count] = i;
            map_count++;
            if (map_count > 10000) {
                break;
            }
        }
        if (map_count > 10000) {
            break;
        }
    }

    // for (int i = 1 ; i <= 141; i++) {
    //     cout << i << " : ";
    //     for (auto j : map_position[i]) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    cin >> T;

    for(test_case = 1; test_case <= T; ++test_case) {
        int s, e;
        cin >> s >> e;

        if (s == e) {
            cout << "#" << test_case << " " << 0 << endl;
            continue;
        }

        // int count = BFS(map, min(s, e), max(s, e));
        // cout << "#" << test_case << " " << count << endl;
        // if (mapmap[s] == mapmap[e]) {
        //     cout << "#" << test_case << " " << abs(s-e) << endl;
        // }
        // else {
        //     cout << "#" << test_case << " " << abs(mapmap[e] - mapmap[s]) << endl;
        // }
        if (s < e) {
            cout << "#" << test_case << " " << Pyenbup(s, e, mapmap) << endl;
        }
        else {
            cout << "#" << test_case << " " << Pyenbup(e, s, mapmap) << endl;
        }
    }
    return 0;
}