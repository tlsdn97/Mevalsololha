#pragma once


class CircleCollider : public Collider, public enable_shared_from_this<CircleCollider>
{
public:
	CircleCollider(Vector2D center, float radius);

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	virtual bool IsCollision(const Vector2D& pos) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> other) override;
	virtual bool IsCollision(shared_ptr<class RectCollider> other) override;

	float Radius() { return _radius; }

private:
	float		 _radius;
};

