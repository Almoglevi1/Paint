#pragma once

#include "pch.h"
#include "MyTriangle.h"


IMPLEMENT_SERIAL(MyTriangle, MyShape, 1)

MyTriangle::MyTriangle() {}

MyTriangle::MyTriangle(const CPoint& start, const CPoint& end, COLORREF penColor, int penSize) : MyShape(start, end, penColor, penSize) 
{

}

void MyTriangle::draw(CDC* dc) const
{
	CPen pen(PS_SOLID, penSize, penColor);
	CPen* old = dc->SelectObject(&pen);
	CPoint arr[3];
	int x0 = this->start.x, y0 = this->start.y, x1 = this->end.x, y1 = this->end.y;
	arr[0].SetPoint(x0, y1);
	arr[1].SetPoint(x1, y1);
	arr[2].SetPoint((x0 + x1) / 2, y0);
	dc->Polygon(arr, 3);
	dc->SelectObject(old);
}



