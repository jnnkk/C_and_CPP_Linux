#include <iostream>
#include <string>

using namespace std;

class Book {
	private:
    string title;
    string author;
	public:
    Book(string title, string author) {
        this->title = title;
        this->author = author;
    }
	string getTitle() const {
        return title;
	}
	// 저자 반환 함수
	string getAuthor() const {
        return author;
	}
	// 제목 설정 함수
	void setTitle(string title) {
        this->title = title;
	}
	// 저자 설정 함수
	void setAuthor(string author) {
        this->author = author;
	}
	// 정보 출력 함수
	void displayInfo() const {
        cout << "Book Information:" << endl;
        cout << "Title: " << title;
        cout << ", Author: " << author << endl;
	}
};

int main() {
    string title, author;
    cout << "Enter the title of the book: ";
    getline(cin, title);
    cout << "Enter the author of the book: " << endl;
    getline(cin, author);
    Book book(title, author);
    book.displayInfo();
}