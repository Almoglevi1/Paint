#pragma once

#include "pch.h"
#include "MyRectCirc.h"


IMPLEMENT_SERIAL(MyRectCirc, MyRectangle, 1)


MyRectCirc::MyRectCirc() {}

MyRectCirc::MyRectCirc(const CPoint& start, const CPoint& end, COLORREF penColor, int penSize) : MyRectangle(start, end, penColor, penSize)
{

}

/*virtual*/ void MyRectCirc::draw(CDC* dc) const {
	MyRectangle::draw(dc);
	CPen pen(PS_SOLID, penSize, penColor);
	CPen* old = dc->SelectObject(&pen);
	dc->Ellipse(start.x, start.y, end.x, end.y);
	dc->SelectObject(old);
}

