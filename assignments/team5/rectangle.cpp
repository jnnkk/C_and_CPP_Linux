#include <iostream>
using namespace std;
class Rectangle {
private:    
    double width;
    double height;
public:
	// 생성자
    Rectangle(double w, double h) {
        width = w;
        height = h;   
    }
	// 면적 계산 함수
	double calculateArea() const {
        return width * height;
	}
	// 정보 출력 함수
	void displayInfo() const {
		cout << "Rectangle Information:" << endl;
        cout << "Width: " << width;
        cout << ", Height: " << height << endl;
	}
};

int main() {
// 사용자로부터 가로와 세로 길이 입력 받기
    double width, height;
    while(true){
        cout << "Enter the width of the rectangle: ";
        cin >> width;
        if(width>0 && width<=100) {
            break;
        }
        else {
            cout << "Enter it again" << endl;
        }
    }
    while(true){
        cout << "Enter the height of the rectangle: ";
        cin >> height;
        if(height>0 && height<=100) {
            break;
        }
        else {
            cout << "Enter it again" << endl;
        }
    }

	// 입력 받은 정보를 클래스 객체로 생성
    Rectangle rect(width, height);
	// 면적 출력
    cout << "\nArea of the rectangle: " << rect.calculateArea() << endl;
	// 정보 출력
    rect.displayInfo();
	return 0;
}