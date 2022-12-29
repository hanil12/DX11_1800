#include "framework.h"
#include "Sprite.h"

Sprite::Sprite(wstring file, Vector2 maxFrame)
: Quad(file)
{
	_actionBuffer = make_shared<ActionBuffer>();
	_actionBuffer->_data.imageSize = _srv->GetSize();
	_maxFrame = maxFrame;

	_ps = ADD_PS(L"ActionPixelShader");
}

Sprite::Sprite(wstring file, Vector2 maxFrame, Vector2 size)
: Quad(file, size)
{
	_actionBuffer = make_shared<ActionBuffer>();
	_actionBuffer->_data.imageSize = _srv->GetSize();
	_maxFrame = maxFrame;

	_ps = ADD_PS(L"ActionPixelShader");
}

void Sprite::Update()
{
	_actionBuffer->Update();
	Quad::Update();
}

void Sprite::Render()
{
	_actionBuffer->SetPSBuffer(1);
	Quad::Render();
}

void Sprite::SetSpriteByFrame(Vector2 curFrame)
{
	_actionBuffer->_data.size.x = _actionBuffer->_data.imageSize.x / _maxFrame.x;
	_actionBuffer->_data.size.y = _actionBuffer->_data.imageSize.y / _maxFrame.y;
	_actionBuffer->_data.startPos.x = _actionBuffer->_data.imageSize.x * (curFrame.x / _maxFrame.x);
	_actionBuffer->_data.startPos.y = _actionBuffer->_data.imageSize.y * (curFrame.y / _maxFrame.y);
}

void Sprite::SetSpriteAction(const Action::Clip& clip)
{
	_actionBuffer->_data.size = clip.size;
	_actionBuffer->_data.startPos = clip.startPos;
}
