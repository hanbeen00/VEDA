#include <iostream>
#include <cstring>
#include <string>

#include "Circle.h"
#include "StructCircle.h"

using namespace std;

void Circle::setRadius(int r) {
	radius = r;
}

void increase(Circle c) {
	int r = c.getRadius();
	c.setRadius(r+1);
}

void increase2(Circle* c) {
	int r = c->getRadius();
	c->setRadius(r + 2);
}

Circle getCircle() {
	Circle tmp(100);
	return tmp;
}


char& find(char s[], int index) {
	return s[index];
}

int main() {
	///////////////////////////////////////////////////////////////
	// 공백 포함 문자열 입력 받기
	/*char address[100];
	cin.getline(address, 100, '\n');
	cout << address << endl;

	if (strcmp(address, "abcd")==0) {
		cout << "ok\n";
	}

	string address2;
	getline(cin, address2);
	cout << address2 << endl;
	if (address2 == "abcd") {
		cout << "ok\n";
	}
	cout << address2[1] << endl;*/
	///////////////////////////////////////////////////////////////


	///////////////////////////////////////////////////////////////
	// 객체 vs 배열
	Circle donut;
	double area = donut.getArea();
	cout << area << endl;

	Circle pizza(10);
	cout << pizza.getArea() << endl;

	donut = pizza;

	StructCircle waffle;
	cout << waffle.getArea() << endl;

	StructCircle pie(20);
	cout << pie.getArea() << endl;
	///////////////////////////////////////////////////////////////


	///////////////////////////////////////////////////////////////
	// 객체 포인터 + 객체 배열
	Circle* p;
	p = &donut;
	cout << "객체 포인터 " << p->getArea() << " " << (*p).getArea() << endl;

	Circle circleArray[3] = { Circle(), Circle(), Circle(30) };
	circleArray[0].setRadius(10);
	circleArray[1].setRadius(20);
	circleArray[2].setRadius(30);

	p = circleArray;

	cout << "객체 배열 포인터 " << p->getArea() << " " << circleArray[1].getArea() << " " << (p + 2)->getArea() << endl;
	///////////////////////////////////////////////////////////////
	

	///////////////////////////////////////////////////////////////
	// 객체 동적 할당
	int* q;
	q = new int[3] {0, 1, 2};
	if (!q) {
		cout << "메모리 할당 불가";
		return 0;
	}

	*q = 5;
	cout << "동적할당 " << *(q+1) << endl;
	delete []q;

	Circle* a, * b;
	Circle* c = new Circle[3]{ Circle(), Circle(2), Circle(3) };
	a = new Circle();
	b = new Circle(50);
	cout << "객체 동적할당 " << a->getArea() << " " << b->getArea() << endl;
	cout << "객체 배열 동적할당 " << c[0].getArea() << " " << (*(p+1)).getArea() << " " << (p+2)->getArea() << " " << endl;

	delete b;
	delete a;
	delete []c;
	///////////////////////////////////////////////////////////////


	///////////////////////////////////////////////////////////////
	// string 객체
	/*string* s = new string("c++");
	string cpys;
	(* s)[1] = '-';
	cpys = *s;
	s->append(" great");
	cout << *s << " " << cpys << endl;
	delete s;

	string t;
	getline(cin, t, '.');
	cin.ignore();
	cout << t << endl;*/
	///////////////////////////////////////////////////////////////


	///////////////////////////////////////////////////////////////
	// 값에 의한 호출 vs 주소에 의한 호출
	Circle ball(40);
	increase(ball);
	ball = getCircle(); // ball = getCircle() 대입 연산 후 getCircle 함수의 임시 객체의 소멸 (임시 객체의 소멸, 2번).
	//기존 ball 객체 자원 해제: ball = getCircle() 대입 연산에서 기존 ball 객체의 자원이 해제됩니다.
	ball.setRadius(42);
	increase2(&ball);
	///////////////////////////////////////////////////////////////


	///////////////////////////////////////////////////////////////
	// 참조변수
	int n = 1;
	int& refn = n;
	//참조변수에 대한 참조변수도 가능(참조변수는 따로 변수공간 가지지 않음)
	refn++;
	int* o= &n;
	if (o == &refn) {
		refn++;
		cout << refn << endl;
	}
	///////////////////////////////////////////////////////////////


	///////////////////////////////////////////////////////////////
	// 참조 리턴 
	char name[] = "Mike";
	find(name, 0) = 'S';
	char& ref = find(name, 2);
	ref = 't';
	cout << name << endl;
	///////////////////////////////////////////////////////////////
	

	///////////////////////////////////////////////////////////////
	// 깊은 복사 생성자
	Circle src(200);
	Circle dest(src);
	cout << dest.getRadius() << endl;
	///////////////////////////////////////////////////////////////


	return 0;
}
