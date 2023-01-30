#include "framework.h"
#include "HPBar.h"

HPBar::HPBar()
{
	_quad = make_shared<Quad>(L"UI/Button.png");
	_quad->SetPixelShader(ADD_PS(L"HPBarPixelShader"));

	_sliderBuffer = make_shared<SliderBuffer>();
}

HPBar::~HPBar()
{
}

void HPBar::Update()
{
	_quad->Update();
}

void HPBar::Render()
{
	_sliderBuffer->SetPSBuffer(1);
	_quad->Render();
}
