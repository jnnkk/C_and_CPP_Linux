#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Book {
    string title;
    string author;
    int publicationYear;
public:
    Book(string title, string author, int publicationYear) {
        this->title = title;
        this->author = author;
        this->publicationYear = publicationYear;
    }
    string getTitle() { return title; }
    string getAuthor() { return author; }
    int getPublicationYear() { return publicationYear; }
};

class Member {
    string name;
    int memberId;
    int borrowedBooks; // 현재 대출 중인 도서의 수
    vector<Book> borrowedBookList; // 대출 중인 도서의 목록 (도서는 최대 5권 대출 가능)
public:
    Member(string name, int memberId) {
        this->name = name;
        this->memberId = memberId;
        borrowedBooks = 0;
    }
    string getName() { return name; }
    int getMemberId() { return memberId; }
    int getBorrowedBooks() { return borrowedBooks; }
    vector<Book> getBorrowedBookList() { return borrowedBookList; }
    void borrowBook(Book book) {
        if (borrowedBooks < 5) {
            borrowedBookList.push_back(book);
            borrowedBooks++;
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<Book> books;
    vector<Member> members;

    for (int i = 0 ; i < n ; i++) {
        string title, author;
        int publicationYear;
        cin >> title >> author >> publicationYear;
        books.push_back(Book(title, author, publicationYear));
    }

    int p;
    cin >> p;

    for (int i = 0 ; i < p ; i++) {
        string name;
        int memberId;
        cin >> name >> memberId;
        Member member(name, memberId);

        members.push_back(member);
    }

    if (books.size() == 0) {
        cout << "대출 가능한 도서가 없습니다." << endl;
        return 0;
    }

    int command;
    int a, b;
    cin >> command;

    if (command == 1) {
        cin >> b >> a;
        if ( a > books.size() ) {
            cout << "존재하지 않는 도서입니다." << endl;
            return 0;
        } else if ( b > members.size() ) {
            cout << "등록되지 않은 회원입니다." << endl;
            return 0;
        }
        cout << "도서 \"" <<  books[a-1].getTitle() << "\"이(가) 회원 \"" << members[b-1].getName() << "\"에게 대출되었습니다." << endl;
    } else if (command == 2) {
        cin >> b >> a;
        if ( a > books.size() ) {
            cout << "존재하지 않는 도서입니다." << endl;
            return 0;
        } else if ( b > members.size() ) {
            cout << "등록되지 않은 회원입니다." << endl;
            return 0;
        }

        cout << "도서 \"" <<  books[a-1].getTitle() << "\"이(가) 회원 \"" << members[b-1].getName() << "\"에게 반납되었습니다." << endl;
    } else {
        cin >> b >> a;
        cout << "대출 또는 반납을 선택해주세요." << endl;
    }


}