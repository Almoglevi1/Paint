#pragma once

#include "pch.h"
#include "MyCircle.h"

IMPLEMENT_SERIAL(MyCircle, MyShape, 1)


	MyCircle::MyCircle() :radius(0) {}

	MyCircle::MyCircle(const CPoint& start, const CPoint& end, COLORREF penColor, int penSize) : MyShape(start, end, penColor, penSize), radius(0), center(((start.x + end.x) / 2), ((start.y + end.y) / 2)) /*: MyShape(start, end)*/ 
	{
	}

	void MyCircle::draw(CDC* dc) const
	{

		CPen pen(PS_SOLID, penSize, penColor);
		CPen* old = dc->SelectObject(&pen);
		dc->Ellipse(start.x, start.y, end.x, end.y);
		dc->SelectObject(old);
	}


