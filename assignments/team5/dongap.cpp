#include <iostream>
#include <string>

using namespace std;

// 구현할 부분
class last_class {
private:
	
public:
    int grade = 5;
	int grade_optim() {
		if (this->grade < 0) { this->grade = 0; cout << endl << "둘리가 최저 성적에 도달했습니다." << endl; return 0; }
		if (this->grade > 100) { this->grade = 100; cout << "둘리가 최고 성적에 도달했습니다." << endl << endl; return 100; }
		return -1;
	}
	int take_exam() { return this->grade; }
	void playing() {
		cout << endl << "둘리가 놀면서 시간을 보냅니다. 성적이 1점 떨어졌습니다." << endl;
		this->grade--;
		grade_optim();
		cout << endl;
	}
	void study() {
		cout << endl << "둘리가 책상 앞에 앉았습니다.";
		playing();
	}
	// 구현할 부분
};


class first_class {
private:
	int grade = 94;
public:
	int grade_optim() {
		if (this->grade > 100) { this->grade = 100; cout << endl << "도우너가 최고 성적에 도달했습니다." << endl; return 100; }
		return -1;
	}
	int take_exam() { return this->grade; }
	void study() {
		cout << endl << "도우너가 성실히 공부하여 성적이 3점 올랐습니다." << endl;
		this->grade += 3;
		grade_optim();
		cout << endl;
	}
	// 구현할 부분
    void make_study(last_class& duly) {
        cout << endl << "도우너가 둘리를 공부시켜 둘리의 성적이 10점 올랐습니다." << endl;
        duly.grade += 10;
        cout << endl;
    }
};


// 구현할 부분

int main() {
	first_class donut;
	last_class duly;
	int menu = 0;

	cout << "동갑내기 과외하기를 시작합니다." << endl;
	cout << "도우너의 성적: " << donut.take_exam() << endl;
	cout << "둘리의 성적: " << duly.take_exam() << endl << endl;

	while (menu != 6)
	{
		cout << "=============================" << endl;
		cout << "1. 도우너 - 공부하기" << endl;
		cout << "2. 둘  리 - 놀기" << endl;
		cout << "3. 둘  리 - 공부하기" << endl;
		cout << "4. 도우너 - 둘리 공부시키기" << endl;
		cout << "5. 시험보기" << endl;
		cout << "6. 프로그램 종료" << endl;
		cout << "=============================" << endl;
		cout << "선택지를 고르세요. >> ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			donut.study();
			break;
		case 2:
			duly.playing();
			break;
		case 3:
			duly.study();
			break;
		case 4:
			donut.make_study(duly);
			break;
		case 5:
			cout << endl << "도우너의 성적: " << donut.take_exam() << endl;
			cout << "둘리의 성적: " << duly.take_exam() << endl << endl;
			break;
		case 6:
			cout << "동갑내기 과외하기 프로그램을 종료합니다.";
			break;
		default:
			cout << endl << "잘못된 입력입니다. 다시 입력해 주세요." << endl << endl;
			break;
		}
	}
	return 0;
}