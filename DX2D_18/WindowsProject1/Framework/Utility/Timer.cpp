#include "framework.h"
#include "Timer.h"

Timer* Timer::_instance = nullptr;
Timer::Timer()
{
	// 1�ʵ��� CPU�� �������� ��ȯ�ϴ� �Լ�
	QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency);

	// ���� ������ ����
	QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime); // 0

	_timeScale = 1.0f / (double)_periodFrequency; // 10000
}

Timer::~Timer()
{
}

void Timer::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&_curTime); // 10000
	// (���ݱ��� ������ Ƚ�� - ó���� ������ Ƚ��) * ( 1 / �ʴ� ������ Ƚ��)
	// (10000 - 0) * ( 1 / 10000) -> Update �ѹ��� �ɸ� �ð� : 1�� -> Delta Time

	if (_lockFPS != 0)
	{
		while (_timeElased < (1.0f / _lockFPS))
		{
			QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			// �� �� �����Ӹ�ŭ ����� �ð�
			_timeElased = (double)(_curTime - _lastTime) * _timeScale;
		}
	}
	else
	{
		_timeElased = (double)(_curTime - _lastTime) * _timeScale;
	}

	_lastTime = _curTime;

	_frameCount++; // -> FPS
	_oneSecCount += _timeElased; // timeElased : Update�ѹ��� ����� �ð� = Delta Time

	// 1�ʸ��� �����ؾߵǴ� ����
	if (_oneSecCount >= 1)
	{
		_frameRate = _frameCount;
		// frameRate : FPS (Frame Per Second)
		_frameCount = 0;
		_oneSecCount = 0;
	}

	// �� ����� �ð�
	_runTime += _timeElased;
}
