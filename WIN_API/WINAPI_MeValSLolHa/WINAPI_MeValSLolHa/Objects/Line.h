#pragma once
class Line
{
public:
	Line(Vector2D start, Vector2D end);
	~Line();

	void Update();
	void Render(HDC hdc);

public:
	Vector2D _start;
	Vector2D _end;
};

