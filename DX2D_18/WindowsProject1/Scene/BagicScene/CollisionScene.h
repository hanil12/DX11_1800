#pragma once
class CollisionScene : public Scene
{
public:
	CollisionScene();
	virtual ~CollisionScene();

	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<Collider> _rect;
	shared_ptr<Collider> _circle;
	shared_ptr<CircleCollider> _circle1;
	shared_ptr<CircleCollider> _circle2;
};

