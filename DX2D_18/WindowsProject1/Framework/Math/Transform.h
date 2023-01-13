#pragma once

class MatrixBuffer;

class Transform
{
public:
	Transform();
	~Transform();

	void Update();
	void SetWorldBuffer(int slot = 0);
	void SetSRT();

	// �����ų�, �������� �ѹ��� ������ ���� ����... ��Ʈ���� �������� ���ִ� �Լ�
	void SetPos(Vector2 pos) { _pos = pos; SetSRT(); return; }
	void SetScale(Vector2 scale) { _scale = scale; SetSRT(); return; }
	void SetAngle (float angle) { _angle = angle; SetSRT(); return; }

	Vector2& GetScale();
	Vector2 GetWorldScale();
	// �ܼ� ������
	Vector2& GetPos() { return _pos; }
	Vector2 GetWorldPos();
	float& GetAngle();
	float GetWorldAngle();

	void SetParent(shared_ptr<Transform> parent) { _parent = parent; }
	XMMATRIX* GetMatrix() { return &_srtMatrix; }

private:
	Vector2 _scale = { 1.0f, 1.0f };
	float _angle = 0.0f;
	Vector2 _pos = { 0.0f, 0.0f };

	XMMATRIX _srtMatrix = XMMatrixIdentity();
	shared_ptr<MatrixBuffer> _worldBuffer;

	shared_ptr<Transform> _parent = nullptr;
};
