#pragma once
class Button
{
public:
	struct TextInfo
	{
		wstring text;
		RECT rect;
		float size = 20.0f;
		XMFLOAT4 color = { 1,1,1,1 };
	};

	enum State
	{
		NONE,
		HOVER,
		CLICK
	};

	Button(wstring path);
	~Button();

	void Update();
	void PostRender();

	void SetPostion(Vector2 pos);
	void SetScale(Vector2 scale);

	void SetEvent(CallBack callBack) { _callBack = callBack; }

	void SetText(TextInfo info) { _textInfo = info; }

	Vector2 LeftTop() { return _collider->LeftTop(); }
	Vector2 RightBottom() { return _collider->RightBottom(); }

private:
	State _state;

	shared_ptr<Quad> _quad;
	shared_ptr<RectCollider> _collider;
	shared_ptr<ButtonInfoBuffer> _buttonInfoBuffer;

	TextInfo _textInfo;

	CallBack _callBack;
};

