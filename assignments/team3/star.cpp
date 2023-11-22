#include <iostream>
#include <string>

using namespace std;

// TODO: 함수 중복을 사용해 구현하세요
void starPrint(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < n*2 - 1; j++) {
            if (j >= i && j <= (n*2 - 2 - i)) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void starprint(int n, string c) {
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < n*2 - 1; j++) {
            if (j >= i && j <= (n*2 - 2 - i)) {
                cout << c;
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
	int M, N;
	string c;
	// TODO: main 구현
	
    cin >> M;
    if (M == 1) {
        cin >> N;
        starPrint(N);
    }
    else if (M == 2) {
        cin >> N >> c;
        starprint(N, c);
    }

	return 0;
}