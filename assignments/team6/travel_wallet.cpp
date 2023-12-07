#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class FundCalculator {
public:
    static long long totalFund;  // 전체 공금액을 저장하는 static 변수
    int fund;                    // 개인의 공금액을 저장하는 변수
    int origin_money;
    FundCalculator(int origin_money) {
        this->origin_money = origin_money;
        fund = 0;
    }
    int fundcal(int order, int N) {      // 개인의 공금액을 계산하는 함수
        if (order == 0) {
            fund = origin_money * 0.2;
            totalFund += this->fund;
        }
        else {
            fund = origin_money * 0.2 * (N - order)/N;
            totalFund += this->fund;
        }
        return fund;
    }
};

long long FundCalculator::totalFund = 0;

int main() {
    int N;
    cin >> N;
    vector<FundCalculator> fund_calculators;
    for (int i = 0; i < N; i++) {
        int origin_money;
        cin >> origin_money;
        fund_calculators.push_back(FundCalculator(origin_money));
    }
    sort(fund_calculators.begin(), fund_calculators.end(), [](FundCalculator a, FundCalculator b) {
        return a.origin_money > b.origin_money;
    });

    for (int i = 0; i < N; i++) {
        fund_calculators[i].fundcal(i, N);
    }

    cout << FundCalculator::totalFund << endl;

    for (auto fund_calculator : fund_calculators) {
        cout << fund_calculator.fund << endl;
    }


	return 0;
}