#pragma once

#include "pch.h"
#include "MyPen.h"

IMPLEMENT_SERIAL(MyPen, MyLine, 1)


MyPen::MyPen()
{

}

MyPen::MyPen(CPoint p, COLORREF penColor, int penSize) : MyLine(start, end, penColor, penSize)
{
	pointArray.push_back(p);

}

void MyPen::Serialize(CArchive& archive)
{
	MyLine::Serialize(archive);
	int max = pointArray.size();

	CPoint point;

	if (archive.IsStoring()) { // SAVE      //בודק אם לשמור או לפתוח את הקובץ
		
		archive << max;
		for (int i = 0; i < max; i++)
		{
			archive << pointArray[i];
		}

	}
	else  // LOAD
	{
		archive >> max;
		for (int i = 0; i < max; i++)
		{
			archive >> point;
			pointArray.push_back(point);
		}
	}

}

void MyPen::draw(CDC* dc) const
{
	int max = pointArray.size();
	int i;

	CPen pen(PS_SOLID, penSize, penColor);
	CPen* oldPen = dc->SelectObject(&pen);
	dc->MoveTo(pointArray[0]);
	dc->SelectObject(&pen);
	for (i = 1; i < max; i++)
	{
		dc->LineTo(pointArray[i]);
	}
	dc->SelectObject(oldPen);
}



CPoint MyPen::lastPoint()
{
	return pointArray[pointArray.size() - 1];
}

void MyPen::build(CPoint currentPoint)
{
	pointArray.push_back(currentPoint);
}


