/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>

using namespace std;

void galaxyUpdate(int n, int(*agent_matrix)[3], int (*agent_most)[3], int galaxy_index, bool* galaxy, int* gal_num) {
    int min_index[2] = { 0 , 0 };
    int min_difference = 1000000;

    if (galaxy_index == 0 && galaxy[0] == false) {
        if (gal_num[1] > 1) {
            for (int i = 0; i < n; i++) {
                if (agent_most[i][1] != 0) {
                    int temp = agent_most[i][1] - agent_matrix[i][0];
                    if (temp < min_difference) {
                        min_difference = temp;
                        min_index[0] = 1;
                        min_index[1] = i;
                    }
                }
            }
        }
        if (gal_num[2] > 1) {
            for (int i = 0; i < n; i++) {
                if (agent_most[i][2] != 0) {
                    int temp = agent_most[i][2] - agent_matrix[i][0];
                    if (temp < min_difference) {
                        min_difference = temp;
                        min_index[0] = 2;
                        min_index[1] = i;
                    }
                }
            }
        }
        agent_most[min_index[1]][min_index[0]] = 0;
        agent_most[min_index[1]][0] = agent_matrix[min_index[1]][0];

        gal_num[0]++;
        gal_num[min_index[0]]--;
        galaxy[0] = true;
    }
    else if (galaxy_index == 1 && galaxy[1] == false) {
        if (gal_num[0] > 1) {
            for (int i = 0; i < n; i++) {
                if (agent_most[i][0] != 0) {
                    int temp = agent_most[i][0] - agent_matrix[i][1];
                    if (temp < min_difference) {
                        min_difference = temp;
                        min_index[0] = 0;
                        min_index[1] = i;
                    }
                }
            }
        }
        if (gal_num[2] > 1) {
            for (int i = 0; i < n; i++) {
                if (agent_most[i][2] != 0) {
                    int temp = agent_most[i][2] - agent_matrix[i][1];
                    if (temp < min_difference) {
                        min_difference = temp;
                        min_index[0] = 2;
                        min_index[1] = i;
                    }
                }
            }
        }
        agent_most[min_index[1]][min_index[0]] = 0;
        agent_most[min_index[1]][1] = agent_matrix[min_index[1]][1];

        gal_num[1]++;
        gal_num[min_index[0]]--;
        galaxy[1] = true;
    }
    else if (galaxy_index == 2 && galaxy[2] == false) {
        if (gal_num[0] > 1) {
            for (int i = 0; i < n; i++) {
                if (agent_most[i][0] != 0) {
                    int temp = agent_most[i][0] - agent_matrix[i][2];
                    if (temp < min_difference) {
                        min_difference = temp;
                        min_index[0] = 0;
                        min_index[1] = i;
                    }
                }
            }
        }
        if (gal_num[1] > 1) {
            for (int i = 0; i < n; i++) {
                if (agent_most[i][1] != 0) {
                    int temp = agent_most[i][1] - agent_matrix[i][2];
                    if (temp < min_difference) {
                        min_difference = temp;
                        min_index[0] = 1;
                        min_index[1] = i;
                    }
                }
            }
        }
        agent_most[min_index[1]][min_index[0]] = 0;
        agent_most[min_index[1]][2] = agent_matrix[min_index[1]][2];

        gal_num[2]++;
        gal_num[min_index[0]]--;
        galaxy[2] = true;
    }
}

int allCount(int(*agent_most)[3], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        count += agent_most[i][0] + agent_most[i][1] + agent_most[i][2];
    }

    return count;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); // 시간 초과 방지 1
    cin.tie(NULL); // 시간 초과 방지 2
    cout.tie(NULL); // 시간 초과 방지 3

	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        bool galaxy[3] = { false, false, false };
        int gal_num[3] = { 0, 0, 0 };
        int max_count = 0;
        
        cin >> n;

        int agent_matix[n][3] = { 0, };
        int agent_most[n][3] = { 0, };

        for (int i = 0; i < n; i++) {
            int a, b, c;
            int max_num = 0; 
            
            cin >> a >> b >> c;
            max_count += a + b + c;

            agent_matix[i][0] = a;
            agent_matix[i][1] = b;
            agent_matix[i][2] = c;
            
            max_num = max(a, max(b, c));
            if (max_num == a) {
                agent_most[i][0] = a;
                galaxy[0] = true;
                gal_num[0]++;
            }
            else if (max_num == b) {
                agent_most[i][1] = b;
                galaxy[1] = true;
                gal_num[1]++;
            }
            else if (max_num == c) {
                agent_most[i][2] = c;
                galaxy[2] = true;
                gal_num[2]++;
            }
        }

        if (n < 3) {
            cout << "#" << test_case << " -1" << endl;
            continue;
        }

        galaxyUpdate(n, agent_matix, agent_most, 0, galaxy, gal_num);
        galaxyUpdate(n, agent_matix, agent_most, 1, galaxy, gal_num);
        galaxyUpdate(n, agent_matix, agent_most, 2, galaxy, gal_num);

        cout << "galaxy :";
        cout << galaxy[0] << galaxy[1] << galaxy[2] << endl;
        cout << "agent_matix :" << endl;
        for (auto i : agent_matix) {
            cout << i[0] << i[1] << i[2] << endl;
        }
        cout << "agent_most :" << endl;
        for (auto i : agent_most) {
            cout << i[0] << i[1] << i[2] << endl;
        }
        cout << "gal_num :" << endl;
        cout << gal_num[0] << gal_num[1] << gal_num[2] << endl;
        cout << "result :" << endl;

        max_count -= allCount(agent_most, n);
        cout << "#" << test_case << " " << max_count << endl;
	}
	return 0;
}