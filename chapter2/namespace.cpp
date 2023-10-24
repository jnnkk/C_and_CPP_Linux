#include <iostream>

using namespace std;

namespace AA {
	char test='A';

	void func(char c) {
		cout << "Inside AA, Input" << c << endl;
	}
}

namespace BB {
	char test='B';

	void func(char c) {
		cout << "Inside BB, Input" << c << endl;
	}
}

int main() {
	AA::func('A');
	AA::func('B');
	BB::func('A');
	BB::func('B');
}