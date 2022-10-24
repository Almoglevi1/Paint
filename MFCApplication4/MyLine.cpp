#pragma once

#include "pch.h"
#include "MyLine.h"


IMPLEMENT_SERIAL(MyLine, MyShape, 1)


MyLine::MyLine() {}

MyLine::MyLine(const CPoint& start, const CPoint& end, COLORREF penColor, int penSize) : MyShape(start, end, penColor, penSize)
{
}


MyLine::MyLine(COLORREF penColor, int penSize)
{

}

/*virtual*/ void MyLine::draw(CDC* dc) const
{


	CPen pen(PS_SOLID, penSize, penColor);
	CPen* old = dc->SelectObject(&pen);
	dc->MoveTo(start);
	dc->LineTo(end.x, end.y);
	dc->MoveTo(start);
	dc->LineTo(end.x, end.y);
	dc->SelectObject(old);

}


bool MyLine::isSelected(CPoint& point) const
{
	return false;
}
