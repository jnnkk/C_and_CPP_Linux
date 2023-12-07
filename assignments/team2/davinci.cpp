// 작성된 코드 예시입니다.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Card {
private:
	int num;
	char color;
public:
	Card(int num, char color);
	int getNum() { return num; }
	char getColor() { return color; }
};

Card::Card(int num, char color) {
    this->num = num;
    this->color = color;
}

int main() {
    int T, C;
    string input;
    vector<Card> cards;

    cin >> T >> input >> C;

    if (input.find("10") != string::npos) {
        int idx = input.find("10");
        cards.push_back(Card(10, input[idx-1]));
        input.erase(idx-1, 3);
    }
    if (input.find("11") != string::npos) {
        int idx = input.find("11");
        cards.push_back(Card(11, input[idx-1]));
        input.erase(idx-1, 3);
    }
    if (input.find("10") != string::npos) {
        int idx = input.find("10");
        cards.push_back(Card(10, input[idx-1]));
        input.erase(idx-1, 3);
    }
    if (input.find("11") != string::npos) {
        int idx = input.find("11");
        cards.push_back(Card(11, input[idx-1]));
        input.erase(idx-1, 3);
    }


    for (int i = 0 ; i < input.size() ; i+=2) {
        int color = input[i];
        int num = stoi(input.substr(i+1, 1));
        cards.push_back(Card(num, color));
    }

    sort(cards.begin(), cards.end(), [](Card a, Card b) {
        if (a.getNum() == b.getNum()) {
            return a.getColor() < b.getColor();
        }
        return a.getNum() < b.getNum();
    });

    if (C == 0) {
        for (auto card : cards) {
            cout << card.getColor() << card.getNum();
        }
    } else {
        Card present_card = cards[C-1];
        if (present_card.getColor() == 'W') {
            cout << "White " << present_card.getNum();
        }
        else {
            cout << "Black " << present_card.getNum();
        }
    }

}