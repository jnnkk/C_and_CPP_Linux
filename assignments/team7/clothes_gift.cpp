#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Clothes
{
public:
	string type;
	string color;
	int price;
	
	// 필요 시 생성자 추가 가능
	Clothes(string _type, string _color, int _price) {
        type = _type;
        color = _color;
        price = _price;
    }
    void print_clothes() {
        cout << type << "(" << color << "): " << price << " WON" << endl;
    }
};

class PresentSet
{
public:
	string name;
	int number;
	vector<Clothes> set;
	
	PresentSet(string _name, int _number) {
        name = _name;
        number = _number;
        for (int i = 0; i < number; i++) {
            string type, color;
            int price;
            cin >> type >> color >> price;
            set.push_back(Clothes(type, color, price));
        }
    }
	PresentSet(PresentSet &s) {
        name = s.name;
        number = s.number;
        for (int i = 0; i < number; i++) {
            set.push_back(s.set[i]);
        }

        string new_name;
        cin >> new_name;
        name = new_name;

        int replace_idx;
        string new_type, new_color;
        int new_price;

        cin >> replace_idx;

        cin >> new_type >> new_color >> new_price;
        set[replace_idx] = Clothes(new_type, new_color, new_price);
    }
	PresentSet(string _name, PresentSet &s1, PresentSet &s2) {
        name = _name;
        number = s1.number + s2.number;
        for (int i = 0; i < s1.number; i++) {
            set.push_back(s1.set[i]);
        }
        for (int i = 0; i < s2.number; i++) {
            set.push_back(s2.set[i]);
        }
    
    }
	void print() {
        cout << name << endl;
        for (int i = 0; i < number; i++) {
            cout << i+1 << ". ";
            set[i].print_clothes();
        }
    }
};


int main()
{
    string p1_name;
    int p1_num;
    cin >> p1_name >> p1_num;

    PresentSet p1(p1_name, p1_num);

    PresentSet p2(p1);

    string p3_name;
    cin >> p3_name;

    PresentSet p3(p3_name, p1, p2);

    p1.print();
    p2.print();
    p3.print();

	return 0;
}