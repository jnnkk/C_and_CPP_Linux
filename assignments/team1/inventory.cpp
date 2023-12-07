#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Item {
private:
	string name;
	int grade;
	int price;
public:
	Item() {}
	Item(string name, int grade, int price);
	string get_name() { return name; }
	int get_grade() { return grade; }
	int get_price() { return price; }
};

Item::Item(string name, int grade, int price) {
	this->name = name;
	this->grade = grade;
	this->price = price;
	
}

int Item_compare(Item a, Item b) {
	if (a.get_grade() == b.get_grade()) {
		if (a.get_price() == b.get_price()) {
			if (a.get_name() == b.get_name()) {
				return -1;
			}
			else {
				return a.get_name() < b.get_name();
			}
		}
		else {
			return a.get_price() > b.get_price();
		
		}
	} else {
		return a.get_grade() > b.get_grade();
	}
}

int inventory_least_item(vector<Item> inventory) {
	int least_item_idx = 0;

	for (int i = 1 ; i < inventory.size() ; i++) {
		if (Item_compare(inventory[least_item_idx], inventory[i])) {
			least_item_idx = i;
		}
	}

	return least_item_idx;
}

int inventory_highest_item(vector<Item> inventory) {
	int highest_item_idx = 0;

	for (int i = 1 ; i < inventory.size() ; i++) {
		if (!Item_compare(inventory[highest_item_idx], inventory[i])) {
			highest_item_idx = i;
		}
	}

	return highest_item_idx;
}

void show_inventory(vector<Item> inventory) {
	cout << "[ ";
	for (int i = 0 ; i < inventory.size() ; i++) {
		if (i != 0) cout << ", ";
		cout << inventory[i].get_name();
	}
	cout << " ]" << endl;
}

int main() {
	vector<Item> inventory;
	int inv_size = 0;

	cin >> inv_size;
	cin.ignore();

	string cmd;

	while (true) {
		string item_name;
		int item_grade;
		int item_price;

		getline(cin, cmd);

		if (cmd == "독버섯") break;

		cmd.find(" ");
		item_name = cmd.substr(0, cmd.find(" "));
		cmd = cmd.substr(cmd.find(" ") + 1);
		item_grade = stoi(cmd.substr(0, cmd.find(" ")));
		cmd = cmd.substr(cmd.find(" ") + 1);
		item_price = stoi(cmd);

		if (inv_size == inventory.size()) {
			int least_item_idx = inventory_least_item(inventory);
			cout << item_grade << "등급 " << item_name << " 획득!" << endl;
			if (Item_compare(inventory[least_item_idx], Item(item_name, item_grade, item_price))) {
				cout << item_grade << "등급 " << item_name << " 폐기.." << endl;
			} else {
				cout << inventory[least_item_idx].get_grade() << "등급 " << inventory[least_item_idx].get_name() << " 폐기.." << endl;
				inventory.erase(inventory.begin() + least_item_idx);
				inventory.insert(inventory.begin() + least_item_idx, Item(item_name, item_grade, item_price));
			}
			
		}
		else {
			inventory.push_back(Item(item_name, item_grade, item_price));
			cout << item_grade << "등급 " << item_name << " 획득!" << endl;
		}
		show_inventory(inventory);
	}

	while(inventory.size() != 0) {
		int highest_item_idx = inventory_highest_item(inventory);
		cout << inventory[highest_item_idx].get_grade() << "등급 " << inventory[highest_item_idx].get_name() << " 폐기.." << endl;
		inventory.erase(inventory.begin() + highest_item_idx);
	}
	cout << "인벤토리가 사라집니다." << endl;

	return 0;
}