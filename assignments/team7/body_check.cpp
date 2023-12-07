#include <iostream>
#include <cmath>

using namespace std;

class Person
{
	
// 접근지정자 수정 불가
private:
	string name;
	string sex;
	double height;
	double weight;
	double muscle;
	
	double BMI;
	double muscle_ratio;
	
	string obesity_rate;
	string body_muscle_type;

public:
	Person(string name, string sex, double height, double weight, double muscle) {
        this->name = name;
        this->sex = sex;
        this->height = height;
        this->weight = weight;
        this->muscle = muscle;
    }
	void set_obesity_rate() {
        BMI = weight / (height * height);
        if (BMI < 18.5) {
            obesity_rate = "underweight";
        } else if (BMI < 23) {
            obesity_rate = "normal weight";
        } else if (BMI < 25) {
            obesity_rate = "overweight";
        } else {
            obesity_rate = "obesity";
        }
    } // 비만도 계산
	void set_body_muscle_type() {
        muscle_ratio = (muscle / weight) * 100;
        if (sex == "man") {
            if (muscle_ratio < 30) {
                body_muscle_type = "slim body";
            } else if (muscle_ratio < 45) {
                body_muscle_type = "fit body";
            } else {
                body_muscle_type = "strong body";
            }
        } else {
            if (muscle_ratio < 20) {
                body_muscle_type = "slim body";
            } else if (muscle_ratio < 30) {
                body_muscle_type = "fit body";
            } else {
                body_muscle_type = "strong body";
            }
        }
    
    } // 근육유형 결정
	void print() {
        cout << name << " is " << obesity_rate << " and " << body_muscle_type << endl;
    } // 출력함수
    double BMI_twentyone() {
        double BMI = 21;
        double w;
        w = BMI * height * height;
        return w - weight;
    }
};


int main()
{   
    string name, sex;
    double height, weight, muscle;

    getline(cin, name);
    cin >> sex >> height >> weight >> muscle;

    Person p(name, sex, height, weight, muscle);
    p.set_obesity_rate();
    p.set_body_muscle_type();
    p.print();
    
    string double_s;
    double_s = to_string(p.BMI_twentyone());
    cout << double_s.substr(0, double_s.find(".") + 2) << endl;

	return 0;
}