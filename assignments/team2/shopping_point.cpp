// 작성된 코드 예시입니다.
#include <iostream>
#include <string>

using namespace std;

class shopPoint {
private:
	int consume;
	static int point;
public:
	shopPoint();
	void addConsume(int price) { consume += price; }
	static void addPoint(int point) { shopPoint::point += point; }
	int getConsume() { return consume; }
	static int getPoint() { return point; }
};

int shopPoint::point = 0;

shopPoint::shopPoint() {
    consume = 0;
}

int main() {
    shopPoint a, b, c;

    while (true) {
        string command;
        cin >> command;

        if (command == "Q") {
            break;
        }
        
        if (command == "A") {
            int price;
            cin >> price;
            cin.ignore();
            a.addConsume(price);
            if (price >= 10000) {
                shopPoint::addPoint(price * 0.1);
            }
            else {
                shopPoint::addPoint(price * 0.05);
            }
        }
        else if (command == "B") {
            int price;
            cin >> price;
            cin.ignore();
            b.addConsume(price);
            if (price >= 10000) {
                shopPoint::addPoint(price * 0.1);
            }
            else {
                shopPoint::addPoint(price * 0.05);
            }
        }
        else if (command == "C") {
            int price;
            cin >> price;
            cin.ignore();
            c.addConsume(price);
            if (price >= 10000) {
                shopPoint::addPoint(price * 0.1);
            }
            else {
                shopPoint::addPoint(price * 0.05);
            }
        }
        else if (command == "P") {
            cout << "Point : " << shopPoint::getPoint() << endl;
        }
        else if (command == "M") {
            cout << "A : " << a.getConsume() << endl;
            cout << "B : " << b.getConsume() << endl;
            cout << "C : " << c.getConsume() << endl;
        }

    }
}