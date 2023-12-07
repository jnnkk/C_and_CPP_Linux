#include <iostream>
#include <string>

using namespace std;

class Sphere {
private:
    int radius;
public:
    Sphere() {
        radius = 0;
    } 
    Sphere(int r) {
        radius = r;
    }
    double getSurfaceArea() {
        return 4 * 3.14 * radius * radius;
    }; // 겉넓이 반환 함수
};

int main() {
    int N;
    cin >> N;
    Sphere* spheres = new Sphere[N];

    for (int i = 0; i < N; i++) {
        int r;
        cin >> r;
        spheres[i] = Sphere(r);
    }

    for (int i = 0; i < N; i++) {
        // 무조건 소숫점 2자리 까지
        cout << fixed;
        cout.precision(2);
        cout << spheres[i].getSurfaceArea() << endl;
    }

    delete[] spheres;

	return 0;
}