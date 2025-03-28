#pragma once

class Vector2 {
public:
	int x;
	int y;

	Vector2()
		: x(0), y(0){}
	Vector2(int _x, int _y)
		: x(_x), y(_y) {}

	//Operators
	Vector2 operator+(const Vector2& other) {
		return Vector2(x + other.x, y + other.y);
	}

	bool operator==(const Vector2& other) {
		return x == other.x && y == other.y;
	}

	void operator!() {
		x = -x;
		y = -y;
	}
};