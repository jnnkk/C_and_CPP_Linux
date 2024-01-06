#include <iostream>

using namespace std;

int algorithm(int s, int e, int* mapmap) { // s < e, 거리 계산 알고리즘

    int s_pos = mapmap[s]; // s의 위치
    int e_pos = mapmap[e]; // e의 위치
    int diff = abs(s_pos - e_pos); // s와 e의 위치 차이

    int L_pos = 0;
    int R_pos = 0;

    if (diff == 0) { // s와 e가 같은 위치에 있을 때
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

    int mapmap[10001]; // 1 ~ 10000까지의 위치를 저장하는 배열
    int map_count = 1; // mapmap의 인덱스

    for (int i = 1; i <= 200; i++) {
        for (int j = 1; j <= i; j++) {
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

    cin >> T;

    for(test_case = 1; test_case <= T; ++test_case) {
        int s, e;
        cin >> s >> e;

        if (s == e) {
            cout << "#" << test_case << " " << 0 << endl;
            continue;
        }

        if (s < e) {
            cout << "#" << test_case << " " << algorithm(s, e, mapmap) << endl;
        }
        else {
            cout << "#" << test_case << " " << algorithm(e, s, mapmap) << endl;
        }
    }
    return 0;
}