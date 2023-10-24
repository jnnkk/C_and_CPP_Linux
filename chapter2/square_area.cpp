#include <iostream> // 표준 입출력 헤더

int main() {
	int width, height, area;

	using namespace std; // std 네임스페이스 사용

	cout << "Enter width: ";
	cin >> width;
	cout << "Enter height: ";
	cin >> height;
	area = width * height;
	cout << "Area = " << area << endl;
}