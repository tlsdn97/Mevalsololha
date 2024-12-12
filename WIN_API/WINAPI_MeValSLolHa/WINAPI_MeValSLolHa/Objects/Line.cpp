#include "framework.h"
#include "Line.h"

Line::Line(Vector2D start, Vector2D end)
: _start(start)
, _end(end)
{
}

Line::~Line()
{
}

float Line::calculateShadowLength(const Line& line, const Line& floor)
{
	float shadowStartX = line._start.x + (floor._start.y - line._start.y) * (line._end.x - line._start.x) / (line._end.y - line._start.y);
	float shadowEndX = line._end.x + (floor._start.y - line._end.y) * (line._end.x - line._start.x) / (line._end.y - line._start.y);
	return shadowEndX - shadowStartX;
}

Line Line::extendLine2(const Line& line2, float shadowLength)
{
    Vector2D direction(line2._end.x - line2._start.x, line2._end.y - line2._start.y);
    float magnitude = sqrt(direction.x * direction.x + direction.y * direction.y);
    Vector2D unitDirection(direction.x / magnitude, direction.y / magnitude);

    Vector2D extendedEnd
    (
        line2._end.x + unitDirection.x * shadowLength,
        line2._end.y + unitDirection.y * shadowLength
    );
    return Line(line2._start, extendedEnd);
}

void Line::Update()
{
}

void Line::Render(HDC hdc)
{
    MoveToEx(hdc, static_cast<int>(_start.x), static_cast<int>(_start.y), nullptr);
    LineTo(hdc, static_cast<int>(_end.x), static_cast<int>(_end.y));
}
