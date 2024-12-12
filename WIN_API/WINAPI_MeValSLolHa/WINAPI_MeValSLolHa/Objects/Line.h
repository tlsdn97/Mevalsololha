#pragma once
struct Point
{
	float x, y;
	Point (float x, float y) : x(x), y(y) {}
};

class Line
{
public:
	Line(Vector2D start, Vector2D end);
	~Line();
	float calculateShadowLength(const Line& line, const Line& floor);
	Line extendLine2(const Line& line2, float shadowLength);

	void Update();
	void Render(HDC hdc);

public:
	Vector2D _start;
	Vector2D _end;
};

