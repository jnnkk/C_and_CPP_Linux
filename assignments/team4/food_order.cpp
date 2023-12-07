#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Food {
	string name;
    double price;
    int quantity;
public:
    Food() {
        name = "Unknown";
        price = 0.0;
        quantity = 0;
    }
    Food(string name, double price) {
        this->name = name;
        this->price = price;
        quantity = 1;
    }
    string getName() {
        return name;
    }
    double getPrice() {
        return price;
    }
    int getQuantity() {
        return quantity;
    }
    void setQuantity(int quantity) {
        this->quantity = quantity;
    }
};

class Order {
	vector<Food> foods;
public:
    Order() {
        foods = vector<Food>();
    }
    void addFood(Food food) {
        foods.push_back(food);
    }
    double calculateTotalPrice() {
        double totalPrice = 0.0;
        for (int i = 0; i < foods.size(); i++) {
            totalPrice += foods[i].getPrice() * foods[i].getQuantity();
        }
        return totalPrice;
    }
    void displayOrderInfo() {
        for (int i = 0; i < foods.size(); i++) {
            cout << foods[i].getName() << ": $" << foods[i].getPrice() << " ";
        }
        cout << endl;
    }
};

class Customer {
	string name;
    Order order;
public:
    Customer() {
        name = "Unknown";
        order = Order();
    }
    Customer(string name) {
        this->name = name;
        order = Order();
    }
    void placeOrder(Food food) {
        order.addFood(food);
    }
    void displayCustomerInfo() {
        cout << "Customer Information:" << endl;
        cout << name << ", ";
        order.displayOrderInfo();
        cout << "Total: $" << order.calculateTotalPrice() << endl;
    }
};

int main() {
	Food burger("Cheese Burger", 8.99);
	Food fries("French Fries", 3.99);
	
	Customer customer("John Doe");
	customer.placeOrder(burger);
	customer.placeOrder(fries);

	customer.displayCustomerInfo();
	
	return 0;
}