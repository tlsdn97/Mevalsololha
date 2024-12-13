#include "framework.h"
#include "LineScene.h"

LineScene::LineScene()
{
	_line1 = make_shared<Line>(Vector2D(100,100), Vector2D(100,100));
	_line2 = make_shared<Line>(Vector2D(100,500), Vector2D(800,100));
	//_floor = make_shared<Line>(Vector2D(0,600), Vector2D(2000,600));

	_circle = make_shared<CircleCollider>(Vector2D(), 5);

	

	// TODO
	// _line2�� ���̸� floor�� ��ġ�� line1�� �׸��� ���̸�ŭ 'floor�� ����'���� Ŀ���� �׷��ּ���.

	// TODO
	//_floor = make_shared<Line>(Vector2D(0, 600), Vector2D(2000, 300));
}

LineScene::~LineScene()
{
}

void LineScene::Update()
{
	Line::HitResult hitResult = _line1->IsCollision(_line2);
	if (hitResult.isCollision)
	{
		_line1->SetRed();
		_line2->SetRed();

		_circle->center = hitResult.point;
	}
	else
	{
		_line1->SetGreen();
		_line2->SetGreen();
	}

	_line1->_end = mousePos;

	// L
	// Vector2D L = _line1->_end - _line1->_start;
	// // Q
	// Vector2D Q = _floor->_end - _floor->_start;
	// float shadowLength = Q.NormalVector().DotProduct(L);
	// _line2->_end = _line2->_start + Q.NormalVector() * shadowLength;
	// 
		// ���� 
		// A Dot (B�� ��������) = > a b ������ ���

	
	// float shadow = 

	_line1->Update();
	_line2->Update();
	_circle->Update();
	//_floor->Update();
}

void LineScene::Render(HDC hdc)
{
	_line1->Render(hdc);
	_line2->Render(hdc);
	_circle->Render(hdc);
	//_floor->Render(hdc);
}
