#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Fighter {
private:
	string name; // 이름
	int* gameRecord = new int[2]; // 전적. gameRecord[0]이 승, gameRecord[1]이 패
	int performance; // 경기력
public:
    Fighter(string name, int win, int lose, int performance) {
        this->name = name;
        this->gameRecord[0] = win;
        this->gameRecord[1] = lose;
        this->performance = performance;
    }
    Fighter(const Fighter &f) {
        int* newGameRecord = new int[2];
        this->name = f.name;
        this->performance = f.performance;
        newGameRecord[0] = f.gameRecord[0];
        newGameRecord[1] = f.gameRecord[1];
        this->gameRecord = newGameRecord;
    }
    int getPerformance() const {
        return performance;
    }
    int getTotalGame() const {
        return gameRecord[0] + gameRecord[1];
    }
    void upWin() {
        gameRecord[0]++;
    }
    void upLose() {
        gameRecord[1]++;
    }
    void upPerformance(int performance) {
        this->performance += performance;
    }
    int getwin() const {
        return gameRecord[0];
    }
    int getlose() const {
        return gameRecord[1];
    }

};

// Fighter 객체 두 개를 받아 경기 결과를 예측하는 함수. 실제 객체 정보가 바뀌지 않는다.
// bool 형 반환값으로 승자를 구분한다.
bool expect(Fighter challenger, Fighter f) {
    if (challenger.getPerformance() > f.getPerformance()) {
        return true;
    }
    else if (challenger.getPerformance() < f.getPerformance()) {
        return false;
    }
    else {
        if (challenger.getTotalGame() >= f.getTotalGame()) {
            return true;
        }
        else {
            return false;
        }
    }
}

// Fighter 객체 두 개를 받아 경기를 치루는 함수. 실제 객체 정보가 바뀐다.
// bool 형 반환값으로 승자를 구분한다.
bool challenge(Fighter &challenger, Fighter &f) {
    if (expect(challenger, f)) {
        challenger.upWin();
        challenger.upPerformance(f.getPerformance());
        return true;
    }
    else {
        challenger.upLose();
        return false;
    }
}

bool compare(const Fighter &a, const Fighter &b) {
    return a.getPerformance() < b.getPerformance();
}

int main() {
    int N;
    cin >> N;
    Fighter challenger("Challenger", 0, 0, 5);
    vector<Fighter> fighters;

    for (int i = 0; i < N+1; i++) {
        string name;
        int win, lose, performance;
        cin >> name >> win >> lose >> performance;
        Fighter* fighter = new Fighter(name, win, lose, performance);
        fighters.push_back(*fighter);
    }

    sort(fighters.begin(), fighters.end(), compare);
    
    // 최소한으로 가보기
    Fighter temp2(challenger);

    for (int i = 0; i < N+1; i++) {
        if (i == N) {
            if (expect(temp2, fighters[i])) {
                cout << temp2.getwin() << "승 무패로 타이틀전 성사" << endl;
                challenge(temp2, fighters[i]);
                cout << temp2.getwin() << "승 무패로 챔피언 등극!" << endl;
                return 0;
            }
            else {
                challenge(temp2, fighters[i-1]);
                if (expect(temp2, fighters[i])) {
                    cout << temp2.getwin() << "승 무패로 타이틀전 성사" << endl;
                    challenge(temp2, fighters[i]);
                    cout << temp2.getwin() << "승 무패로 챔피언 등극!" << endl;
                    return 0;
                }
                else {
                    break;
                }
            }
        }

        if (expect(temp2, fighters[i])) {
            continue;
        }
        else {
            if (i == 0) {
                break;
            }
            else {
                challenge(temp2, fighters[i-1]);
                if (expect(temp2, fighters[i])) {
                    continue;
                }
                else {
                    break;
                }
            }
        }
    }

    // 이길수 있는지 확인
    Fighter temp(challenger);

    bool iswin = true;
    for (int i = 0; i < N; i++) {
        if (challenge(temp, fighters[i])) {
            continue;
        }
        else {
            iswin = false;
        }
    }

    if (!iswin) {
        cout << "타이틀전 성사 실패" << endl;
        return 0;
    }
    else {
        cout << temp.getwin() << "승 "<< "무패로 타이틀전 성사" << endl;
        if (challenge(temp, fighters[N])) {
            cout << temp.getwin() << "승 무패로 챔피언 등극!" << endl;
        }
        else {
            cout << temp.getwin() << "승 " << temp.getlose() << "패로 챔피언 도전 실패" << endl;
        }
    }
    
	return 0;
}