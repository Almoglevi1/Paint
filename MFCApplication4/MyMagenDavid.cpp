#pragma once

#include "pch.h"
#include "MyMagenDavid.h"


IMPLEMENT_SERIAL(MyMagenDavid, MyTriangle, 1)


MyMagenDavid::MyMagenDavid() {}


MyMagenDavid::MyMagenDavid(const CPoint& start, const CPoint& end, COLORREF penColor, int penSize) : MyTriangle(start, end, penColor, penSize)
{

}

void MyMagenDavid::draw(CDC* dc) const
{

	COLORREF color = RGB(0, 0, 255);

	int offsetDownUp = 50;
	CBrush myBrush, * oldBrush;
	myBrush.CreateSolidBrush(color);
	oldBrush = dc->SelectObject(&myBrush);

	CPen pen(PS_SOLID, penSize, color); // 0-255
	CPen* old = dc->SelectObject(&pen);
	CPoint arr[3];
	int x0 = this->start.x, y0 = this->start.y, x1 = this->end.x, y1 = this->end.y;
	arr[0].SetPoint(x0, y1);
	arr[1].SetPoint(x1, y1);
	arr[2].SetPoint((x0 + x1) / 2, y0 - offsetDownUp);
	dc->Polygon(arr, 3);

	CPoint arr2[3];
	arr2[0].SetPoint(x1, y0);
	arr2[1].SetPoint(x0, y0);
	arr2[2].SetPoint((x0 + x1) / 2, y1 + offsetDownUp);
	dc->Polygon(arr2, 3);
	dc->SelectObject(old);


	dc->SelectObject(oldBrush);

}