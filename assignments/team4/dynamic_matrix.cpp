#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b;

    cin >> a >> b;

    // 원소 값이 b인 a*a*a 행렬
    int ***matrix = new int**[a];
    for (int i = 0; i < a; i++) {
        matrix[i] = new int*[a];
        for (int j = 0; j < a; j++) {
            matrix[i][j] = new int[a];
            for (int k = 0; k < a; k++) {
                matrix[i][j][k] = b;
            }
        }
    }

    for (int i = 0; i < a; i++) {
        cout << "[";
        for (int j = 0; j < a; j++) {
            if (j != 0) {
                cout << ", ";
            }
            cout << "[";
            for (int k = 0; k < a; k++) {
                if (k != 0) {
                    cout << ", ";
                }
                cout << matrix[i][j][k];
            }
            cout << "]";
        }
        cout << "]" << endl;
    }


    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            delete[] matrix[i][j];
        }
        delete[] matrix[i];
    }
	
	return 0;
}