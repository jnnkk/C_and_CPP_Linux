#include <iostream>
#include <string>
using namespace std;

class Card {
private:
    int value;
public:
    Card(int value) {}
};

class DeckofCards {
private:
    int count = 0;
public:
    DeckofCards() {}
    int getCount() { return count; }
    void addCount() { count++; }
    int cardDistribute(DeckofCards* deck, int value) {}
};

class Person {
private:
    string name;
    int age;
    int money;
    int points = 0;
    static DeckofCards Deck[14];
public:
    Person() {}
    Person(string name, int age, int money) {
        this->name = name;
        this->age = age;
        this->money = money;
    }
    void getName() { cout << name << endl; }
    void getAge() { cout << age << endl; }
    int getMoney() { return money; }
    void printMoney() { cout << money << endl; }
    void subMoney(int money) { this->money -= money; }
    void addMoney(int money) { this->money += money; }
    bool isBurst() { if (points > 21) return true; else return false; }

    void addCard(int num) {
        while (Deck[num].getCount() >= 4) {
            cout << "choose another value" << endl;
            cin >> num;
        }
        Deck[num].addCount(); points += num; if (points <= 11 && num == 1) points += 10; // 핵심
    }

    int myCardPoint() { return points; }

    int isWin(Person& dealer) {
        if (dealer.isBurst()) {
            if (isBurst()) return 1;
            else return 2;
        }
        else {
            if (isBurst()) return 0;
            else {
                if (dealer.myCardPoint() < myCardPoint()) return 2;
                else if (dealer.myCardPoint() == myCardPoint()) return 1;
                else return 0;
            }
        }
    }
};
DeckofCards Person::Deck[14];

int main()
{
    string name;
    int age, money;

    cin >> name >> age >> money;
    Person player(name, age, money);

    player.getName();
    player.getAge();
    player.printMoney();

    int bet;
    cin >> bet;

    player.subMoney(bet);
    player.printMoney();

    Person dealer;

    int card;
    for (int i = 0; i < 2; i++) {
        cin >> card;
        dealer.addCard(card);
    }
    for (int i = 0; i < 3; i++) {
        cin >> card;
        player.addCard(card);
    }


    cout << dealer.myCardPoint() << endl;
    cout << player.myCardPoint() << endl;


    player.addMoney(player.isWin(dealer) * bet);
    player.printMoney();

    return 0;
}
