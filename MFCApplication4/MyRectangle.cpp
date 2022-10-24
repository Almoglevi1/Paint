#pragma once

#include "pch.h"
#include "MyRectangle.h"


IMPLEMENT_SERIAL(MyRectangle, MyShape, 1)


MyRectangle::MyRectangle() {}


MyRectangle::MyRectangle(const CPoint& start, const CPoint& end, COLORREF penColor, int penSize) : MyShape(start, end, penColor, penSize)
{

}

/*virtual */void MyRectangle::draw(CDC* dc) const
{
	CPen pen(PS_SOLID, penSize, penColor);
	CPen* old = dc->SelectObject(&pen);
	dc->Rectangle(start.x, start.y, end.x, end.y);
	dc->SelectObject(old);
}



