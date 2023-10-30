#include <iostream>

using namespace std;

void foo( char (&a)[100] ) {
    cout << "foo() " << sizeof(a) << endl;
}

int main() {
    char bar[100] = {0};
    cout << "main() " << sizeof(bar) << endl;
    foo(bar);
    return 0;
}

/*
    main() 100 / char a[100] : 8
    main() 100 / char* a : 8
    main() 100 / char (&a)[100] : 8
*/