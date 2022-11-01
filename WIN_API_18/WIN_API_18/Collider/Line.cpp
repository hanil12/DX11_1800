#include "framework.h"
#include "Line.h"

Line::Line()
{
    _pens[0] = CreatePen(0, 3, RED);
    _pens[1] = CreatePen(0, 3, GREEN);
    _curPen = _pens[1];
}

Line::Line(Vector2 start, Vector2 end)
: _startPos(start)
, _endPos(end)
{
    _pens[0] = CreatePen(0, 3, RED);
    _pens[1] = CreatePen(0, 3, GREEN);
    _curPen = _pens[1];
}

Line::~Line()
{
}

void Line::Update()
{
}

void Line::Render(HDC hdc)
{
    SelectObject(hdc, _curPen);
    MoveToEx(hdc, _startPos._x, _startPos._y, nullptr);
    LineTo(hdc, _endPos._x, _endPos._y);
}

Line::Result Line::IsCollision(shared_ptr<Line> other)
{
    Result myResult;

    Vector2 line1Vec = _endPos - _startPos;
    Vector2 line1ToEnd = other->_endPos - _startPos;
    Vector2 line1ToStart = other->_startPos - _startPos;

    bool between1 = line1Vec.IsBetween(line1ToEnd, line1ToStart);

    Vector2 line2Vec = other->_endPos - other->_startPos;
    Vector2 line2ToEnd = _endPos - other->_startPos;
    Vector2 line2ToStart = _startPos - other->_startPos;

    bool between2 = line2Vec.IsBetween(line2ToEnd, line2ToStart);

    if (between1 == true && between2 == true)
    {
        myResult.collision = true;

        // ���� �ﰢ���� ����
        float leftTriangle = abs(line2Vec.Cross(line2ToStart));
        float rightTriangle = abs(line2Vec.Cross(line2ToEnd));

        float t = (leftTriangle) / (rightTriangle + leftTriangle);
        Vector2 conflict = LERP(_startPos, _endPos, t);
        myResult.conflict = conflict;
    }
    else
    {
        myResult.collision = false;
    }

    return myResult;
}
