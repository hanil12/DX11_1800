#pragma once
class Ball;

class Block
{
public:
	Block();
	~Block();

	void Update();
	void Render(HDC hdc);
	void SetPos(const Vector2& pos) { _rectCol->SetCenter(pos); }
	const Vector2& GetBlockSize() { return _rectCol->GetSize(); }

	// 볼과 충돌함수

	bool _isActive = false;
private:
	shared_ptr<RectCollider> _rectCol;
};

