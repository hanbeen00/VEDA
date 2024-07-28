#include <iostream>
#include "Circle.h"

using namespace std;

Circle::Circle(const Circle& c) {
	this->radius = c.radius;
	cout << "복사생성자 " << radius << endl;
}

Circle::Circle() {
	radius = 1;
	cout << "매개변수x 생성자 반지름 " << radius << endl;
}

Circle::Circle(int radius) {
	this->radius = radius;
	cout << "매개변수o 생성자 반지름 " << radius << endl;
}

/*Circle::Circle(int r) : Circle() { // 위임 생성자 vs 타켓생성자
	radius = r;
	cout << "반지름2 " << radius << endl;
}*/

Circle::~Circle() {
	cout << "반지름 " << radius << " 소멸자" << endl;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}
