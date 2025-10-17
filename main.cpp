#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Point.h"
#include "Square.h"
using namespace std;

Point::Point(int px, int py) : x(px), y(py) {}
int Point::getX() const { return x; }
int Point::getY() const { return y; }
void Point::setX(int px) { x = px; }
void Point::setY(int py) { y = py; }

Square::Square(const string n, int x, int y, unsigned int s) : Point(x, y), name(n), side(s) {
    area = side * side;
}
unsigned int Square::getSide() const { return side; }
unsigned int Square::getArea() const { return area; }
string Square::getName() const { return name; }
void Square::setSide(unsigned int s) { side = s; area = s * s; }
void Square::setArea(unsigned int a) { area = a; }
void Square::setName(string n) { name = n; }

int main() {
    int n;
    cin >> n;
    vector<Square> v;
    for (int i = 0; i < n; i++) {
        string name;
        int x, y;
        unsigned int side;
        cin >> name >> x >> y >> side;
        v.emplace_back(name, x, y, side);
    }

    cout << endl;

    sort(v.begin(), v.end(), [](const Square& a, const Square& b) {
        return a.getArea() < b.getArea();
        });
    cout << "Squares in increasing order of area\n";
    for (auto& s : v) {
        cout << s.getName() << "(" << s.getX() << ", " << s.getY()
            << ") side=" << s.getSide() << ", area=" << s.getArea() << endl;
    }

    cout << endl;

    sort(v.begin(), v.end(), [](const Square& a, const Square& b) {
        return (a.getX() + a.getSide()) < (b.getX() + b.getSide());
        });
    cout << "Squares in increasing order of max x-coordinate\n";
    for (auto& s : v) {
        cout << s.getName() << "(" << s.getX() + s.getSide() << ", " << s.getY()
            << ") side=" << s.getSide() << ", area=" << s.getArea() << endl;
    }

    cout << endl;

    sort(v.begin(), v.end(), [](const Square& a, const Square& b) {
        return (a.getY() + a.getSide()) < (b.getY() + b.getSide());
        });
    cout << "Squares in increasing order of max y-coordinate\n";
    for (auto& s : v) {
        cout << s.getName() << "(" << s.getX() << ", " << s.getY() + s.getSide()
            << ") side=" << s.getSide() << ", area=" << s.getArea() << endl;
    }

    return 0;
}
