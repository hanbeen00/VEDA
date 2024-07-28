#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
	int radius = 5;
public:
	Circle(const Circle& c);
	Circle();
	Circle(int r);
	~Circle();
	double getArea();
	void setRadius(int r);
	int getRadius() {
		return radius;
	}
};

#endif
