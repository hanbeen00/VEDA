#pragma once

struct StructCircle {
private:
	int radius;
public:
	StructCircle() { radius = 2; }
	StructCircle(int r) { radius = r; }
	double getArea();
};

