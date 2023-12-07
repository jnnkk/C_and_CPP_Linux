#include <iostream>
#include <string>

using namespace std;

class H {
private:
	int r = 0, i = 0, j = 0, k = 0; // r은 real number의 이니셜 (변수명을 '1'로 지을 수 없기 때문)
public:
	void setH(int _r, int _i, int _j, int _k) { r = _r; i = _i; j = _j; k = _k; }
	void printH() { cout << this->r << " + " << this->i << "i + " << this->j << "j + " << this->k << "k"; }

	// 구현할 부분
    H operator+(H& h) {
        H temp;
        temp.r = this->r + h.r;
        temp.i = this->i + h.i;
        temp.j = this->j + h.j;
        temp.k = this->k + h.k;
        return temp;
    }
    H operator*(H& h) {
        H temp;
        temp.r = this->r * h.r - this->i * h.i - this->j * h.j - this->k * h.k;
        temp.i = this->r * h.i + this->i * h.r + this->j * h.k - this->k * h.j;
        temp.j = this->r * h.j - this->i * h.k + this->j * h.r + this->k * h.i;
        temp.k = this->r * h.k + this->i * h.j - this->j * h.i + this->k * h.r;
        return temp;
    }

};

int main() {
	H H1, H2, H3, H4;
	int tempR, tempI, tempJ, tempK;

	cout << "사원수 H1을 생성합니다." << endl;
	cout << "H1 = ( ) + ( )i + ( )j + ( )k" << endl;
	cout << "정수 4개를 순서대로 입력하세요. >> ";
	cin >> tempR >> tempI >> tempJ >> tempK;
	H1.setH(tempR, tempI, tempJ, tempK);
	cout << endl << "H1 = "; H1.printH(); cout << endl << endl;

	cout << "사원수 H2를 생성합니다." << endl;
	cout << "H2 = ( ) + ( )i + ( )j + ( )k" << endl;
	cout << "정수 4개를 순서대로 입력하세요. >> ";
	cin >> tempR >> tempI >> tempJ >> tempK;
	H2.setH(tempR, tempI, tempJ, tempK);
	cout << endl << "H2 = "; H2.printH(); cout << endl << endl;

	cout << "사원수의 덧셈 연산을 실행합니다." << endl;
	H3 = H1 + H2;
	cout << "H1 + H2 = "; H3.printH(); cout << endl << endl;

	cout << "사원수의 곱셈 연산을 실행합니다." << endl;
	H4 = H1 * H2;
	cout << "H1 * H2 = "; H4.printH(); cout << endl << endl;

	return 0;
}